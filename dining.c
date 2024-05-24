#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
int semid, shmid;
char *buf;
void dinphil(int);
void feelhungry(int);
int main() {
  int i, pid;
  semid = semget((key_t)0x153, 1, IPC_CREAT | 0600);
  shmid = shmget((key_t)0x133, 100, IPC_CREAT | 0600);
  buf = (char *)shmat(shmid, NULL, 0);
  semctl(semid, 0, SETVAL, 2); // at a  time 2 processes can eat
  for (i = 0; i < 5; ++i)
    buf[i] = 0; // all the forks are  empty
  pid = fork();
  if (pid == 0) {
    pid = fork();
    if (pid == 0) {
      pid = fork();
      if (pid == 0) {
        pid = fork();
        if (pid == 0)
          dinphil(3);
        else
          dinphil(2);
      } else
        dinphil(1);
    } else
      dinphil(0);
  }
  semctl(semid, 0, IPC_RMID);
  shmctl(shmid, IPC_RMID, 0);
  printf("\n");
}
void dinphil(int n) {
  int i;
  printf("\nPhilosopher %d entered\n", n);
  for (i = 0; i < 2; ++i) {
    printf("\nPhilosopher %d is thinking....", n);
    sleep(1);
    feelhungry(n);
  }
  printf("\nPhilosopher %d is died...", n);
}
void feelhungry(int n) {
  struct sembuf sop;
  printf("\nPhilosopher %d is feeling hungry..\n", n);
  sop.sem_num = 0; // first semaphore
  sop.sem_op = -1; // request for resouce
  sop.sem_flg = 0; // non blocking
  semop(semid, &sop, 1);
  if (buf[n] == 0 && buf[(n + 1) % 5] == 0) {
    buf[n] = 1;     // using left fork
    buf[n + 1] = 1; // using right fork
    printf("\nPhilosopher %d is eating...", n);
    sleep(3);
    printf("\nPhilosopher %d is finished eating..", n);
    buf[n] = 0;           // free
    buf[(n + 1) % 5] = 0; // free
  }
  sop.sem_num = 0;
  sop.sem_op = 1; // release the resource
  // sop.sem_flg=0;
  // //
  semop(semid, &sop, 1);
}

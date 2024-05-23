#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>
#define NUM_LOOPS 5


int main(int argc, char *argv[]) {
  int sem_set_id;
  int child_pid;
  int i;
  struct sembuf sem_op;
  int rc;
  sem_set_id = semget(IPC_PRIVATE, 1, 0600);
  if (sem_set_id == -1) {
    perror("main: semget");
    exit(1);
  }
  printf("semaphore set created,semaphore set id '%d'.\n", sem_set_id);
  rc = semctl(sem_set_id, 0, SETVAL, 0);
  child_pid = fork();
  switch (child_pid) {
  case -1:
    perror("fork");
    exit(1);
  case 0:
    for (i = 0; i < NUM_LOOPS; i++) {
      sem_op.sem_num = 0;
      sem_op.sem_op = -1;
      sem_op.sem_flg = 0;
      semop(sem_set_id, &sem_op, 1);
      printf("consumer: '%d'\n", i);
      fflush(stdout);
      sleep(2);
    }
    printf("consumer ends\n");
    break;
  default:
    for (i = 0; i < NUM_LOOPS; i++) {
      printf("producer: '%d'\n", i);
      fflush(stdout);
      sem_op.sem_num = 0;
      sem_op.sem_op = 1;
      sem_op.sem_flg = 0;
      semop(sem_set_id, &sem_op, 1);
      sleep(2);
    }
    printf("producer ends\n");
    break;
  }
  return 0;
}

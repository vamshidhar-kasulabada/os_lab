#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
struct {
  long mtype;
  char mtext[512];
} send, recv;
int main() {
  int msqid, pid, i, n, n1;
  printf("how many message u t enter:");
  scanf("%d", &n1);
  msqid = msgget((key_t)123456, IPC_CREAT | 0700);
  if (msqid < 0) {
    printf("msgget error: ");
    exit(1);
  }
  pid = fork();
  if (pid == 0) {
    for (i = 1; i <= n1; ++i) {
      printf("\nEnter a message:");
      fflush(stdin);
      scanf("%s", send.mtext);
      send.mtype = 1;
      msgsnd(msqid, &send, strlen(send.mtext), 0);
      n = msgrcv(msqid, &recv, 512, 2, 0);
      recv.mtext[n] = '\0';
      printf("Message echoed: %s\n", recv.mtext);
    }
    msgctl(msqid, IPC_RMID, 0);
  } else {
    for (i = 1; i <= n1; ++i) {
      n = msgrcv(msqid, &recv, 512, 1, 0);
      send.mtype = 2;
      strcpy(send.mtext, recv.mtext);
      msgsnd(msqid, &send, n, 0);
    }
  }
}

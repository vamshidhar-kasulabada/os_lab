#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
  int childid, fd[2], uid;
  char string[40];
  char buffer[40];
  pipe(fd);
  if ((childid = fork()) < 0) {
    printf("Error\n");
    exit(0);
  }
  if (childid == 0) {
    close(fd[0]);
    printf("Enter string: \n");
    gets(string);
    printf("Child process sends the string %s\n", string);
    write(fd[1], string, strlen(string) + 1);
  } else {
    close(fd[1]);
    printf("Parent Process\n");
    uid = read(fd[0], buffer, sizeof(buffer));
    printf("Parent process receives the string %s\n", buffer);
  }
}

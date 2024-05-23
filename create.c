#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
  char buf1[100], buf2[100];
  int dest_file = open("v.txt", O_WRONLY | O_CREAT, 0600);
  printf("enter a string:");
  fflush(stdin);
  scanf("%s", buf1);
  int input_length = strlen(buf1);
  int written_bites = write(dest_file, buf1, input_length);
  printf("no of bytes written to file: %d\n", written_bites);
  close(dest_file);
  int source_file = open("v.txt", O_RDONLY);
  int readed_bites = read(source_file, buf2, input_length);
  printf("no of bytes read:%d\n", readed_bites);
  printf("readed string :%s\n", buf2);
  close(source_file);
}

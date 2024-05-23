#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid number of arguments");
  }
  int source_file = open(argv[1], O_RDONLY);
  if (source_file < 0) {
      perror("Source File Not Found");
  }
  int dest_file = open(argv[2], O_WRONLY | O_CREAT, 0777);
  char ch;
  while (read(source_file, &ch, 1) == 1) {
    write(dest_file, &ch, 1);
  }
  close(source_file);
  close(dest_file);
}

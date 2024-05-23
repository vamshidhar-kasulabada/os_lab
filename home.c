#include <stdio.h>
#include <stdlib.h>

int main() {
  char *home = getenv("HOME");
  if (home == NULL) {
    printf("HOME is not defined");
  } else {
    printf("HOME is :%s", home);
  }
}

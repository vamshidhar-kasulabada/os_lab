#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t mutex, writeblock;
int data = 0, rcount = 0;

void *reader(void *arg) {
  int f = (int)(long)arg;  // Correctly cast the argument
  sem_wait(&mutex);
  rcount++;
  if (rcount == 1)
    sem_wait(&writeblock);
  sem_post(&mutex);
  
  printf("\nData read by the reader %d is %d\n", f, data);
  sleep(1);
  
  sem_wait(&mutex);
  rcount--;
  if (rcount == 0)
    sem_post(&writeblock);
  sem_post(&mutex);
  
  return NULL;  // Return NULL at the end
}

void *writer(void *arg) {
  int f = (int)(long)arg;  // Correctly cast the argument
  sem_wait(&writeblock);
  data++;
  printf("\nData written by writer %d is %d\n", f, data);
  sleep(1);
  sem_post(&writeblock);
  
  return NULL;  // Return NULL at the end
}

int main() {
  int i;
  pthread_t rtid[5], wtid[5];
  
  sem_init(&mutex, 0, 1);
  sem_init(&writeblock, 0, 1);
  
  for (i = 0; i < 4; i++) {  // Loop condition corrected
    pthread_create(&wtid[i], NULL, writer, (void *)(long)i);  // Cast the integer to a void pointer
    pthread_create(&rtid[i], NULL, reader, (void *)(long)i);  // Cast the integer to a void pointer
  }
  
  for (i = 0; i < 4; i++) {  // Loop condition corrected
    pthread_join(wtid[i], NULL);
    pthread_join(rtid[i], NULL);
  }
  
  sem_destroy(&mutex);       // Clean up semaphores
  sem_destroy(&writeblock);
  
  return 0;  // Return 0 at the end of main
}


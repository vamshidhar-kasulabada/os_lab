#include <pthread.h> // Include for pthreads
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFERSIZE 10

int buffer[BUFFERSIZE]; // Buffer with a fixed size
int in = 0, out = 0;    // Indexes for producer and consumer
int item;               // Item to be produced/consumed

pthread_mutex_t mutex; // Mutex for critical section protection
pthread_cond_t empty;  // Condition variable to signal empty slots
pthread_cond_t full;   // Condition variable to signal filled slots

void producer() {
  while (1) { // Infinite loop (can be modified for specific production count)
    printf("\n Enter an item: ");
    scanf("%d", &item);

    // Critical section: wait for empty slot and acquire mutex
    pthread_mutex_lock(&mutex);
    while ((in + 1) % BUFFERSIZE == out) { // Check for buffer full condition
      printf("\n Buffer full, producer waiting\n");
      pthread_cond_wait(&empty, &mutex); // Wait for empty slot signal
    }

    // Produce item and update buffer
    buffer[in] = item;
    in = (in + 1) % BUFFERSIZE;

    // Release resources and signal consumer
    pthread_cond_signal(&full); // Signal consumer that a new item is available
    pthread_mutex_unlock(&mutex);
  }
}

void consumer() {
  while (1) { // Infinite loop (can be modified for specific consumption count)
    // Critical section: wait for filled slot and acquire mutex
    pthread_mutex_lock(&mutex);
    while (in == out) { // Check for buffer empty condition
      printf("\n Buffer empty, consumer waiting\n");
      pthread_cond_wait(&full, &mutex); // Wait for filled slot signal
    }

    // Consume item and update buffer
    item = buffer[out];
    out = (out + 1) % BUFFERSIZE;

    // Release resources and signal producer
    pthread_cond_signal(&empty); // Signal producer that a slot is empty
    pthread_mutex_unlock(&mutex);

    printf("\n Consumed item = %d\n", item);
  }
}

int main() {
  printf(
      "Enter the value of n (number of items to be produced and consumed): ");
  int n;
  scanf("%d", &n);

  // Initialize mutex and condition variables
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&empty, NULL);
  pthread_cond_init(&full, NULL);

  // Create producer and consumer threads
  pthread_t producer_thread, consumer_thread;
  pthread_create(&producer_thread, NULL, (void *)producer, NULL);
  pthread_create(&consumer_thread, NULL, (void *)consumer, NULL);

  // Wait for threads to finish (optional, depends on your use case)
  // pthread_join(producer_thread, NULL);
  // pthread_join(consumer_thread, NULL);

  // Destroy mutex and condition variables
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&empty);
  pthread_cond_destroy(&full);

  return 0;
}

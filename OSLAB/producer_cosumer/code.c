#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];

int in = 0;
int out = 0;

// Semaphores
sem_t empty;
sem_t full;

// Mutex lock
pthread_mutex_t mutex;


void* producer(void* arg)
{
    int item;

    while (1)
    {
        // Produce item
        item = rand() % 100;

        // Wait if buffer is full
        sem_wait(&empty);

        // Enter critical section
        pthread_mutex_lock(&mutex);

        // Add item to buffer
        buffer[in] = item;

        printf("Producer produced: %d at position %d\n",
               item, in);

        in = (in + 1) % BUFFER_SIZE;

        // Exit critical section
        pthread_mutex_unlock(&mutex);

        // Increase full count
        sem_post(&full);

        sleep(1);
    }
}


// ---------------- CONSUMER ----------------
void* consumer(void* arg)
{
    int item;

    while (1)
    {
        // Wait if buffer is empty
        sem_wait(&full);

        // Enter critical section
        pthread_mutex_lock(&mutex);

        // Remove item from buffer
        item = buffer[out];

        printf("Consumer consumed: %d from position %d\n",
               item, out);

        out = (out + 1) % BUFFER_SIZE;

        // Exit critical section
        pthread_mutex_unlock(&mutex);

        // Increase empty count
        sem_post(&empty);

        sleep(2);
    }
}



int main()
{
    pthread_t producerThread;
    pthread_t consumerThread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&producerThread,
                   NULL,
                   producer,
                   NULL);

    pthread_create(&consumerThread,
                   NULL,
                   consumer,
                   NULL);

    // Wait for threads
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);

    pthread_mutex_destroy(&mutex);

    return 0;
}

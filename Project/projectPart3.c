#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

#define NUM_ITERATIONS 100000
#define MAX_BUFFER_SIZE 100
//https://www.includehelp.com/c-programming-questions/compiling-program-with-pthread-library-linux.aspx

int counter = 0;
sem_t mutex;
sem_t full;
sem_t empty;
int buffer[MAX_BUFFER_SIZE];
int fillIndex = 0;
int useIndex = 0;

void put(int value){
    buffer[fillIndex] = value;
    fillIndex = (fillIndex+1);
}

int get(){
    int temp = buffer[useIndex];
    useIndex = (useIndex+1);
    return temp;
}

void *consumer(void*arg){   
    //sem_wait(&full);
    //sem_wait(&mutex);
        int tmp = get();
        sem_post(&mutex);
        sem_post(&empty);
        printf("Consuming %d from the buff\n",tmp);   
}

void *producer(void*arg){
        //sem_wait(&empty);
        //sem_wait(&mutex);
        put(counter);
        sem_post(&mutex);
        sem_post(&full);
        printf("Adding %d to the buffer\n", counter);
        counter++;
}

int main(int argc, char*argv[]){

    // Exercise 1
    pthread_t p1,p2;
    int rc;

    //initialize semaphore that will garuntee mutal exclusive access to the shared counter
    sem_init(&mutex,0,1); //at most 1 may access guarded resources
    sem_init(&full,0,0);
    sem_init(&empty, 0, MAX_BUFFER_SIZE);

    printf("main:begin\n");
    for(int s = 0; s < MAX_BUFFER_SIZE; s++){
        pthread_create(&p1,NULL,producer,"A");
        pthread_create(&p2,NULL,consumer,"B");
        pthread_join(p1, NULL);
        pthread_join(p2, NULL);
    }
    printf("main:end\n");
    printf("Produced Item Total: %d\n", fillIndex);
    printf("Consumed Item Total: %d\n",useIndex);

    printf("Destory everything\n");
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    
    return 0;
}

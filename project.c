#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

//#define NUM_ITERATIONS = 100000;
//#define MAX_BUFFER_SIZE = 10;
//https://www.includehelp.com/c-programming-questions/compiling-program-with-pthread-library-linux.aspx

static volatile int counter = 0;
sem_t mutex;
sem_t full;
sem_t empty;

void put(int value){
    int buffer[10];
    int fillIndex = 0;
    buffer[fillIndex] = value;
    fillIndex = (fillIndex+1)%10;
}

int get(){
    int useIndex = 0;
    int buffer[useIndex];
    int temp = buffer[useIndex];
    useIndex = (useIndex+1)%10;
    return temp;
}

void *consumer(void*arg){
    for(int i = 0; i < 100000; i++){
        int tmp = get();
        printf("%d\n",tmp);
    }
}

void *producer(void*arg){
    for(int i = 0; i < 100000;i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        put(i);
        sem_post(&mutex);
        sem_post(&full);
    }
}

void *mythread(void*arg){
    printf("Start%s\n", (char*)arg);
    for(int i = 0; i < 100000; i++){
        sem_wait(&mutex); //try to grain exclusie access 
        //ciritcal section accesses shared data 
        counter++;
        sem_post(&mutex); //release exclusive access
    }
    printf("Finish%s\n",(char *)arg);
    return NULL;
}

int main(int argc, char*argv[]){

    // Exercise 1
    pthread_t p1,p2;
    int rc;

    //initialize semaphore that will garuntee mutal exclusive access to the shared counter
    sem_init(&mutex,0,1); //at most 1 may access guarded resources

    printf("main:begin\n");
    rc = pthread_create(&p1,NULL,mythread,"A");
    assert(rc==0);
    producer(rc);
    rc = pthread_create(&p2,NULL,mythread,"B");
    assert(rc==0);
    rc = pthread_join(p1, NULL);
    assert(rc==0);
    rc = pthread_join(p2, NULL);
    assert(rc==0);
    printf("main:end\n");
    return 0;
}


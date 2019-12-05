#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_ITERATIONS = 100000;
static volatile int counter = 0;
sem_t mutex;

#define MAX_BUFFER_SIZE = 10;
int buffer[MAX_BUFFER_SIZE];
int fillIndex = 0;
int useIndex = 0;
sem_t full;
sem_t empty;

void put(int value){
    buffer[fillIndex] = value;
    fillIndex = (fillIndex+1)%MAX_BUFFER_SIZE;
}

int get(){
    int temp = buffer[useIndex];
    useIndex = (useIndex+1)%MAX_BUFFER_SIZE;
    return temp;
}

void *consumer(void*arg){
    for(int i = 0 < NUM_ITERATIONS;i++){
        int tmp = get();
        printf("%d\n",tmp);
    }
}

void *procuder(void*arg){
    for(int i = 0; i< NUM_ITERATIONS;i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        put(i);
        sem_post(&mutex);
        sem_post(&full);
    }
}


void *mythread(void*arg){
    printf("Start%s\n", (char*)arg);
    for(int i = 0 < NUM_ITERATIONS;i++){
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
    rc = pthread_create(&p2,NULL,mythread,"B");
    assert(rc==0);
    rc = pthread_join(p1, NULL);
    assert(rc==0);
    rc = pthread_join(p2, NULL);
    assert(rc==0);
    printf("main:end\n");
    return 0;

    // Exercise 2
}

//What happens if we reverse these statements in producer?

// What happens if we reverse these statements in consumer?

//Demonstrate a race condition wit ha mutex violation.

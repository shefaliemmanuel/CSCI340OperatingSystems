# include "pcb.h"
# include <stddef.h>
# include <stdio.h>
#include <stdbool.h>

# define MAX_Q_LEN 100

typedef struct{
    PCB pcbList[MAX_Q_LEN];
    int numProcesses;
    int time;
}ReadyQ;

void empty(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// post-conditon: sets numProcesses = 0

bool isEmpty(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// returns true if queue is empty - contains no processes; else, false.

// Q - pointer to a ReadyQueue
// returns true if queue is full - contains MAX_Q_LEN processes; else, false.
bool isFull(ReadyQ* Q);

int sizeOfQ(ReadyQ *Q);

bool insertQ(ReadyQ *Q);

PCB*remove(ReadyQ *Q);

void sortQ(ReadyQ *Q);

void runFCFS(ReadyQ *Q);

void removeFrontPCB(ReadyQ *Q);

void printQ(ReadyQ* Q);

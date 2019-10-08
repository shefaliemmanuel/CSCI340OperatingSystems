# include "pcb.h"
# include <stdbool.h>
# include <stdio.h>

# define MAX_Q_LEN 100

typedef struct{
    PCB pcbList[MAX_Q_LEN];
    int numProcesses;
}ReadyQ;

void empty(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// post-conditon: sets numProcesses = 0

bool isEmpty(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// returns true if queue is empty - contains no processes; else, false.

bool isFull(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// returns true if queue is full - contains MAX_Q_LEN processes; else, false.

int sizeOfQ(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// returns number of processes stored in the queue.

bool insert(ReadyQ *Q, PCB *process);
// Q - pointer to a ReadyQueue
// process - pointer to a PCB
// post-condition: if Q is not full, then insert process
// into next open processList array slot, increment
// numProcesses, and return true; else, return false.

PCB*remove(ReadyQ *Q);

void bubbleSort(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// post-condition: Sorts contents of queue into
// increasing order of remainingTime.  PCB with lowest
// remainingTime will occupy list slot index 0.

void print(ReadyQ* Q);
// Q - pointer to a ReadyQueue
// post-condition: prints out information for each PCB in the queue.

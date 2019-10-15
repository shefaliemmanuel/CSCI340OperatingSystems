#if !defined(readyQ_header)
#define readyQ_header

# include "pcb.h"
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>

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

bool isFull(ReadyQ* Q);
// Q - pointer to a ReadyQueue
// returns true if queue is full - contains MAX_Q_LEN processes; else, false.

int sizeOfQ(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// returns number of processes stored in the queue.

bool insertQ(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// process - pointer to a PCB
// post-condition: if Q is not full, then insert process
// into next open processList array slot, increment
// numProcesses, and return true; else, return false.

void sortQ(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// post-condition: Sorts contents of queue into
// increasing order of remainingTime.  PCB with lowest
// remainingTime will occupy list slot index 0.

void runFCFS(ReadyQ *Q);
// Q - pointer to a ReadyQueue
// post-condition: if Q is not empty, then call runProcess function
// on first PCB in the queue.  
// Run first process in Q to completion.  Shift all remaining
// PCBs one array slot forward so second is now first.
// Return number of units of time that first process ran

void removeFrontPCB(ReadyQ *Q);
// pre-condition: assume first PCB has completed.
// post-condition: shift all other PCB one slot to left
//                 decrement numProcesses by 1.

void printQ(ReadyQ* Q);
// Q - pointer to a ReadyQueue
// post-condition: prints out information for each PCB in the queue.

int runSRTF(ReadyQ* Q);
// Q - pointer to a ReadyQueue
// post-condition: if Q is not empty, then call sort to arrange the
// Q in ascending order of time time remaining to complete.
// Run first process in Q to completion.  Shift all remaining
// PCBs one array slot forward so second is now first.
// Return number of units of time that first process ran

int runRoundRobin(ReadyQ* Q, int timeSlice);
// Q - pointer to a ReadyQueue
// post-condition: if Q is not empty, then call runProcess function
// on first PCB in the queue.  After running the process, move it
// to the rear of the Q
// Return number of units of time that first process ran

#endif
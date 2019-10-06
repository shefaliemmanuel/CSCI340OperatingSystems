# include "pcb.h"
# define MAX_Q_LEN 100
typedef struct{
    PCB pcbList[MAX_Q_LEN];
    int numProcesses;
}ReadyQ;

void empty(ReadyQ *Q);

bool isEmpty(ReadyQ *Q);

int sizeOfQ(ReadyQ *Q);

bool insert(ReadyQ *Q);

PCB*remove(ReadyQ *Q);

void bubbleSort(ReadyQ *Q);

# include "readyQ.h"
# include <stdbool.h>
# include <stddef.h>

//set list to empty state
numProcesses = 0;

void empty(ReadyQ *Q){
    Q->numProcesses = 0;
    //memset(Q->processList,0,Q->numProcesses)
    Q->pcbList[0];
}
bool isEmpty(ReadyQ *Q){
    if(Q == NULL){
        return true;
    } return false;
}

bool isFull(ReadyQ *Q){
    if(Q->numProcesses == MAX_Q_LEN){
        return true;
    }else{
        return false;
    }
}

int sizeOfQ(ReadyQ *Q){
    //return Q->numProcesses;
    return sizeof(Q->pcbList);
}
bool insert(ReadyQ *Q, PCB *process){
    //use numProcesses as index for where to insert
    if(!isEmpty(Q)){
        Q->pcbList[Q->numProcesses] = *process;
        numProcesses= numProcesses + 1;
        return true;
    }else{
        return false;
    }
}

PCB*remove(ReadyQ *Q){
    if (Q == NULL){
        return NULL;
    }else{
        return Q->pcbList;
    }
}

void bubbleSort(ReadyQ *Q){
    ;
}

void print(ReadyQ* Q){
    for(int i = 0; i < sizeof(Q->pcbList);i++){
        printf("%d/n",Q->pcbList[i]->pid);
        printf("%d/n",Q->pcbList[i]->totalTime);
        printf("%d/n",Q->pcbList[i]->remainingTime);
    }
}
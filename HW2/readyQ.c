# include "readyQ.h"
# include <stdbool.h>
# include <stddef.h>

//set list to empty state
numProcesses = 0;

void empty(ReadyQ *Q){
    Q->numProcesses = 0;
    //memset(Q->processList,0,Q->numProcesses)
    //Q->pcbList[0];
}
bool isEmpty(ReadyQ *Q){
    if(Q->numProcesses == 0){
        return true;
    }else{
        return false;
    }
    //return Q->numProcesses == 0;
}

bool isFull(ReadyQ *Q){
    if(Q->numProcesses >= MAX_Q_LEN){
        return true;
    }else{
        return false;
    }
    //return Q->numProcesses >= MAX_Q_LEN;
}

int sizeOfQ(ReadyQ *Q){
    return Q->numProcesses;
    //return sizeof(Q->pcbList);
}

bool insert(ReadyQ *Q, PCB *process){
    //use numProcesses as index for where to insert
    if(!isFull(Q) && Q!=NULL && process != NULL){
        Q->pcbList[Q->numProcesses] = *process; //* because of the way PCB is defines (pass by value)
                                                // could change PCB* pcblist[Max] and then it would just be process no *
        Q->numProcesses = Q->numProcesses + 1;
        return true;
    }else{
        return false;
    }
}



PCB*remove(ReadyQ *Q){
    ;
}

void bubbleSort(ReadyQ *Q){
    ;
}


void runFCFS(ReadyQ *Q){
    ;
}

void removeFrontPCB(ReadyQ *Q){
    if(Q->numProcesses > 1){
        for(int i=0; i < (Q->numProcesses-1);i++){
            Q->pcbList[i] = Q->pcbList[i+1];
        }
    }
    Q->numProcesses = Q->numProcesses - 1;
}

void print(ReadyQ* Q){
    for(int i = 0; i < sizeof(Q->pcbList);i++){
        printf("%d/n",Q->pcbList[i]->pid);
        printf("%d/n",Q->pcbList[i]->totalTime);
        printf("%d/n",Q->pcbList[i]->remainingTime);
    }
}
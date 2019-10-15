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

bool insertQ(ReadyQ *Q, PCB *process){
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

void sortQ(ReadyQ *Q){
    ;
}


void runFCFS(ReadyQ *Q){
    if(!isEmpty(Q)){
        PCB* process = &(Q->pcbList[0]);

        //run until compeletion

        int timeRun = runProcess(process,process->remainingTime);
        //completed this Process, so print a message
        Q->time = Q->time + process->remainingTime;
        
        printf("Time %d Completed PID %d\n", Q->time, process->pid);
        //remove completed process from Q
    }
}

void removeFrontPCB(ReadyQ *Q){
    if(Q->numProcesses > 1){
        for(int i=0; i < (Q->numProcesses-1);i++){
            Q->pcbList[i] = Q->pcbList[i+1];
        }
    }
    if(!isEmpty(Q)){
        Q->numProcesses = Q->numProcesses - 1;
    }
}

void printQ(ReadyQ *Q){
    for(int i = 0; i < sizeof(Q->pcbList);i++){
        printf("%d/n",Q->pcbList[i]->pid);
        printf("%d/n",Q->pcbList[i]->totalTime);
        printf("%d/n",Q->pcbList[i]->remainingTime);
    }
}
# include "readyQ.h"
# include "pcb.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>

//set list to empty state
//numProcesses = 0;
//time = 0;

void emptyQueue(ReadyQ *Q){
    Q->numProcesses = 0;
    Q->time = 0;
    //memset(Q->processList,0,Q->numProcesses)
    //Q->pcbList[0];
}
bool isEmptyQueue(ReadyQ *Q){
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

void sortQ(ReadyQ *Q){
    // Q - pointer to a ReadyQueue
    // post-condition: Sorts contents of queue into increasing order of remainingTime.  PCB with lowest remainingTime will occupy list slot index 0. 
    for(int i = 0; i < Q->numProcesses;i++){
        for(int j = 0; j < Q->numProcesses-i-1;j++){
            if (Q->pcbList[i].remainingTime > Q->pcbList[j+1].remainingTime){
                PCB temp;
                temp = Q->pcbList[i];
                Q->pcbList[i] = Q->pcbList[i+1];
                Q->pcbList[i + 1] = temp;
            }
        }
    }
}

void runFCFS(ReadyQ *Q){
    if(!isEmptyQueue(Q)){
        PCB* process = &(Q->pcbList[0]);

        //run until compeletion

        int timeRun = runProcess(process,process->remainingTime);
        //completed this Process, so print a message
        Q->time = Q->time + timeRun;
        
        printf("Time %d Completed PID %d\n", Q->time, process->pid);
        //remove completed process from Q
        removeFrontPCB(Q);
    }
}

void removeFrontPCB(ReadyQ *Q){
    if(Q->numProcesses > 1){
        for(int i=0; i < (Q->numProcesses-1);i++){
            Q->pcbList[i] = Q->pcbList[i+1];
        }
    }
    if(!isEmptyQueue(Q)){
        Q->numProcesses = Q->numProcesses - 1;
    }
}

void printQ(ReadyQ *Q){
    for(int i = 0; i < sizeof(Q->pcbList);i++){
        printf("%d/n",Q->pcbList[i].pid);
        printf("%d/n",Q->pcbList[i].totalTime);
        printf("%d/n",Q->pcbList[i].remainingTime);

    }
}

int runSRTF(ReadyQ* Q){
// Q - pointer to a ReadyQueue
// post-condition: if Q is not empty, then call sort to arrange the
// Q in ascending order of time time remaining to complete.
// Run first process in Q to completion.  Shift all remaining PCBs one array slot forward so second is now first.
// Return number of units of time that first process ran
    if(!isEmptyQueue(Q)){
        sortQ(Q);
        removeFrontPCB(Q);
        sizeOfQ(Q);
    }
}

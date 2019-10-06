# include "readyQ.h"
# include <stdbool.h>
# include <stddef.h>

//set list to empty state
numProcesses = 0;

void empty(ReadyQ *Q){
    Q.numProcesses = 0;
    Q.pcbList[0];
}
bool isEmpty(ReadyQ *Q){
    if(Q != NULL){
        return true;
    } return false;
}
int sizeOfQ(ReadyQ *Q){
    sizeof(Q.pcbList);
}
bool insert(ReadyQ *Q){
    //use numProcesses as index for where to insert

}

PCB*remove(ReadyQ *Q){
    if (Q == NULL){
        return NULL;
    }else{
        return Q.pcbList;
    }
}

void bubbleSort(ReadyQ *Q){
    
}

# include "pcb.h"
# include "readyQ.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>

void main(){

    //declare each PCB
    PCB a;
    PCB b;
    PCB c;

    //initialize each PCB to certian values
    initProcessValues(&a, 1, 30); 
    initProcessValues(&b, 2, 20);
    initProcessValues(&c, 3, 10);

    //declare a ReadyQ
    ReadyQ shefQ;

    //initialize to empty
    //Pass shefQ by address using the & address-of operator
    emptyQueue(&shefQ);
    shefQ.time = 0;

    //insert process A into Q
    insertQ(&shefQ, &a);
    insertQ(&shefQ, &b);
    insertQ(&shefQ, &c);

    while(!isEmptyQueue(&shefQ)){
        runFCFS(&shefQ);
        printQ(&shefQ);
    }
}

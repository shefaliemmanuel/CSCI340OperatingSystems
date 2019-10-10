# include "pcb.h"
# include "readyQ.h"
# include <stddef.h>
# include <stdio.h>

void main(){

    //declare a PCB
    PCB a;
    //declare a PCB
    a.pid=1; //lazy way with out init
    a.totalTime=10; //lazy way
    //init_process(&a, 1, 10); USE & to turn a into the pointer to a

    //confirm initialization- print PID 1 TimeRemaining 10
    printf("PID %d TimeLeft %d\n", a.pid, a.remainingTime);

    //declare a ReadyQ
    ReadyQ shefQ;
    //initialize to empty
    //Pass shefQ by address using the & address-of operator
    empty(&shefQ);

    //test isEmpty, isFull, size
    printf("Is shefQ empty %d?\n", isEmpty(&shefQ));
    printf("Is shefQ full %d?\n", isFull(&shefQ));
    printf("What is shefQ size?  %d\n", sizeOfQ(&shefQ));

    //insert process A into Q
    bool sucessInsert = insertQ(&shefQ, &a);
    printf("Was the insert sucessful?  %d\n", sucessInsert)

    //unit testing
    printQ(&shefQ);

    //one run of FCFS
    runFCFS(&shefQ)

}

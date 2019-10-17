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
    a.pid = 1;
    a.totalTime = 30;
    a.remainingTime = 0;

    b.pid = 2;
    b.totalTime = 20;
    b.remainingTime = 0;

    c.pid = 3;
    c.totalTime = 10;
    c.remainingTime = 0;

    //USE & to turn a into the pointer to a
    //init_process(&a, 1, 30); 
    //init_process(&b, 2, 20);
    //init_process(&c, 3, 10);

    //confirm initialization- print PID 1 TimeRemaining 10
    //printf("PID %d TimeLeft %d\n", a.pid, a.remainingTime);
    //printf("PID %d TimeLeft %d\n", b.pid, b.remainingTime);
    //printf("PID %d TimeLeft %d\n", c.pid, c.remainingTime);

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
        
    }
}

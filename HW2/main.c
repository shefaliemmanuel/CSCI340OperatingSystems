# include "pcb.h"
# include "readyQ.h"
# include <stddef.h>

init_process(PCB *p1, 100, 10, 10);

//declare a PCB a;
PCB a;
//initialize
init_process(a, 100, 10, 10);

//declare a PCB b;
PCB *b;
init_process(b, 2, 10, 10);

runProcess(&p1,2);

printProcesses(PCB p1)
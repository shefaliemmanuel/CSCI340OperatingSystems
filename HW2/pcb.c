# include "pcb.h"
# include <stddef.h>
# include <stdio.h>

// simulate CPU run of a process
// &process_address of PCB
// &process_time run in secs
// dedeucted runTime from PCB remainingTime

void initProcess(PCB* process){
    process->pid = 0;
    process->totalTime = 0;
    process->remainingTime = 0; 
}

int runProcess(PCB *process, int runTime){
    if(process != NULL){
        if( runTime >= process->remainingTime){
            int returnMe = runTime;
            process->remainingTime = process->remainingTime - runTime;
            return returnMe;
        }
        else{
            int returnMe = process->remainingTime;
            process->remainingTime = 0;
            return returnMe;
        }
    }
}

void initProcessValues(PCB* process, int pid, int totalTime){
    process->pid = pid; 
    process->totalTime; 
    process->remainingTime = totalTime;
}



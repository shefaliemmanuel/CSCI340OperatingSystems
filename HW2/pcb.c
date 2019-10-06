# include "pcb.h"
# include <stddef.h>

// simulate CPU run of a process
// &process_address of PCB
// &process_time run in secs
// dedeucted runTime from PCB remainingTime

void init_process(PCB * process, int pid, int totalTime, int remainingTime){
    process->pid=pid;
    process->remainingTime=remainingTime;
    process->totalTime=totalTime;
}

void runProcess(PCB *process, int time){
    if(process != NULL){
        if(time < (*process).remainingTime)
        (*process).remainingTime -= time;
    }
}

void printProcesses(PCB p){
    printf(p.pid);
    printf(p.remainingTime);
    printf(p.totalTime);
}



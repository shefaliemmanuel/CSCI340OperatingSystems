# include "pcb.h"
# include <stddef.h>

// simulate CPU run of a process
// &process_address of PCB
// &process_time run in secs
// dedeucted runTime from PCB remainingTime

//void init_process(PCB *process, int pid, int totalTime, int remainingTime){
  //  process->pid = pid;
   // process->remainingTime = remainingTime;
    //process->totalTime = totalTime;
//}
void initProcess(PCB* process){
    process->pid = 0;
    process->totalTime = 0;
    process->remainingTime = 0; 
}

int runProcess(PCB *process, int ptime){
    if(process != NULL){
        if(process->remainingTime  >= ptime){
            int returnMe = ptime;
            process->remainingTime = process->remainingTime - ptime;
            return returnMe;
        }
        else{
            int returnMe = process->remainingTime;
            process->remainingTime = 0;
            return returnMe;
        }
    
    }
    else
    {
        return 0;
    }
    
}

void initProcessValues(PCB* process, int pid, int totalTime){
    process->pid = pid; 
    process->totalTime; 
    process->remainingTime = totalTime;
}



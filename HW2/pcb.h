# if !defined (PCB_Header)
# define PCB_Header
typedef struct{
    int pid, totalTime, remainingTime;
}PCB;

// comments from pcb.c

void init_process(PCB * process, int pid, int totalTime, int remainingTime);
// process - Pointer to a PCB
// post-condition: assigns all attributes to have value 0.

void init_process_values(PCB * process, int pid, int totalTime, int remainingTime);
// post-condtion: assign PCB total time to given totalRun time
// temianing time to same value, assigns pid value

void runProcess(PCB * process, int time);
// process - Pointer to a PCB
// runTime - Number of seconds to run this process on CPU
// post-condition: Decrease process remainingTime by 
// runTime only if runTime is >= remainingTime; else,
// decrease process remainingTime by remainingTime (zero it out),
// if remainingTime < runTime

void printProcesses(PCB p);

# endif

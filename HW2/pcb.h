# if !defined (PCB_Header)
# define PCB_Header
typedef struct{
    int pid, totalTime, remainingTime;
}PCB;

// comments from pcb.c

void init_process(PCB * process, int pid, int totalTime, int remainingTime);

void runProcess(PCB * process, int time);

void printProcesses(PCB p);

# endif

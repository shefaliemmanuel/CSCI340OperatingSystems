# if !defined (PCB_Header)
# define PCB_Header
typedef struct{
    int pid, totalTime, remainingTime;
}PCB;

// comments from pcb.c

void initProcess(PCB* process);
int runProcess(PCB * process, int time);
void initProcessValues(PCB* process, int pid, int totalRunTime);

# endif

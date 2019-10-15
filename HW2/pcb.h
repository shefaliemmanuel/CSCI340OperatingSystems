# if !defined (PCB_Header)
# define PCB_Header

typedef struct{
    int pid, totalTime, remainingTime;
}PCB;

// comments from pcb.c

void initProcess(PCB* process);
// process - Pointer to a PCB
// post-condition: assigns all attributes to have value 0.

int runProcess(PCB * process, int time);
// process - Pointer to a PCB
// runTime - Number of seconds to run this process on CPU
// post-condition: Decrease process remainingTime by 
// runTime only if runTime is >= remainingTime; else,
// decrease process remainingTime by remainingTime (zero it out),
// if remainingTime < runTime
// Return number of units of time actually run by the given process.

void initProcessValues(PCB* process, int pid, int totalTime);
// post-condion: assigned PCB totalTime to given totalRunTime and
// remainingTime to same value, assigns pid value

# endif
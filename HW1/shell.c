//
//  main.c
//  340
//
//  Created by Shefali Emmanuel on 9/19/19.
//  Copyright © 2019 Shefali Emmanuel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define argumentLength 100

int main() {

    printf("hello world");
    int spaceUsed = 0;
    char *argumentBuffer[argumentLength];

    printf("Please enter a command: ")

    while(fgets(argumentBuffer, argumentLength, stdin) && strcmp(argumentBuffer,"exit\n")!=0){
        //memset(argumentBuffer, 0, argumentLength);

char * pch;
            printf ("Splitting string \"%s\" into tokens:\n",argumentBuffer);
        pch = strtok (argumentBuffer," "); // used space to generate new tokens
        argumentBuffer[spaceUsed] = pch;
        spaceUsed++;

        while (pch != NULL){
            printf ("%s\n",pch); //allocates mem and returns a pointer to the memory
            pch = strtok (NULL, " ");
            argumentBuffer[spaceUsed] = *pch;
            // get rid of & symbol if its the 2nd to last
}//end while pch 

            bool isBackgroupJob =false;
            if (strcmp(argumentBuffer[spaceUsed-2], "&") == 0){
                argumentBuffer[spaceUsed-2] = NULL;
                isBackgrounpJob=true;
                //BOLEAN that says this is a backgroup job flag variable
            }

        int rc = fork();
    
  
        // fork failed; exit
        if (rc < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        // child (new process)
        else if (rc == 0) {
            printf("hello, I am child (pid:%d)\n", (int) getpid());

            
            execvp(argumentBuffer[0], argumentBuffer);
        }

    // parent goes down this path (original process)
    else {
 
        //take out the & symbol
        if(isBackgrounpJob == false){

int wc = wait(NULL);

}
        printf("hello, I am parent of %d (pid:%d)\n",
                rc, (int) getpid());
    }
}
}

printf("Goodbye.\n");

return 0;
}


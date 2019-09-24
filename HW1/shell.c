//
//  main.c
//  340
//
//  Created by Shefali Emmanuel on 9/19/19.
//  Copyright © 2019 Shefali Emmanuel. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define argumentLength 300

int main() {
    printf("hello world");
    char runBk = 0;
    int spaceUsed = 0;
    char  argumentBuffer[argumentLength];
    while(fgets(argumentBuffer, argumentLength, stdin) && strcmp(argumentBuffer,"exit\n")!=0){
        runBk = 0;
        memset(argumentBuffer, 0, argumentLength);
        int rc = fork();
        printf("Enter command: ");
        scanf("%[^\n]", argumentBuffer);
        if (strcmp(argumentBuffer, "exit\n")){
            return 0;
        }
        
        char * pch;
        printf ("Splitting string \"%s\" into tokens:\n",argumentBuffer);
        pch = strtok (argumentBuffer," "); // used space to generate new tokens
        argumentBuffer[spaceUsed] = *pch;
        spaceUsed++;
        while (pch != NULL){
            printf ("%s\n",pch); //allocates mem and returns a pointer to the memory
            pch = strtok (NULL, " ");
            argumentBuffer[spaceUsed] = *pch;
            // get rid of & symbol if its the 2nd to last
            if (strcmp(&argumentBuffer[spaceUsed-2], "&")){
                argumentBuffer[spaceUsed-2] = 0;
            }
        }
        
        // fork failed; exit
        if (rc < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        // child (new process)
        else if (rc == 0) {
            printf("hello, I am child (pid:%d)\n", (int) getpid());
            execvp(&argumentBuffer[0], argumentBuffer);
        }
    // parent goes down this path (original process)
    else {
        int wc = wait(NULL);
        //take out the & symbol
        if()
        printf("hello, I am parent of %d (pid:%d)\n",
                rc, (int) getpid());
    }
}

printf("Goodbye.\n");

return 0;
}


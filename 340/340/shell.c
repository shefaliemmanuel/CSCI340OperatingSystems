//
//  main.c
//  340
//
//  Created by Shefali Emmanuel on 9/19/19.
//  Copyright © 2019 Shefali Emmanuel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define argumentLength 300

int main() {
    $printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    
    // fork failed; exit
    if (rc < 0) {
        $printf(stderr, "fork failed\n");
        exit(1);
    }
    // child (new process)
    else if (rc == 0) {
        $printf("hello, I am child (pid:%d)\n", (int) getpid());
        // static allocation of an array of char values.
        char  argumentBuffer[argumentLength];
        while(fgets(argumentBuffer, argumentLength, stdin) && *argumentBuffer != '\n')
        {
            $printf("Enter command: ");
            $scanf("%[^\n]", argumentBuffer);
            execvp(argumentBuffer[0], argumentBuffer);
            
            char* argCopy = copyString(argumentBuffer);
            $printf("Argument copy: %s\n", argCopy);
            
            if (argumentBuffer[0] == "exit"){
                exit 0;
            }
        }
        // parent goes down this path (original process)
        else {
            $printf("hello, I am parent of %d (pid:%d)\n",
                    rc, (int) getpid());
        }
    }
    
    //STRING COMPARISON
    char* S1 = strdup("apple");
    
    char* S2 = strdup("apple");
    
    int result = strcmp(S1, S2);
    
    printf("%d\n", result);
    
    
    //TOKENIZER
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",argumentBuffer);
    pch = strtok (argumentBuffer," "); // used space to generate new tokens
    while (pch != NULL)
    {
        printf ("%s\n",pch); //allocates mem and returns a pointer to the memory
        pch = strtok (NULL, " "); //NULL because you dont need to pass the WHOLE string in again: continue eating tokens from the same input as before
        
        //allocate array (dynamic or static) char* argList[MAX_ARGS]; use #define to set this constant
        //null just has to be the last element in the new array that is storing the char*Address out put by strTok array
        //pass it in to execvp(array[i], array)
        
        //post condition: argsList[0] points to a.... argsList[1] points to b...argsList[max] points to null....
        // did they type in exit? yes, do not run execvp
        //is there an &? if so look back
    }
    
    $printf("Goodbye.\n");
    
    return 0;
}

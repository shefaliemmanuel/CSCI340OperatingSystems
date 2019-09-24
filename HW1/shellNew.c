//
//  main.c
//  340
//
//  Created by Shefali Emmanuel on 9/19/19.
//  Copyright B) 2019 Shefali Emmanuel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

#define argumentLength 100
#define newArgLen 100


int main (){
    int spaceUsed = 0;
    bool backgroundJobStatus = false;
    char argumentBuffer[argumentLength];
    int wc;

    printf ("Hi! Please enter a command >");
    while (fgets(argumentBuffer, argumentLength, stdin) && *argumentBuffer != '\n'){

        char *pch;

        pch = strtok (argumentBuffer, " ");	// used space to generate new tokens
        //argumentBuffer[spaceUsed] = pch;
        
        char *newArr[newArgLen];
        //tokenizes the user input
        while (pch != NULL){
            newArr[spaceUsed] = pch;
            spaceUsed++;
            //printf ("%s\n", pch);	//allocates mem and returns a pointer to the memory
            pch = strtok (NULL, " ");
        }//end while pch
        newArr[spaceUsed+1] = NULL;
        
        if (strcmp (newArr[spaceUsed - 2], "&") == 0){
            newArr[spaceUsed - 2] = NULL;
            backgroundJobStatus = true;
        } // end of while(fgets (argumentBuffer, argumentLength, stdin) && strcmp (argumentBuffer, "exit\n") != 0)
	    
	spaceUsed = 0;
	memset(argumentBuffer, 0, argumentLength); //empty argumentBuffer
	    
        int rc = fork ();
        // fork failed; exit
        if (rc < 0){
            fprintf (stderr, "fork failed\n");
            exit (1);
        }
        // child (new process)
        else if (rc == 0){
            printf ("hello, I am child (pid:%d)\n", (int) getpid ());
            execvp (newArr[0], newArr);
        }
        
      // parent goes down this path (original process)
      else{
	  //take out the & symbol
          if (backgroundJobStatus == false){
              wc = wait (NULL);
          }
          printf ("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid ());
      }
    printf ("Goodbye.\n");
    }
  return 0;
}

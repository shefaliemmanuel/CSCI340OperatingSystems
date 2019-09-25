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
#define newArgLen 10

//referenced: https://stackoverflow.com/questions/1515195/how-to-remove-n-or-t-from-a-given-string-in-c

int main (){
    
    bool backgroundJobStatus = false;
    char argumentBuffer[argumentLength];
    int wc;

    printf ("Hi! Please enter a command >");
    while (fgets(argumentBuffer, argumentLength, stdin) && *argumentBuffer != '\n'){

        if(strcmp(argumentBuffer,"exit\n")==0){
            exit(0);
        }//end if(strcmp)        

        int spaceUsed = 0;
        char *pch;
        pch = strtok (argumentBuffer, " ");	// used space to generate new tokens
    
        char* newArr[newArgLen];
        
        //tokenizes the user input
        while (pch != NULL){
            //get rid of /n after tokenzier 

            //This code until the next comment was found on github
            char *strip_copy(const char *s) {
                char *p = malloc(strlen(s) + 1);
                if(p) {
                    char *p2 = p;
                    while(*s != '\0') {
                        if(*s != '\t' && *s != '\n') {
                            *p2++ = *s++;
                        } else {
                            ++s;
                        }
                    }
                    *p2 = '\0';
                    }             
                    return p;
                }// end of code found on github

            //char results= strip(*pch);
            newArr[spaceUsed] = strip_copy(pch);
            printf ("%s\n", pch);
            pch = strtok (NULL, " ");
            spaceUsed++;
            if(argumentBuffer[strlen(argumentBuffer)-1] == '\n'){
                argumentBuffer[strlen(argumentBuffer)-1] = '\0';
            }//end of if argumentBuffer
        }//end while (pch != NULL)

        newArr[spaceUsed] = NULL;
        
        if (strcmp (newArr[spaceUsed - 1], "&") == 0){
            newArr[spaceUsed - 1] = NULL;
            backgroundJobStatus = true;
        } // end of while(fgets (argumentBuffer, argumentLength, stdin) && strcmp (argumentBuffer, "exit\n") != 0

	spaceUsed = 0;
	//memset(argumentBuffer, 0, argumentLength); //empty argumentBuffer
	    
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
    printf ("Restarting...\n");
    printf ("Hi! Please enter a command >");
    }
  return 0;
}

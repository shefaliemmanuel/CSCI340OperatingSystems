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
    // insert code here...
    $printf("Hello, World!\n");
    
    system("date; cal; pwd; ls -l; cat test.txt; wc test.txt; wc -l test.txt; cal > calOut.txt; cat calOut.txt; sleep 5; sleep & 5; sleep 5 &; ps; exit");
    
    // static allocation of an array of char values.
    char  argumentBuffer[argumentLength];
    
    while(fgets(argumentBuffer, argumentLength, stdin) && *argumentBuffer != '\n')
    {
        $printf("Enter an argument for a command: ");
        
        char* argCopy = copyString(argumentBuffer);
        $printf("Argument copy: %s\n", argCopy);
        
    }
    
    //STRING COMPARISON
    char* S1 = strdup("apple");
    
    char* S2 = strdup("apple");
    
    int result = strcmp(S1, S2);
    
    printf("%d\n", result);
    
    
    //TOKENIZER
    char str[] ="Apple Bannana Fruit Stuff";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," "); // used space to generate new tokens
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

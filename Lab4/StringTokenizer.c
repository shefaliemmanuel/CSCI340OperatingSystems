//
//  StringTokenizer.c
//  
//
//  Created by Shefali Emmanuel on 9/19/19.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main ()
{
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
    return 0;
}

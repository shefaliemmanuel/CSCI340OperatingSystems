#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an integer constant for the C preprocessor.
// The preprocessor will substitute the text ARGLEN for the literal 100
#define ARGLEN 100

// The C-language requires that we declare function signatures before
// we attempt to call a function.
// The body of the function can be declared below.
char* copyString(char *buf);

int main()
{
  // static allocation of an array of char values.
  char  argBuf[ARGLEN];
  
  printf("Enter an argument for a command: "); //replace prompt with $
  while(fgets(argBuf, ARGLEN, stdin) && *argBuf != '\n')
  {
    printf("You entered argument: %s\n", argBuf);

    char* argCopy = copyString(argBuf);
    printf("Argument copy: %s\n", argCopy);

    printf("Enter an argument for a command: ");
  }

  printf("You entered nothing.  Goodbye.\n");

  // Exit condition normal - value 0.
  exit(0);
}

// receives a string buffer read from keyboard.
// dynamically allocates memory to make a deep copy of the given buf string.
// return pointer to deep copy of given input string.

//Deep VS Shallow Copy

//Char * str1= hello
//char * str2= bye
//Shallow Copy str1 = str2 which means str1 get pointed to str2
//results in memory leak

//Deep Copy
//str2 give me some chunk of memory that can fit str1 (copied 1 by 1) until it hits "/0" and then terminates after copying "/0"
//call strLen(str1)
//malloc(strLen(str1)+1 characters)
//str copy
char* copyString(char* buf)
{
  char *cp = NULL;
	
	// Optional - May need to do this on some systems.
  // Replace '\n' by end of string terminator character '\0'
  // buf[strlen(buf)-1] = '\0';
  cp = malloc( strlen(buf) + 1);
	
  if(cp != NULL)
    strcpy(cp, buf); // copy from buf into cp array.
	                   // assumes buf ends with a '\n' or '\0' terminator
  return cp;
}

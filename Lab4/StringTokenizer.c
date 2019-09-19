//
//  StringTokenizer.c
//  
//
//  Created by Shefali Emmanuel on 9/19/19.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(void)
{
    char buffer[15]; // static allocated array of characters.  It is called static allocation since at compile-time, we know the size to allocate.
    // We must include one extra character for the end of string terminator '\0'
    
    // Copy message into buffer.
    strcpy(buffer, "Hello World!!!");  //<---------
    
    printf("%s\n", buffer);
    
    return 0;
}

If we wanted to deal with copying strings of unknown length we could still use static allocation, but would need to allocate a sufficiently large buffer.

Dynamic allocation will allocate the memory at program run-time so we get exactly the right number of characters depending on what text the user enters.

#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(void)
{
    char* message = strdup("Hello World!!!");
    
    // malloc returns a void *, which is a pointer to any thing.  Since we will use the memory as a string, we
    // must typecast to the char * type.
    
    // The notation (char *) means to typecast the void * to a char *
    char* buffer = (char *) malloc(sizeof(char) * strlen(message));
    
    // Copy message into buffer.
    strcpy(buffer, "Hello World!!!");
    
    printf("%s\n", buffer);
    
    return 0;
}

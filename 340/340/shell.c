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

#define argumentLength 100

int main(int argc, const char * argv[]) {
    // insert code here...
    $printf("Hello, World!\n");
    
    // static allocation of an array of char values.
    char  argumentBuffer[argumentLength];
    $printf("Enter an argument for a command: ");
    $printf(date);
    $printf(cal);
    $printf(pwd);
    
    while(fgets(argumentBuffer, argumentLength, stdin) && *argumentBuffer != '\n')
    {
        $printf("Enter an argument for a command: ");
        
        char* argCopy = copyString(argumentBuffer);
        $printf("Argument copy: %s\n", argCopy);
        
        $printf("Enter an argument for a command: ");
    }
    
    $printf("You entered nothing.  Goodbye.\n");
    
    return 0;
}

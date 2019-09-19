//
//  StringComparison.c
//  
//
//  Created by Shefali Emmanuel on 9/19/19.
//

#include <string.h>

#include <stdio.h>

int main()

{
    
    // Try different combinations of string pairs
    
    // apple vs apple
    //    if the number is the same then it should return 0
    
    // apple vs apples
//    -115
    
    // apple vs zebra
//    97 - 122 = -25
    
    // zebra vs apple
//    122 - 97 = 25
    
    // apple vs APPLE
//    32
    
    // APPLE vs apple
//    -32
    
    char* S1 = strdup("apple");
    
    char* S2 = strdup("apple");
    
// it is an addition of  of ascii characters
//    for this reason it IS case sensative
//compares one charater at a time
// Positive Result: If left char is lexicographically after the right char
// Negative Result: If left char is lexicographically before the right char
    
//I came to this conclusion through testing and reference to https://www.geeksforgeeks.org/strcmp-in-c-cpp/
    
    int result = strcmp(S1, S2);
    
    printf("%d\n", result);
    
}

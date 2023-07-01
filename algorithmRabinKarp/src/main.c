#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "algoritmRobinKarp.h"

int main(void) {
    unsigned char pattern[16];
    int patternLen = 0;
    unsigned char text[16];
    int textLen = 0;
    int isNaN = 0;
    
    int ch;
    while ((ch = getc(stdin)) != '\n') {
        pattern[patternLen] = (unsigned char)ch;
        patternLen++;
    }
    while (textLen != patternLen) {
        if ((ch = getc(stdin)) != EOF) {
            text[textLen] = (unsigned char)ch;
            textLen++;
        }
        else {
            isNaN= 1;
            break;
        }
    }

    int hashPattern = GetHash(pattern, patternLen);
    int hashText = GetHash(text, textLen);

    printf("%d ", hashPattern);
    if (!isNaN) {
        AlgoritmRobinKarp(hashPattern, hashText, text, pattern, patternLen);
    }
    
 
    return EXIT_SUCCESS;
}

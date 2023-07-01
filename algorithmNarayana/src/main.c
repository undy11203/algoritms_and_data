#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "swapperNair.h"
#include "outputResult.h"

int main(void) {
    char comb[11];
    int combLen = 0;
    int numberCount[10];
    for (int i = 0; i < 10; ++i) {
        numberCount[i] = 0;
    }

    char ch;
    while ((ch = (char)getchar()) != '\n') {
        if (ch >= '0' && ch <= '9') {
            if (numberCount[ch - '0'] < 1) {
                numberCount[ch - '0']++;
            }else {
                printf("%s", "bad input");
                return 0;
            }
            comb[combLen] = ch;
            combLen++;
        }else {
            printf("%s", "bad input");
            return 0;
        }
    }
    int N;
    if (scanf("%d", &N) == -1) {
        return 0;
    }

    OutputResult(comb, combLen, N);
    
    return EXIT_SUCCESS;
}

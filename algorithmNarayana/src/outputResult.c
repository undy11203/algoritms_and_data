#include <stdio.h>
#include <stdlib.h>

#include "swapperNair.h"
#include "outputResult.h"

void OutputResult(char* comb, int combLen, int N) {
    comb[combLen] = '\0';
    for (int i = 0; i < N; i++) {
        if (SwapperNair(comb, combLen)) {
            printf("%s\n", comb);
        }
        else {
            break;
        }
    }
}


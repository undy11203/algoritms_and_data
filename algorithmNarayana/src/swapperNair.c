#include <stdlib.h>
#include "swapperNair.h"

void Swap(char* a, char* b) {
    char perm = *a;
    *a = *b;
    *b = perm;
}

void Reverse(char* array, int indexStart, int arrayLen) {
    if (indexStart < arrayLen) {
        for (int i = indexStart + 1, indexStop = arrayLen - 1; i < indexStop; i++, indexStop--)
        {
            Swap(&array[i], &array[indexStop]);
        }
    }
}

int SwapperNair(char* array, int arrayLen) {
    int lastComb = atoi(array);
    int indexI = 0, indexJ = 0;
    for (int i = arrayLen - 1; i > 0; i--) {
        if (array[i - 1] < array[i]) {
            indexI = i - 1;
            break;
        }
    }
    for (int j = arrayLen - 1; j > indexI; j--) {
        if (array[indexI] < array[j]) {
            indexJ = j;
            break;
        }
    }
    Swap(&array[indexI], &array[indexJ]);
    Reverse(array, indexI, arrayLen); 
    int newComb = atoi(array);
    if (lastComb < newComb) {
        return 1;
    }
    else {
        return 0;
    }
}

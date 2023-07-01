#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "heapSort.h"

int main(void) {
    int N;
    int input;
    if (scanf("%d", &N) == -1 || N<0) {
        printf("bad input");
    }

    int* array = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &input) == -1) {
            printf("bad input");
        }
        array[i] = input;
    }

    HeapSort(array, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    free(array);

    return EXIT_SUCCESS;
}

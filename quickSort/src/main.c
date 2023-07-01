#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "quickSort.h"

int main(void) {
    int N, input;
    int* array;
    if (scanf("%d", &N) == -1 || N < 0) {
        printf("bad input");
        return 0;
    }
    if (N > 0) {
        array = (int*)malloc(sizeof(int) * N);
    }
    else {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &input) == -1) {
            printf("bad input");
            free(array);
            return 0;
        }
        array[i] = input;
    }

    if (NeedArraySort(array, N)) {
        QuickSort(array, 0, N - 1);
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    free(array);

    return EXIT_SUCCESS;
}

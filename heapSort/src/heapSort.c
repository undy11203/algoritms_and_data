#include<stdio.h>
#include "heapSort.h"

void Swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void Heapify(int array[], int N, int i) {
    int largest = i;
    int left = i * 2 + 1;
    int rigth = i * 2 + 2;

    if (left < N && array[left] > array[largest]) {
        largest = left;
    }
    if (rigth < N && array[rigth] > array[largest]) {
        largest = rigth;
    }
    if (largest != i) {
        Swap(&array[i], &array[largest]);
        Heapify(array, N, largest);
    }
}

void HeapSort(int array[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--) {
        Heapify(array, N, i);
    }

    for (int i = N - 1; i >= 0; i--) {
        Swap(&array[0], &array[i]);
        Heapify(array, i, 0);
    }
}

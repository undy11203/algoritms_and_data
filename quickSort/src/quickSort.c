#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quickSort.h"

void Swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int Partition(int array[], int startIndex, int endIndex) {
    int pivot = array[endIndex];
    int smallerIndex = startIndex - 1;

    for (int i = startIndex; i < endIndex; i++) {
        if (array[i] < pivot) {
            smallerIndex++;
            Swap(&array[smallerIndex], &array[i]);
        }
    }

    Swap(&array[smallerIndex + 1], &array[endIndex]);
    return smallerIndex + 1;
}


int RandomPartition(int arr[], int start, int end){
    int randomPivotIndex = rand() % (end - start + 1) + start;
    srand((unsigned int)time(NULL));
    Swap(&arr[randomPivotIndex], &arr[end]);

    return Partition(arr, start, end);
}

void QuickSort(int array[], int startIndex, int endIndex) {
    if (startIndex < endIndex) {//то пашем
        int wall = RandomPartition(array, startIndex, endIndex);
        QuickSort(array, startIndex, wall - 1);
        QuickSort(array, wall + 1, endIndex);
    }
}

int NeedArraySort(int array[], int N) {
    int i = 1;
    while(i < N) {
        if (array[i-1] != array[i]) {
            return 1;
        }
        i++;
    }

    return 0;
}


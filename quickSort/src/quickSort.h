#define QUICKSORT_H

void Swap(int* a, int* b);

int Partition(int array[], int startIndex, int endIndex);

void QuickSort(int array[], int startIndex, int endIndex);

int NeedArraySort(int array[], int N);



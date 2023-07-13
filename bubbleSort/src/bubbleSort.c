#include <stdlib.h>

#include "bubbleSort.h"

void Swap(int* i, int* j) {
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

void BubbleSort(int countElement, int* array) {
	for (int i = 0; i < countElement; i++) {
		for (int j = 0; j < countElement - 1; j++) {
			if (array[j] > array[j + 1]) {
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}

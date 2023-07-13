#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "bubbleSort.h"

int* InputArray(int countElement) {
	int* array = (int*)malloc(sizeof(int) * countElement);

	for (int i = 0; i < countElement; i++) {
		scanf("%d", &array[i]);
	}
	return array;
}

void OutputArray(int countElement, int* array) {
	for (int i = 0; i < countElement; i++) {
		printf("%d ", array[i]);
	}
}

int main() {

	int countElem;
	scanf("%d", &countElem);

	int* array = InputArray(countElem);

	BubbleSort(countElem, array);

	OutputArray(countElem, array);

	getchar();

	return 0;
}
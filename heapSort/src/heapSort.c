#include<stdio.h>
#include "heapSort.h"

void Swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void Heapify(int array[], int N, int i) {
    // Инициализируем наибольший элемент как корень
    int largest = i;
    int left = i * 2 + 1;
    int rigth = i * 2 + 2;

     // Если левый дочерний элемент больше корня
    if (left < N && array[left] > array[largest]) {
        largest = left;
    }
    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (rigth < N && array[rigth] > array[largest]) {
        largest = rigth;
    }
    // Если самый большой элемент не корень
    if (largest != i) {
        Swap(&array[i], &array[largest]);
        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        Heapify(array, N, largest);
    }
}

void HeapSort(int array[], int N) {
    // Построение кучи (перегруппируем массив)
    for (int i = N / 2 - 1; i >= 0; i--) {
        Heapify(array, N, i);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = N - 1; i >= 0; i--) {
        Swap(&array[0], &array[i]);
        // вызываем процедуру heapify на уменьшенной куче
        Heapify(array, i, 0);
    }
}

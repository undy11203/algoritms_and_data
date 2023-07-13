#include <stdlib.h>

#include "BFS.h"

typedef struct {
	int* vertics;
	struct Queue* next;
} Queue;

Queue* CreateQueue(int start) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->vertics = start;
	queue->next = NULL;

	return queue;
}

Queue* Enqueue(Queue* queue, int vertics) {
	Queue* tmp = (Queue*)malloc(sizeof(Queue));
	tmp->vertics = vertics;
	tmp->next = queue;

	queue = tmp;
	return queue;
}

Queue* Dequeue(int* value, Queue* queue) {
	Queue* tmp = queue;
	queue = queue->next;

	*value = tmp->vertics;
	free(tmp);

	return queue;
}

int isAllVerticsConnect(int* verticsVisited, int vertics) {
	for (int i = 0; i < vertics; i++) {
		if (!verticsVisited[i]) return 0;
	}
	return 1;
}

int BFS(int** adjMatrix, int start, int vertics) {
	Queue* queue = CreateQueue(start);
	char* verticsVisited = calloc(vertics, sizeof(char));

	verticsVisited[start] = 1;

	while (queue) {
		int currentVertics;
		queue = Dequeue(&currentVertics, queue);

		for (int i = 0; i < vertics; i++) {
			if (adjMatrix[currentVertics][i] == 1) {
				if (!verticsVisited[i]) {
					queue = Enqueue(queue, i);
					verticsVisited[i] = 1;
				}
			}
		}
	}

	return isAllVerticsConnect(verticsVisited, vertics);

}
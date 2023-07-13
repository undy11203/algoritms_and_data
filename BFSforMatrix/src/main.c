#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "BFS.h"

int** InputGraph(int vertics, int edges) {
	int** adjMatrix = (int**)malloc(vertics * sizeof(int*));
	for (int i = 0; i < vertics; i++) {
		adjMatrix[i] = calloc(vertics, sizeof(int));
	}

	int vertics1, vertics2;
	for (int i = 0; i < edges; i++) {
		scanf("%d %d", &vertics1, &vertics2);
		adjMatrix[vertics1][vertics2] = 1;
		adjMatrix[vertics2][vertics1] = 1;
	}

	return adjMatrix;
}

int main() {

	int vertics, edges;
	scanf("%d %d", &vertics, &edges);

	int** adjMatrix = InputGraph(vertics, edges);

	int start;
	scanf("%d", &start);

	printf("%d", BFS(adjMatrix, start, vertics));

	return 0;
}
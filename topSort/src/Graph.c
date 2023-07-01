#include <stdlib.h>
#include <limits.h>

#include "Graph.h"

TStack* AddNode(TStack* node, int value) {
	if (!node) {
		node = calloc(1, sizeof(TStack));
		node->value = value+1;
	}
	else {
		TStack* ptr = malloc(sizeof(TStack));
		ptr->value = value+1;
		ptr->next = node;
		node = ptr;
	}
	return node;
}

void FreeStack(TStack* root) {
	while (root) {
		TStack* ptr = root;
		root = root->next;
		free(ptr);
	}
}

int DFS(char* colors, int current, int maxVertics, char* adjMatrix, TStack** node) {
	colors[current] = 1;
	for (int i = 0; i < maxVertics; i++) {
		int index = (current * maxVertics + i) / CHAR_BIT;
		char binaryMask = (CHAR_MAX + 1) >> ((current * maxVertics + i) % CHAR_BIT);
		binaryMask &= adjMatrix[index];
		if (binaryMask) {
			if (colors[i] == 0) {
				if (!DFS(colors, i, maxVertics, adjMatrix, node)) {
					return 0;
				}
			}
			else if (colors[i] == 1) {
				return 0;
			}
		}
	}
	*node = AddNode(*node, current);
	colors[current] = 2;
	return 1;
}

int TopSort(char* adjMatrix, int maxVertics, TStack** node) {
	char* colors = calloc(maxVertics, sizeof(char));
	for (int i = 0; i < maxVertics; i++) {
		if (colors[i] == 0) {
			if (!DFS(colors, i, maxVertics, adjMatrix, node)) {
				free(colors);
				return 0;
			}
		}
	}
	free(colors);
	return 1;
}

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "Prim.h"

int MinKey(unsigned* key, char* inMST, int countVertix) {
    unsigned min = (unsigned)INT_MAX + 1;
    int minIndex = 0;

    for (int i = 0; i < countVertix; i++)
    {
        if (inMST[i] == 0 && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void Prim(int* matrix, int countVertix) {
	int* parent = calloc(countVertix, sizeof(int));
	unsigned* key = calloc(countVertix, sizeof(unsigned));
	char* inMST = calloc(countVertix, sizeof(char));

	for (int i = 0; i < countVertix; i++) {
		key[i] = (unsigned)INT_MAX + 1;
	}

	key[0] = 0;
	parent[0] = -1;

    for (int i = 0; i < countVertix - 1; i++) {
        int u = MinKey(key, inMST, countVertix);
        inMST[u] = 1;

        for (int j = 0; j < countVertix; j++) {
            if (matrix[u * countVertix + j] && inMST[j] == 0 && (unsigned)matrix[u * countVertix + j] < key[j]) {
                parent[j] = u;
                key[j] = matrix[u * countVertix + j];
            }
        }
    }

    for (int i = 0; i < countVertix; i++) {
        if (key[i] == (unsigned)INT_MAX + 1) {
            printf("no spanning tree");
            free(parent);
            free(key);
            free(inMST);
            return;
        }
    }

    for (int i = 1; i < countVertix; i++) {
        printf("%d %d\n", parent[i] + 1, i + 1);
    }
    free(key);
    free(parent);
    free(inMST);
}

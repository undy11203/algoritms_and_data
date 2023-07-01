#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "Input.h"
#include "Graph.h"
#include "Output.h"

int main(void) {
    int N, M;
    if (!InputVerticsAndEdge(&N, &M)) {
        return 0;
    }

    int sizeAdjMatrix = (N * N / CHAR_BIT) + 1;
    char* adjMatrix = calloc(sizeAdjMatrix, sizeof(char));
    TStack* stack = NULL;

    for (int i = 0; i < M; i++) {
        int vertic1, vertic2;
        if (!InputWay(&vertic1, &vertic2, N)) {
            free(adjMatrix);
            return 0;
        }
        int index = ((vertic1-1) * N + (vertic2-1)) / CHAR_BIT;
        char binaryMask = (CHAR_MAX + 1) >> (((vertic1 - 1) * N + (vertic2 - 1)) % CHAR_BIT);
        adjMatrix[index] |= binaryMask;
    }
    if (!TopSort(adjMatrix, N, &stack)) {
        free(adjMatrix);
        FreeStack(stack);
        printf("impossible to sort");
        return 0;
    }

    free(adjMatrix);
    PrintSortGraph(stack);

    return EXIT_SUCCESS;
}

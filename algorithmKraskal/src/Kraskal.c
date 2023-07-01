#include <stdlib.h>
#include <stdio.h>
#include "Kraskal.h"

int compare(const void* a, const void* b) {
    TEdge* c = (TEdge*)a,
        * d = (TEdge*)b;
    return c->Weight - d->Weight;
}

int Find(int i, int* parent) {
    if (i == parent[i]) {
        return i;
    }
    return parent[i] = Find(parent[i], parent);
}

void Union(int x, int y, int* parent, int* rank) {
    x = Find(x, parent);
    y = Find(y, parent);
    if (rank[x] < rank[y]) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
        if (rank[x] == rank[y]) {
            ++rank[x];
        }
    }
}

void Kraskal(TEdge* edges, int numberVertics, int numberEdges) {
    qsort(edges, numberEdges, sizeof(TEdge), compare);

    TEdge* mstTree = malloc(numberVertics * sizeof(TEdge));
    int countEdges = 0;
    int* parent = calloc(numberVertics, sizeof(int)),
        * rank = calloc(numberVertics, sizeof(int));

    for (int i = 0; i < numberVertics; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < numberEdges; i++) {
        int start = Find(edges[i].VertixStart - 1, parent);
        int end = Find(edges[i].VertixEnd - 1, parent);
        if (start != end) {
            mstTree[countEdges].VertixStart = edges[i].VertixStart;
            mstTree[countEdges].VertixEnd = edges[i].VertixEnd;
            countEdges++;
            Union(start, end, parent, rank);
            if (countEdges == numberVertics - 1) {
                break;
            }
        }
    }
    if (countEdges != numberVertics - 1) {
        free(mstTree);
        free(parent);
        free(rank);
        printf("no spanning tree");
        return;
    }

    for (int i = 0; i < countEdges; i++) {
        printf("%d %d\n", mstTree[i].VertixStart, mstTree[i].VertixEnd);
    }
    free(mstTree);
    free(parent);
    free(rank);
}

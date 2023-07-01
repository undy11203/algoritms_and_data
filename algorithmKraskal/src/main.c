#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Kraskal.h"

int main(void) {
    int N, M;

    if (scanf("%d%d", &N, &M) < 2) {
        printf("bad number of lines");
    }
    
    if (N < 0 || N>5000) {
        printf("bad number of vertices");
        return 0;
    }
    if (M < 0 || M > N * (N + 1) / 2) {
        printf("bad number of edges");
        return 0;
    }

    TEdge* edges = calloc(M, sizeof(TEdge));
    for (int i = 0; i < M; i++) {
        int ver1, ver2, weight;
        if (scanf("%d %d %d", &ver1, &ver2, &weight) < 3) {
            printf("bad number of lines");
            free(edges);
            return 0;
        }
        if (ver1 < 1 || ver1 > N) {
            printf("bad vertex");
            free(edges);
            return 0;
        }
        if (ver2 < 1 || ver2 > N) {
            printf("bad vertex");
            free(edges);
            return 0;
        }
        if (weight < 0 || weight > INT_MAX) {
            printf("bad length");
            free(edges);
            return 0;
        }
        edges[i].VertixStart = ver1;
        edges[i].VertixEnd = ver2;
        edges[i].Weight = weight;
    }

    Kraskal(edges, N, M);
    free(edges);

    return EXIT_SUCCESS;
}

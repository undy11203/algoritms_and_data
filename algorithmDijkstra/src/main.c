#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "Dijkstra.h"

int main(void) {
    int N, M, S, F;

    if (scanf("%d %d %d %d", &N, &S, &F, &M) < 4) {
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

    if (S < 1 || F < 1 || S > N || F > N) {
        printf("bad vertex");
        return 0;
    }

    int* matrix = calloc(N * N, sizeof(int));
    for (int i = 0; i < M; i++) {
        int vertix1, vertix2, distance;
        if (scanf("%d %d %d", &vertix1, &vertix2, &distance) < 3) {
            printf("bad number of lines");
            free(matrix);
            return 0;
        }
        if (vertix1 < 1 || vertix1 > N) {
            printf("bad vertex");
            free(matrix);
            return 0;
        }
        if (vertix2 < 1 || vertix2 > N) {
            printf("bad vertex");
            free(matrix);
            return 0;
        }
        if (distance < 0 || distance > INT_MAX) {
            printf("bad length");
            free(matrix);
            return 0;
        }
        vertix1--;
        vertix2--;
        matrix[vertix1 * N + vertix2] = distance;
        matrix[vertix2 * N + vertix1] = distance;
    }

    Dijkstra(matrix, N, S, F);
    free(matrix);

    return EXIT_SUCCESS;
}

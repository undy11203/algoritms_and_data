#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "Dijkstra.h"

void Dijkstra(int* matrix, int vertix, int start, int finish) {
    start--;
    finish--;

    char* used = calloc(vertix, sizeof(char));
    unsigned* distance = calloc(vertix, sizeof(unsigned));
    int* parent = calloc(vertix, sizeof(int));
    int overflowWay = 0;

    for (int i = 0; i < vertix; i++) {
        distance[i] = UINT_MAX;
        parent[i] = i;
    }
    distance[start] = 0;
    for (int i = 0; i < vertix; i++) {
        int currVertix = -1;
        for (int j = 0; j < vertix; j++) {
            if (!used[j] && (currVertix == -1 || distance[j] < distance[currVertix])) {
                currVertix = j;
            }
        }
        if (currVertix == -1) {
            break;
        }
        used[currVertix] = 1;
        for (int j = 0; j < vertix; j++) {
            if (matrix[currVertix * vertix + j]) {
                if (matrix[currVertix * vertix + j] + distance[currVertix] < distance[j] && !used[j]) {
                    if (matrix[currVertix * vertix + j] + distance[currVertix] <= INT_MAX) {
                        distance[j] = matrix[currVertix * vertix + j] + distance[currVertix];
                    }
                    else {
                        distance[j] = UINT_MAX - 1;
                    }
                    parent[j] = currVertix;
                }
            }
        }
    }

    for (int i = 0; i < vertix; i++) {
        if (distance[i] == UINT_MAX - 1) {
            overflowWay++;
            for (int j = i; j < vertix; j++) {
                if (matrix[i * vertix + j] && distance[j] != UINT_MAX) {
                    overflowWay++;
                }
            }
        }
    }
    for (int i = 0; i < vertix; i++) {
        if (distance[i] == UINT_MAX) {
            printf("oo ");
        }
        else if (distance[i] > INT_MAX) {
            printf("INT_MAX+ ");
        }
        else {
            printf("%u ", distance[i]);
        }
    }
    printf("\n");


    if (distance[finish] == UINT_MAX) {
        printf("no path");
    }
    else if (overflowWay > 1 && distance[finish] > INT_MAX) {
        printf("overflow");
    }
    else {
        for (int i = finish; i != start; i = parent[i]) {
            printf("%d ", i + 1);
        }
        printf("%d ", start + 1);
    }

    free(used);
    free(parent);
    free(distance);
}

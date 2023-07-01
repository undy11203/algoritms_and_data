#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "Input.h"
#include "Tree.h"
#include "Height.h"
#include "Alloc.h"

int main(void) {
    int N, number;
    Input(&N);

    TTree* tree = NULL;

    if (N > 0) {
        Input(&number);
        tree = CreateRoot(number, N);
        for (int i = 1; i < N; i++) {
            Input(&number);
            tree = FillTree(number, tree);
            tree->color = Black;
        }
        printf("%d", BlackHeight(tree));
        Freeloc(tree, N);
    }
    else {
        printf("0");
    }
    return EXIT_SUCCESS;
}

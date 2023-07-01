#include <stdlib.h>
#include <stdio.h>

#include "Tree.h"
#include "Alloc.h"
#include "AddValue.h"
#include "Height.h"
#include "Input.h"

int main(void) {
    int N, number;
    Input(&N);

    TAVLTree* tree = Alloc(N, NULL);

    for (int i = 0; i < N; i++) {
        Input(&number);
        tree = AddValue(tree, number);
    }
    printf("%d", GetHeight(tree));
    Freeloc(tree, N);

    return EXIT_SUCCESS;
}

#include <stdlib.h>

#include "Tree.h"
#include "Alloc.h"

TAVLTree* carriage = NULL;

TAVLTree* Createloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    return calloc(size, sizeof(TAVLTree));
}

TAVLTree* Alloc(int N, TAVLTree* tree) {
    if (N != 0) {
        carriage = Createloc(N);
        return carriage;
    }
    if (tree != carriage) {
        carriage++;
    }
    TAVLTree* ptr = carriage;
    return ptr;
}

void Freeloc(TAVLTree* tree, int N) {
    tree = calloc(N, sizeof(TAVLTree));
    free(tree);
}

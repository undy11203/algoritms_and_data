#include <stdlib.h>

#include "Tree.h"
#include "Alloc.h"

TTree* carriage = NULL;

TTree* Createloc(size_t size) {
    return calloc(size, sizeof(TTree));
}

void startCarriage(TTree* tree) {
    carriage = tree;
}

TTree* Alloc() {
    carriage++;
    TTree* ptr = carriage;
    return ptr;
}

void Freeloc(TTree* tree, int N) {
    tree = calloc(N, sizeof(TTree));
    free(tree);
}

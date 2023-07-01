#include <stdlib.h>

#include "Tree.h"
#include "Height.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))

int FixHeight(TAVLTree* tree) {
    return tree ? max(GetHeight(tree->Left), GetHeight(tree->Right)) + 1 : 0;
}

int GetHeight(TAVLTree* tree) {
    return tree ? tree->Height: 0;
}

int Difference(TAVLTree* tree) {
    if (!tree) {
        return 0;
    }
    return GetHeight(tree->Left) - GetHeight(tree->Right);
}

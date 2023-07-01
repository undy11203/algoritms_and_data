#include <stdlib.h>

#include "Tree.h"
#include "CheckColor.h"

int RedNode(TTree* node) {
    if (node == NULL) {
        return 0;
    }
    return node->color == Red;
}

int BlackNode(TTree* node) {
    if (node == NULL) {
        return 1;
    }
    return node->color == Black;
}

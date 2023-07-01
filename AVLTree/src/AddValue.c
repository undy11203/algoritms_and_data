#include <stdlib.h>

#include "Tree.h"
#include "Balanced.h"
#include "Alloc.h"
#include "AddValue.h"

TAVLTree* MakeNode(int value, TAVLTree* tree) {
    TAVLTree* node = Alloc(0, tree);
    node->Value = value;
    node->Left = NULL;
    node->Right = NULL;
    node->Height = 0;
    return node;
}

TAVLTree* AddValue(TAVLTree* tree, int value) {
    if (!tree || tree->Height == 0) {
        TAVLTree* node = MakeNode(value, tree);
        node->Height++;
        return node;
    }

    if (value <= tree->Value) {
        tree->Left = AddValue(tree->Left, value);
    }
    else {
        tree->Right = AddValue(tree->Right, value);
    }
    return Balance(tree);
}

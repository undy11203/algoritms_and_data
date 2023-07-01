#include <stdlib.h>

#include "Tree.h"
#include "Balanced.h"
#include "CheckColor.h"

TTree* RightRotate(TTree* tree) {
    TTree* tmp = tree->Left;
    tree->Left = tmp->Right;
    tmp->Right = tree;
    tmp->color = tree->color;
    tree->color = Red;
    return tmp;
}

TTree* LeftRotate(TTree* tree) {
    TTree* tmp = tree->Right;
    tree->Right = tmp->Left;
    tmp->Left = tree;
    tmp->color = tree->color;
    tree->color = Red;
    return tmp;
}
TTree* SwapColor(TTree* tree) {
    tree->color = tree->color ^ 1;
    tree->Left->color = tree->Left->color ^ 1;
    tree->Right->color = tree->Right->color ^ 1;
    return tree;
}

TTree* Balanced(TTree* tree) {
    if (RedNode(tree->Right)) {
        if (RedNode(tree->Left)) {
            if (RedNode(tree->Right->Right) || RedNode(tree->Right->Left)) {
                tree = SwapColor(tree);
            }
        }
        else {
            if (RedNode(tree->Right->Right)) {
                tree = LeftRotate(tree);
            }
            else if (RedNode(tree->Right->Left)) {
                tree->Right = RightRotate(tree->Right);
                tree = LeftRotate(tree);
            }
        }
    }
    if (RedNode(tree->Left)) {
        if (RedNode(tree->Right)) {
            if (RedNode(tree->Left->Left) || RedNode(tree->Left->Right)) {
                tree = SwapColor(tree);
            }
        }
        else {
            if (RedNode(tree->Left->Left)) {
                tree = RightRotate(tree);
            }
            else if (RedNode(tree->Left->Right)) {
                tree->Left = LeftRotate(tree->Left);
                tree = RightRotate(tree);
            }
        }
    }
    return tree;
}

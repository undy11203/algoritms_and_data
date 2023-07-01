#include <stdlib.h>

#include "Tree.h"
#include "Height.h"
#include "Balanced.h"

TAVLTree* LeftSmallRotate(TAVLTree* tree) {     
    if (tree) {
        TAVLTree* a = tree;
        TAVLTree* b = tree->Right;
        if (b == NULL) {
            return tree;
        }
        a->Right = b->Left;
        b->Left = a;
        a->Height = FixHeight(a);
        b->Height = FixHeight(b);
        tree = b;
    }
    return tree;
}

TAVLTree* RightSmallRotate(TAVLTree* tree) {    
    if (tree) {
        TAVLTree* b = tree;
        TAVLTree* a = b->Left;
        if (a == NULL) {
            return tree;
        }
        b->Left = a->Right;
        a->Right = b;
        b->Height = FixHeight(b);
        a->Height = FixHeight(a);
        tree = a;
    }
    return tree;
}

TAVLTree* LeftBigRotate(TAVLTree* tree) {
    if (tree) {
        tree->Right = RightSmallRotate(tree->Right);
        return LeftSmallRotate(tree);
    }
    return NULL;
}

TAVLTree* RightBigRotate(TAVLTree* tree) {
    if (tree) {
        tree->Left = LeftSmallRotate(tree->Left);
        return RightSmallRotate(tree);
    }
    return NULL;
}

TAVLTree* Balance(TAVLTree* tree) {
    if (!tree) {
        return NULL;
    }
    int difference = Difference(tree);
    if (difference == -2) {
        if (Difference(tree->Right) > 0) {
            tree = LeftBigRotate(tree);
        }
        else {
            tree = LeftSmallRotate(tree);
        }
    }
    else if (difference == 2) {
        if (Difference(tree->Left) < 0) {
            tree = RightBigRotate(tree);
        }
        else {
            tree = RightSmallRotate(tree);
        }
    }
    tree->Height = FixHeight(tree);
    return tree;
}

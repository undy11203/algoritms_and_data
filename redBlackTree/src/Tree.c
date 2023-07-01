#include <stdlib.h>

#include "Tree.h"
#include "Alloc.h"
#include "Balanced.h"

TTree* CreateRoot(int number, int size) {
    TTree* root = Createloc(size);
    startCarriage(root);
    root->color = Black;
    root->Number = number;
    root->Left = NULL;
    root->Right = NULL;
    return root;
}

void AddNode(TTree* tree, Place place, int number) {
    TTree* ptr;
    if (place == Right) {
        tree->Right = Alloc();
        ptr = tree->Right;
    }
    else {
        tree->Left = Alloc();
        ptr = tree->Left;
    }
    ptr->Number = number;
    ptr->color = Red;
    ptr->Left = NULL;
    ptr->Right = NULL;
}

TTree* FillTree(int number, TTree* tree) {
    if (number >= tree->Number) {
        if (tree->Right) {
            tree->Right = FillTree(number, tree->Right);
            tree = Balanced(tree);
        }
        else {
            AddNode(tree, Right, number);
            tree = Balanced(tree);
        }
    }
    else {
        if (tree->Left) {
            tree->Left = FillTree(number, tree->Left);
            tree = Balanced(tree);
        }
        else {
            AddNode(tree, Left, number);
            tree = Balanced(tree);
        }
    }
    return tree;
}

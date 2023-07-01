#ifndef TREE
#define TREE

typedef struct TAVLTree TAVLTree;
struct TAVLTree {
    int Height;
    int Value;
    struct TAVLTree* Left;
    struct TAVLTree* Right;
};

#endif

#ifndef TREE
#define TREE

typedef enum {
    Right,
    Left
} Place;

typedef enum {
    Black,
    Red
} Color;

typedef struct TTree {
    int Number;
    Color color;
    struct TTree* Left;
    struct TTree* Right;
} TTree;

TTree* CreateRoot(int number, int size);

void AddNode(TTree* tree, Place place, int number);

TTree* FillTree(int number, TTree* tree);

#endif

#ifndef TREE
#define TREE

typedef unsigned char uchar;

typedef struct TTree TTree;
struct TTree {
    uchar c;
    int frequency;
    TTree* left;
    TTree* right;
};

typedef struct TList TList;
struct TList {
    TTree* node;
    TList* prev;
    TList* next;
};

TTree* CreateNode(uchar symbol, int freq);

TList* AddNodeToList(uchar symbol, int freq, TList* list);

#endif

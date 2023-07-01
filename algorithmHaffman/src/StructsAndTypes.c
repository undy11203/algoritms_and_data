#include <stdlib.h>
#include <stdio.h>

#include "StructsAndTypes.h"

TTree* CreateNode(uchar symbol, int freq) {
    TTree* ptr = calloc(1, sizeof(TTree));
    ptr->c = symbol;
    ptr->frequency = freq;
    return ptr;
}

TList* AddNodeToList(uchar symbol, int freq, TList* list) {
    TTree* node = CreateNode(symbol, freq);
    if (!list) {
        list = calloc(1, sizeof(TList));
        list->node = node;
        return list;
    }
    TList* newList = calloc(1, sizeof(TList));
    newList->next = list;
    newList->node = node;
    list->prev = newList;
    return newList;
}

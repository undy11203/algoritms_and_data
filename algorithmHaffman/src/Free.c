#include <stdlib.h>
#include <stdio.h>

#include "StructsAndTypes.h"
#include "Free.h"

void FreeHuffmanTable(uchar** table) {
    for (int i = 0; i < 256; i++) {
        if (table[i]) {
            free(table[i]);
        }
    }
    free(table);
}

void FreeTree(TTree* tree) {
    if (tree->left || tree->right) {
        FreeTree(tree->left);
        FreeTree(tree->right);
        free(tree);
    }
    else {
        free(tree);
    }
}

void FreeAll(int* frequency, uchar* code, uchar** huffmanTable, TTree* root) {
    if (frequency) {
        free(frequency);
    }
    if (code) {
        free(code);
    }
    if (huffmanTable) {
        FreeHuffmanTable(huffmanTable);
    }
    if (root) {
        FreeTree(root);
    }
}

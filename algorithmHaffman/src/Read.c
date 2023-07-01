#include <stdio.h>
#include <stdlib.h>

#include "StructsAndTypes.h"
#include "Read.h"

uchar ReadBit(uchar* bit, uchar* byte, FILE* in) {
    if (*bit == 0) {
        if (!fread(byte, sizeof(uchar), 1, in)) { return 255; }
    }
    uchar res = ((*byte) & 1 << (7 - (*bit))) ? 1 : 0;
    *bit = ((*bit) + 1) % 8;
    return res;
}

uchar ReadByte(uchar* bit, uchar* byte, FILE* in) {
    uchar symbol = 0;
    for (int i = 0; i < 8; i++) {
        symbol = symbol | ReadBit(bit, byte, in) << (7 - i);
    }
    return symbol;
}

void ReadHeader(int* sizeMessage, FILE* in) {
    if (!fread(sizeMessage, sizeof(int), 1, in)) { return; }
}

TTree* ReadTree(TTree* node, uchar* bit, uchar* byte, FILE* in) {
    uchar shift = ReadBit(bit, byte, in);
    if (!shift) {
        node->left = calloc(1, sizeof(TTree));
        node->left = ReadTree(node->left, bit, byte, in);
        node->right = calloc(1, sizeof(TTree));
        node->right = ReadTree(node->right, bit, byte, in);
    }
    else {
        node->c = ReadByte(bit, byte, in);
    }

    return node;
}

uchar ReadSymbol(TTree* root, int* sizeMessage, uchar* bit, uchar* byte, FILE* in) {
    while (root->left && root->right) {
        uchar shift;
        if ((shift = ReadBit(bit, byte, in)) != 255) {
            if (shift) {
                root = root->right;
            }
            else {
                root = root->left;
            }
            if (root->c) {
                break;
            }
        }
        else {
            break;
        }
    }
    (*sizeMessage)--;
    return root->c;
}

void ReadMessage(TTree* root, int* sizeMessage, uchar* bit, uchar* byte, FILE* in, FILE* out) {
    while (*sizeMessage) {
        uchar symbol = ReadSymbol(root, sizeMessage, bit, byte, in);
        fputc(symbol, out);
    }
}

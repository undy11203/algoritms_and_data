#include <stdio.h>

#include "StructsAndTypes.h"
#include "Write.h"

void WriteBit(uchar bit, uchar* bitpos, uchar* byte, FILE* out) {
    if (*bitpos == 8) {
        fwrite(byte, sizeof(uchar), 1, out);
        *byte = 0;
        *bitpos = 0;
    }
    *byte = (*byte) | bit << (7 - (*bitpos));
    (*bitpos)++;
}

void WriteByte(uchar symbol, uchar* bitpos, uchar* byte, FILE* out) {
    for (int i = 0; i < 8; i++) {
        uchar bit = (symbol & 1 << (7 - i)) ? 1 : 0;
        WriteBit(bit, bitpos, byte, out);
    }
}

void WriteHeader(int sizeMessage, FILE* out) {
    fwrite(&sizeMessage, sizeof(int), 1, out);
}

void WriteTree(TTree* node, FILE* out, uchar* bitpos, uchar* byte) {
    if (node) {
        if (node->left || node->right) {
            WriteBit(0, bitpos, byte, out);
            WriteTree(node->left, out, bitpos, byte);
            WriteTree(node->right, out, bitpos, byte);
        }
        else {
            WriteBit(1, bitpos, byte, out);
            WriteByte(node->c, bitpos, byte, out);
        }
    }
}

void WriteMessage(FILE* in, FILE* out, uchar** HuffmanTable, uchar* bitpos, uchar* byte, int sizeMessage) {
    for (int j = 0; j < sizeMessage; j++) {
        uchar c = (uchar)fgetc(in);
        uchar* symbol = HuffmanTable[c];
        for (int i = 0; symbol[i] != '\0'; i++) {
            WriteBit(symbol[i] - '0', bitpos, byte, out);
        }
    }
    if (bitpos != 0) {
        fwrite(byte, sizeof(uchar), 1, out);
    }
}

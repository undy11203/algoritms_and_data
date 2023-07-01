#include <stdlib.h>
#include <stdio.h>

#include "StructsAndTypes.h"
#include "Read.h"
#include "Free.h"
#include "Decode.h"

void Decode(FILE* in, FILE* out) {
    int sizeMessage = 0;
    TTree* root = calloc(1, sizeof(TTree));
    uchar bit = 0;
    uchar byte = 0;
    ReadHeader(&sizeMessage, in);
    if (!sizeMessage) {
        free(root);
        return;
    }
    root = ReadTree(root, &bit, &byte, in);
    ReadMessage(root, &sizeMessage, &bit, &byte, in, out);
    FreeTree(root);
}

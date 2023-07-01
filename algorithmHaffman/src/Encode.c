#include <stdlib.h>
#include <stdio.h>

#include "StructsAndTypes.h"
#include "Write.h"
#include "Free.h"

#include "Encode.h"

TList* FindMin(TList** node) {
    TList* minimum = *node;
    TList* curNode = *node;
    while (curNode) {
        if (minimum->node->frequency > curNode->node->frequency) {
            minimum = curNode;
        }
        curNode = curNode->next;
    }
    TList* prev = minimum->prev;
    TList* next = minimum->next;
    if (minimum == *node) {
        *node = (*node)->next;
    }
    if (prev) {
        prev->next = next;
    }
    if (next) {
        next->prev = prev;
    }
    return minimum;
}

TTree* CreateTree(int frequency[256]) {
    TList* list = NULL;
    for (int i = 0; i < 256; i++) {
        if (frequency[i]) {
            uchar symbol = (uchar)i;
            list = AddNodeToList(symbol, frequency[i], list);
        }
    }
    while (list->next) {
        TList* minimum = FindMin(&list);
        TList* minimum1 = FindMin(&list);
        TList* newNode = calloc(1, sizeof(TList));
        newNode->node = calloc(1, sizeof(TTree));
        newNode->node->frequency = minimum->node->frequency + minimum1->node->frequency;
        if (minimum->node->frequency < minimum1->node->frequency) {
            newNode->node->left = minimum1->node;
            newNode->node->right = minimum->node;
        }
        else {
            newNode->node->left = minimum->node;
            newNode->node->right = minimum1->node;
        }
        free(minimum); free(minimum1);
        if (list) {
            newNode->next = list;
            list->prev = newNode;
        }
        list = newNode;
    }
    TTree* node = list->node;
    free(list);
    return node;
}

uchar** CreateTable(uchar* code, uchar** table, TTree* root, int level, int* treeSize) {
    (*treeSize)++;
    if (root->left || root->right) {
        code[level] = '0';
        CreateTable(code, table, root->left, level + 1, treeSize);
        code[level] = '1';
        CreateTable(code, table, root->right, level + 1, treeSize);
    }
    else {
        table[root->c] = calloc(level + 1, sizeof(uchar));
        for (int i = 0; i < level; i++) {
            table[root->c][i] = code[i];
        }
        table[root->c][level] = '\0';
    }
    return table;
}

void Encode(FILE* in, FILE* out) {
    int treeSize = 0;
    int sizeMessage = 0;

    uchar symbol = 0;
    int* frequency = calloc(256, sizeof(int));

    while ((fread(&symbol, sizeof(uchar), 1, in)) != 0) {
        sizeMessage++;
        frequency[symbol]++;
    }

    if (!sizeMessage) {
        FreeAll(frequency, NULL, NULL, NULL);
        return;
    }
    fseek(in, 1, SEEK_SET);
    TTree* root = CreateTree(frequency);

    uchar** HuffmanTable = (uchar**)calloc(256, sizeof(uchar*));
    uchar* code = (uchar*)calloc(256, sizeof(uchar));
    HuffmanTable = CreateTable(code, HuffmanTable, root, 0, &treeSize);

    uchar bitpos = 0;
    uchar byte = 0;
    WriteHeader(sizeMessage, out);
    WriteTree(root, out, &bitpos, &byte);
    WriteMessage(in, out, HuffmanTable, &bitpos, &byte, sizeMessage);

    FreeAll(frequency, code, HuffmanTable, root);
}

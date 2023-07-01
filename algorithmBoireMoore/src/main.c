#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "algoritmBoyerMyr.h"

int main(void) {
    char template[16];
    int templateLen = 0;
    int ch;
    int table[256];

    ch = getchar();
    while (ch != EOF && ch != 10) {
        template[templateLen] = (char)ch;
        ch = getchar();
        ++templateLen;
    }

    SetTable(table, templateLen, template);
    AlgoritmBoyerMyrMyr(template, table, templateLen);

    return EXIT_SUCCESS;
}

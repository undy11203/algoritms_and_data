#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "algoritmBoyerMyr.h"

void AlgoritmBoyerMyrMyr(char* tmp, int* table, int templateLen) {
    int next = 1;
    int count = 0;
    int protocol = templateLen;
    int start = 0;
    int isTrue = 0;
    char str[16];
    int sdvig;
    int ch;
    while (next != 0) {
        if (start != 0) {
            sdvig = templateLen - start;
            for (int m = 0 - start; m < templateLen; ++m) {
                if (m >= 0) {
                    str[m] = str[m + sdvig];
                }
            }
        }
        for (int i = start; i < templateLen; ++i) {
            ch = getc(stdin);
            if (ch == EOF) {
                next = 0;
            }
            str[i] = (char)ch;
        }
        if (next != 0) {
            for (int j = templateLen - 1; j >= 0; --j) {
                if (tmp[j] == str[j]) {
                    if (count >= 0) {
                        printf("%d ", j + protocol - templateLen + 1);
                    }
                    count += 1;
                    isTrue = 1;
                }else {
                    printf("%d ", j + protocol - templateLen + 1);
                    isTrue = 0;
                    if (count == 0) {
                        start = templateLen - table[(int)str[j]];
                        protocol += table[(int)str[j]];
                    }else if (count == templateLen - 1) {
                        start = 0;
                        protocol += templateLen;
                    }else {
                        start = 1;
                        protocol += table[(int)tmp[0]];
                    }
                    break;
                }
            }
            if (isTrue > 0) {
                protocol += templateLen;
            }
            count = 0;
        }else {
            break;
        }
    }
}

void SetTable(int* table, int templateLen, char* tmp) {
    for (int i = 0; i < 256; i++) {
        table[i] = templateLen;
    }
    for (int i = 0; i <= templateLen - 2; i++) {
        table[(int)tmp[i]] = templateLen - 1 - i;
    }
}

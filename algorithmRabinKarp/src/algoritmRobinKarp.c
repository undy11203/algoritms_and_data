#include <stdio.h>

#include "algoritmRobinKarp.h"

int Binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;

    }
    return res;
}

int GetHash(unsigned char* str, int strLen) {
    int hashSum = 0;
    for (int i = strLen - 1; i >= 0; --i) {
        hashSum += str[i] % 3;
        hashSum *= 3;
    }
    hashSum /= 3;
    return hashSum;
}

int GetMoveHash(int hash, unsigned char* array, unsigned char firstSymbol, unsigned char newSymbol, int patternLen) {
    for (int i = 0; i < patternLen - 1; i++) {
        array[i] = array[i + 1];
    }
    array[patternLen - 1] = newSymbol;
    hash -= firstSymbol % 3;
    hash /= 3;
    hash += newSymbol % 3 * Binpow(3, patternLen - 1);
    return hash;
}

void AlgoritmRobinKarp(int hashPattern, int hashText, unsigned char* text, unsigned char* pattern, int patternLen) {
    int symbol = 0;
    int numberSymbol = patternLen;
    while (1) {
        if (hashPattern == hashText) {
            for (int i = 0; i < patternLen; i++) {
                printf("%d ", numberSymbol - patternLen + i + 1);
                if (text[i] == pattern[i]) {
                    continue;
                }else {
                    break;
                }
            }
        }
        if ((symbol = getc(stdin)) != EOF) {
            numberSymbol++;
            hashText = GetMoveHash(hashText, text, text[0], (unsigned char)symbol, patternLen);
        }else {
            break;
        }
    }
}

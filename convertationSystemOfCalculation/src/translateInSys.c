#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "translateInSys.h"

void Reverse(int* arr, int len) {
    int i;
    int j;
    i = 0;
    j = len - 1;
    while (i < j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++; j--;
    }
}

void TranslateToB2(double x10, int b2, int* resultPrevDot, int* resultNextDot, int* countPrevDot, int* countNextDot) {
    long long x10PrevDot = (long long)x10;
    double x10NextDot = x10 - (long long)x10;
    const int maxCountAfterDot = 11;

    int i = 0;
    int j = 0;

    while (x10PrevDot >= b2) {
        resultPrevDot[i] = x10PrevDot % b2;
        x10PrevDot = x10PrevDot / b2;
        i++;
    }
    resultPrevDot[i] = x10PrevDot % b2;
    while (x10NextDot - (int)x10NextDot != 0) {
        resultNextDot[j] = (int)(x10NextDot * b2);
        x10NextDot = x10NextDot * b2 - (int)(x10NextDot * b2);
        if (j > maxCountAfterDot) {
            break;
        }
        j++;
    }
    Reverse(resultPrevDot, i + 1);
    *countPrevDot = i + 1;
    *countNextDot = j;
}

double TranslateToTen(char* x, int sizeX, int b1) {
    double xToTen = 0;

    int digit = sizeX - 2;
    int digitNextDot = -1;
    int nextDot = 0;
    for (int i = 0; i < sizeX; i++) {
        if (x[i] != '.') {
            char lowerSymbol = (char)tolower(x[i]);
            if (lowerSymbol >= 'a' && lowerSymbol <= 'f') {
                xToTen += ((int)lowerSymbol - 87) * pow(b1, digit);
                digit -= 1;
            }
            else {
                xToTen += (x[i] - '0') * pow(b1, digit);
                digit -= 1;
            }
        }
        if (x[i] == '.') {
            nextDot = 1;
        }
        if (nextDot == 1) {
            digitNextDot++;
        }

    }
    xToTen = xToTen / (pow(b1, digitNextDot));
    return xToTen;
}

int CheckCorrectSys(int b1, int b2) {
    if (b1 < 2 || b1>16 || b2 < 2 || b2>16) {
        return 1;
    }
    return 0;
}

int CheckCorrentInputNumber(char* x, int sizeX) {
    int isDot = 0;

    for (int i = 0; i < sizeX; i++) {
        char lowerSymbol = (char)tolower(x[i]);

        if (x[i] == '.') {
            isDot += 1;
        }
        if (x[sizeX - 1] == '.' || x[0] == '.') {
            return 1;
        }
        else if (isDot > 1) {
            return 1;
        }
        else if ((lowerSymbol >= 'a' && lowerSymbol <= 'f') || (lowerSymbol >= '0' && lowerSymbol <= '9') || lowerSymbol == '.') {
            continue;
        }
        else {
            return 1;
        }
    }
    return 0;
}

int CheckCorrectNumberInSys(char* x, int b1, int sizeX) {
    for (int i = 0; i < sizeX; i++) {
        if (x[i] != '.') {
            char lowerSymbol = (char)tolower(x[i]);
            if (lowerSymbol >= 'a' && lowerSymbol <= 'f') {
                int digit = (int)lowerSymbol - 87;
                if (digit > (b1 - 1)) {
                    return 1;
                }
            }
            else {
                int digit = x[i] - '0';
                if (digit > (b1 - 1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

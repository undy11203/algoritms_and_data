#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "translateInSys.h"

void Output(int countPrevDot, int countNextDot, int* resultPrevDot, int* resultNextDot) {
    for (int i = 0; i < countPrevDot; i++) {
        if (resultPrevDot[i] < 10) {
            printf("%d", resultPrevDot[i]);
        }
        else {
            printf("%c", (char)(resultPrevDot[i] + 87));
        }
    }
    if (countNextDot != 0) {
        printf("%c", '.');
        for (int i = 0; i < countNextDot; i++) {
            if (resultNextDot[i] < 10) {
                printf("%d", resultNextDot[i]);
            }
            else {
                printf("%c", (char)(resultNextDot[i] + 87));
            }
        }
    }
}

int main(void) {
    int b1;
    int b2;
    char xb1[14];
    int sizeX = 0;
    double x10 = 0;
    int countPrevDot = 0;
    int countNextDot = 0;

    if (scanf("%d %d", &b1, &b2) == -1 || scanf("%13s", xb1) == -1) {
        printf("%s", "bad input\n");
    }

    sizeX = (int)strlen(xb1);

    if (CheckCorrectSys(b1, b2)) {
        printf("bad input");
        return 0;
    }
    if (CheckCorrentInputNumber(xb1, sizeX)) {
        printf("bad input");
        return 0;
    }
    if (CheckCorrectNumberInSys(xb1, b1, sizeX)) {
        printf("bad input");
        return 0;
    }
    x10 = TranslateToTen(xb1, sizeX, b1);

    int resultPrevDot[50];
    int resultNextDot[50];
    TranslateToB2(x10, b2, resultPrevDot, resultNextDot, &countPrevDot, &countNextDot);

    Output(countPrevDot, countNextDot, resultPrevDot, resultNextDot);

    return EXIT_SUCCESS;
}

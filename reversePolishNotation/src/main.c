#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "Input.h"
#include "CalcWithRPN.h"

int main(void) {
    char input[1001];
    int len = 0;

    int correctInput = Input(input, &len);

    if (correctInput == 0) {
        printf("%d", CalcWithRPN(input, &len));
    }

    return EXIT_SUCCESS;
}

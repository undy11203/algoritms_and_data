#include <stdio.h>

#include "Input.h"

void Input(int* number) {
	if (scanf("%d", number) == -1) {
		printf("Bad input");
	}
}

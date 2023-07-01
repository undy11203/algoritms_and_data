#include <stdlib.h>
#include <stdio.h>

#include "Eval.h"
#include "Stack.h"

int Eval(char operation, int first, int second) {
	if (operation == '+') {
		return first + second;
	}else if (operation == '-') {
		return second - first;
	}
	else if (operation == '/' && first != 0) {
		return second / first;
	}
	else if (operation == '*') {
		return first * second;
	}
	else {
		printf("division by zero");
		return -1;
	}
}

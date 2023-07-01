
#include "Priority.h"

int Priority(char a) {
	if (a == '(') {
		return 0;
	}
	if (a == ')') {
		return 1;
	}
	if (a == '+' || a == '-') {
		return 2;
	}
	if (a == '*' || a == '/') {
		return 3;
	}
	return -1;
}

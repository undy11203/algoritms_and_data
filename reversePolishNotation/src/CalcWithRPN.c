#include <string.h>

#include "CalcWithRPN.h"
#include "Stack.h"
#include "Priority.h"
#include "Eval.h"

int CalcWithRPN(char array[], int* lenArr) {
	StackOperators* op = NULL;
	StackInt* stack = NULL;
	int number = 0;

	for (int i = 0; i < *lenArr; i++) {
		if (array[i] >= '0' && array[i] <= '9') {
			if (number != 0) {
				number = number * 10 + (array[i] - '0');
			}
			else {
				number += (array[i] - '0');
			}
		}
		else {
			if (number != 0) {
				PushInt(&stack, number);
				number = 0;
			}
			if (array[i] == '(') {
				Push(&op, '(');
			}
			if (array[i] == '+' || array[i] == '-' || array[i] == '*' || array[i] == '/') {
				while (op != NULL && Priority(array[i]) <= Priority(op->value)) {
					int first = DelInt(&stack);
					int second = DelInt(&stack);
					PushInt(&stack, Eval(Del(&op), first, second));
				}
				Push(&op, array[i]);
			}
			if (array[i] == ')') {
				while (op->value != '(') {
					int first = DelInt(&stack);
					int second = DelInt(&stack);
					PushInt(&stack, Eval(Del(&op), first, second));
				}
				Del(&op);
			}
		}
	}
	if (number != 0) {
		PushInt(&stack, number);
		number = 0;
	}
	while (op != NULL ) {
		int first = DelInt(&stack);
		int second = DelInt(&stack);
		PushInt(&stack, Eval(Del(&op), first, second));
	}
	int result = stack->value;
	DelInt(&stack);
	return result;
}

#include <stdlib.h>
#include <stdio.h>

#include "Input.h"
#include "Stack.h"

int IsCorrectInput(char array[], int len) {
	int bracket = 0;
	for (int i = 0; i < len; i++) {
		if (array[i] == '(') {
			bracket++;
		}
		else if (array[i] == ')') {
			bracket--;
		}
		if (bracket < 0) {
			printf("syntax error");
			return -1;
		}
		if (!(array[i] >= '(' && array[i] <= '9' && array[i] != '.' && array[i] != ',')) {//недопустимые знаки
			printf("syntax error");
			return -1;
		}
		if (array[i] == '0' && array[i - 1] == '/') {//деление на ноль
			printf("division by zero");
			return -1;
		}
		if (i > 0 && (array[i - 1] >= '*' && array[i - 1] <= '/') && (array[i] >= ')' && array[i] <= '/')) {//недопустимо два знака рядом
			printf("syntax error");
			return -1;
		}
		if (i > 0 && array[i] == '(' && array[i - 1] >= '0' && array[i - 1] <= '9') {//недопустимо скобка и цифра рядом1
			printf("syntax error");
			return -1;
		}
		if (i > 0 && array[i - 1] == ')' && array[i] >= '0' && array[i] <= '9') {//недопустимо скобка и цифра рядом2
			printf("syntax error");
			return -1;
		}
		if (i > 0 && array[i] == ')' && array[i - 1] == '(') {
			printf("syntax error");
			return -1;
		}
		if (i > 0 && array[i] == '(' && array[i - 1] == ')') {
			printf("syntax error");
			return -1;
		}
	}
	if (bracket != 0) {//разное количество скобок
		printf("syntax error");
		return -1;
	}
	if (!((len-1 > 0) && ((array[len - 1] >= '0' && array[len - 1] <= '9') || array[len - 1] == ')'))) {
		printf("syntax error");
		return -1;
	}
	return 0;
}

int Input(char array[], int* len) {
	int ch;
	int i = 0;
	while ((ch = getc(stdin)) != EOF && ch != '\n') {
		array[i] = (char)ch;
		i++;
	}
	*len = i;
	return IsCorrectInput(array, i);
}

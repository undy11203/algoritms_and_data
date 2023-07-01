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
		if (!(array[i] >= '(' && array[i] <= '9' && array[i] != '.' && array[i] != ',')) {//������������ �����
			printf("syntax error");
			return -1;
		}
		if (array[i] == '0' && array[i - 1] == '/') {//������� �� ����
			printf("division by zero");
			return -1;
		}
		if (i > 0 && (array[i - 1] >= '*' && array[i - 1] <= '/') && (array[i] >= ')' && array[i] <= '/')) {//����������� ��� ����� �����
			printf("syntax error");
			return -1;
		}
		if (i > 0 && array[i] == '(' && array[i - 1] >= '0' && array[i - 1] <= '9') {//����������� ������ � ����� �����1
			printf("syntax error");
			return -1;
		}
		if (i > 0 && array[i - 1] == ')' && array[i] >= '0' && array[i] <= '9') {//����������� ������ � ����� �����2
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
	if (bracket != 0) {//������ ���������� ������
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

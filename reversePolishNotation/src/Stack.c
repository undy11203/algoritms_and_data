#include <stdlib.h>
#include <stdio.h>

#include "Stack.h"
#include "Priority.h"

//+-/ * => *+-/
void Push(StackOperators** stack, char data) {
	StackOperators* ptr = malloc(sizeof(StackOperators));
	ptr->value = data;
	ptr->next = *stack;
	*stack = ptr;
}

//*+-/ => +-/ *
char Del(StackOperators** stack) {
	StackOperators* ptr = *stack;
	char result = ptr->value;
	*stack = ptr->next;
	free(ptr);
	return result;
}

void PushInt(StackInt** stack, int data) {
	StackInt* ptr = malloc(sizeof(StackInt));
	ptr->value = data;
	ptr->next = *stack;
	*stack = ptr;
}

//*+-/ => +-/ *
int DelInt(StackInt** stack) {
	StackInt* ptr = *stack;
	int result = ptr->value;
	*stack = ptr->next;
	free(ptr);
	return result;
}


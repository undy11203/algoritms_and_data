
typedef struct StackOperators { 
	struct StackOperators* next;
	char value; 
}StackOperators;

typedef struct StackInt {
	struct StackInt* next;
	int value;
}StackInt;

void Push(StackOperators** head, char data);

char Del(StackOperators** head);

void PushInt(StackInt** head, int data);

int DelInt(StackInt** head);


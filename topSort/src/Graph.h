
typedef struct TStack TStack;
struct TStack {
	int value;
	struct TStack* next;
};

void FreeStack(TStack* root);

int TopSort(char* adjMatrix, int maxVertics, TStack** node);

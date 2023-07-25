#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define MAX_STR 501

typedef struct HashTable HashTable;
typedef struct Candidats Candidats;
struct Candidats {
	char key[MAX_STR];
	Candidats* next;
};

struct HashTable {
	int a;
	int b;
	int candidatsCount;
	Candidats* first;
	Candidats** table;
};

int Hash(char* key, int a, int b, int size) {
	int hash = 0; int i = 0;
	while (key[i] != '\0') {
		hash += (a * key[i] + b) % 209;
		i++;
	}
	return hash % size;
}

void AddCandidats(HashTable* subTable, char key[MAX_STR]) {
	Candidats* tmp = subTable->first;
	subTable->first = malloc(sizeof(Candidats));
	strcpy(subTable->first->key, key);
	subTable->first->next = tmp;
	subTable->candidatsCount++;
}

int main() {
	int N, M;
	char key[MAX_STR];
	scanf("%d %d", &N, &M);
	HashTable* mainTable = calloc(2 * N, sizeof(HashTable));

	for (int i = 0; i < N; i++) {
		scanf("%s", key);
		int index = Hash(key, 2, 0, N);
		AddCandidats(&mainTable[index], key);
		int size = mainTable[index].candidatsCount * mainTable[index].candidatsCount;

		if (mainTable[index].table) {
			free(mainTable[index].table);
		}
		mainTable[index].table = calloc(size, sizeof(Candidats*));
		Candidats* tmp = mainTable[index].first;
		srand(time(NULL));
		int a = rand() % 1000;
		int b = rand() % 1000;
		while (tmp) {
			int subIndex = Hash(tmp->key, a, b, size);
			if (mainTable[index].table[subIndex]) {
				a = rand() % 1000;
				b = rand() % 1000;
				tmp = mainTable[index].first;
				free(mainTable[index].table);
				mainTable[index].table = calloc(size, sizeof(Candidats*));
				continue;
			}
			mainTable[index].table[subIndex] = tmp;
			tmp = tmp->next;
		}

		mainTable[index].a = a;
		mainTable[index].b = b;

	}
	for (int i = 0; i < M; i++) {
		scanf("%s", key);
		int index = Hash(key, 2, 0, N);
		if (mainTable[index].candidatsCount == 0) {
			printf("0");
			continue;
		}
		int size = mainTable[index].candidatsCount * mainTable[index].candidatsCount;

		int indexCell = Hash(key, mainTable[index].a, mainTable[index].b, size);
		int res = 1;
		if (mainTable[index].table[indexCell]) {
			res = strcmp(mainTable[index].table[indexCell]->key, key);
		}
		if (res == 0) {
			printf("1");
			continue;
		}

		printf("0");

	}

	return 0;
}
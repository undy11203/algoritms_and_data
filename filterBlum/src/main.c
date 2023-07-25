#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#define LENGTH_HASHTABLE 130000

int hash(char key[21], int koef) {
	int hash = 0;
	for (int i = 0; i < 21; i++) {
		hash = ((hash + key[i]) * (koef + 1)) % LENGTH_HASHTABLE;
	}
	return hash;
}


void insert(char* hashTable, char key[21]) {
	int hashKey[3];
	for (int i = 0; i < 3; i++) {
		hashKey[i] = hash(key, i) % LENGTH_HASHTABLE;
		hashTable[hashKey[i]] = 1;
	}
}

int contain(char* hashTable, char key[21]) {
	int hashKey[3];
	int res = 1;
	for (int i = 0; i < 3; i++) {
		hashKey[i] = hash(key, i) % LENGTH_HASHTABLE;
		if (hashTable[hashKey[i]] == 0) {
			res = 0;
		}
	}
	return res;
}

int main() {
	char* hashTableBlum = (char*)calloc(LENGTH_HASHTABLE, sizeof(char));
	int N, M;
	char key[21];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", key);
		insert(hashTableBlum, key);
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", key);
		char j = contain(hashTableBlum, key);
		printf("%d", j);
	}

	return 0;
}
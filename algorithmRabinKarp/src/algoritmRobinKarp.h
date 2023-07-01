#define ALGORITMROBINKARP_H

int Binpow(int a, int n);

int GetHash(unsigned char* str, int strLen);

int GetMoveHash(int hash, unsigned char* array, unsigned char firstSymbol, unsigned char newSymbol, int patternLen);

void AlgoritmRobinKarp(int hashPattern, int hashText, unsigned char* text, unsigned char* pattern, int patternLen);

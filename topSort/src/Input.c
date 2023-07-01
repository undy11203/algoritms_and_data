#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Input.h"

void Error(ErrorStatus status) {
	switch (status) {
	case BadNumberOfLine:
		printf("bad number of lines");
		break;
	case BadNumberOfVertics:
		printf("bad number of vertices");
		break;
	case BadNumberOfEdges:
		printf("bad number of edges");
		break;
	case BadVertix:
		printf("bad vertex");
		break;
	}
}

int CheckNumberOfVertics(int* vertics) {
	if ((*vertics) < 0 || (*vertics)>2000) {
		Error(BadNumberOfVertics);
		return 0;
	}
	return 1;
}
int CheckNumberOfEdges(int* vertics, int* edges) {
	if ((*edges)<0 || (*edges) >(*vertics) * ((*vertics) + 1) / 2) {
		Error(BadNumberOfEdges);
		return 0;
	}
	return 1;
}
int CheckVertix(int* vertix, int maxVertic) {
	if ((*vertix) < 1 || (*vertix) > maxVertic) {
		Error(BadVertix);
		return 0;
	}
	return 1;
}

int InputVerticsAndEdge(int* vertics, int* edges) {
	if (scanf("%d\n%d", vertics, edges) < 2) {
		Error(BadNumberOfLine);
		return 0;
	}
	if (CheckNumberOfEdges(vertics, edges) && CheckNumberOfVertics(vertics)) {
		return 1;
	}
	return 0;
}

int InputWay(int* vertix1, int* vertix2, int maxVertics) {
	if (scanf("%d %d", vertix1, vertix2) < 2) {
		Error(BadNumberOfLine);
		return 0;
	}
	if (CheckVertix(vertix1, maxVertics) && CheckVertix(vertix2, maxVertics)) {
		return 1;
	}
	return 0;
}

#define TRANSLATEINSYS_H

void Reverse(int* arr, int len);

void TranslateToB2(double x10, int b2, int* resultPrevDot, int* resultNextDot, int* countPrevDot, int* countNextDot);

double TranslateToTen(char* x, int sizeX, int b1);

int CheckCorrectSys(int b1, int b2);

int CheckCorrentInputNumber(char* x, int sizeX);

int CheckCorrectNumberInSys(char* x, int b1, int sizeX);


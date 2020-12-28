#include <cstdlib>
#include <iostream>
#include <time.h>
#include <math.h>


#define SIZE 5
static int a[SIZE][SIZE];


void CreateArray(int a[SIZE][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			a[i][j] = rand() % 100;
		}
	}
}


void PrintArray(int a[SIZE][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


int MatrixSum1(int m[SIZE][SIZE]) {
	int i, j, s = 0;

	for (i = 1; i < SIZE; i++) {
		for (j = 0; j < i; j++) {
			s += m[i][j];
		}
	}

	return s;
}


int main(int argc, char* argv[]) {
	int s = 0, i, t, N;
	N = atoi(argv[1]); //количество матриц N вводится в параметре командной строки
	srand(time(NULL));

	for (i = 1; i <= N; i++) {
		CreateArray(a);
		PrintArray(a);
		t = MatrixSum1(a);
		printf("\nSumm:%d\n ", t);

		if (t > s) {
		    s = t;
		}
	}

	printf("\nMaximum %d\n", s);
	system("PAUSE");

	return EXIT_SUCCESS;
}
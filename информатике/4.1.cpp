#include <cstdlib>

#include <iostream>

#include <time.h>

int main(int argc, char* argv[]) {

	int i, j, x, k, size;

	srand(time(NULL));

	int a[100];

	int b[100];

	printf("Enter size:>");

	scanf_s("%d", &size);

	for (i = 0; i < size; i++) {

		a[i] = rand() % 100; printf("%d ", a[i]);
	}

	printf("\nEnter value to destroy:>"); scanf_s("%d", &x);

	for (i = 0; i < size; i++) {

		if (a[i] == x) {

			for (j = i; j < size - 1; j++) {

				a[j] = a[j + 1];
			}

			size--; break;
		}
	}

	for (i = 0; i < size; i++) {

		printf("%d ", a[i]);
	}

	printf("\nEnter K:>"); scanf_s("%d", &k);

	for (i = 0; i < size; i++) {

		if ((i + k) < size) { b[i + k] = a[i]; }
		else { b[i + k - size] = a[i]; }
	}

	printf("Result:\n");

	for (i = 0; i < size; i++) {

		printf("%d ", b[i]);
	}

	printf("\n");

	system("PAUSE");

	return EXIT_SUCCESS;
}
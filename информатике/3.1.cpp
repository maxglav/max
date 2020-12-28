#include <cstdlib>

#include <iostream>

#include <math.h>

#define A 0.1

#define B 0.8

#define E 10e-4

int main(int argc, char* argv[]) {

	float x, k = (B - A) / 10.0, sn = 0, se = 0, t, y;

	int i, j, n = 3;

	for (x = A; x <= B; x += k) {

		sn = x; se = x;

		for (i = 1; i <= n; i++) {

			sn += pow(x, 4 * i + 1) / (4 * i + 1);
		};

		j = 1;

		do {
			t = pow(x, 4 * j + 1) / (4 * j + 1);

			j++; se += t;
		}

		while (t > E);

		y = log((1.0 + x) / (1.0 - x)) / 4.0 + atan(x) / 2.0;

		printf("x=%.2f SN=%f SE=%f Y=%f\n", x, sn, se, y);
	}

	system("PAUSE");

	return EXIT_SUCCESS;
}
#include <cstdlib>

#include <iostream>

#include <math.h>

#define E 10e-4 //точность

int main(int argc, char* argv[]) {

	int n = 1;

	double s = 0, a = 1;

	do {
		a *= 10.0 / (n + 1); //расчет следующего числа ряда по рекуррентной формуле

		s += a; n++;
	}

	while (a > E); //выход из цикла при достижении нужной точности

	printf("Суммаряда:%f\n", s);

	system("PAUSE");

	return EXIT_SUCCESS;
}
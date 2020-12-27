#include <cstdlib>

#include <iostream>

#include <math.h>

int main(int argc, char* argv[]) {

	//Объявление переменных и исходные данные

	floata1 = 100, b1 = 0.001, c1;

	doublea2 = 100, b2 = 0.001, c2;

	//Расчет значений выражения для типов floatи double

	//Вывод результата с 15 знаками после запятой

	printf(" Float: ");

	c1 = (pow(a1 + b1, 4.0) - (pow(a1, 4) + 4 * pow(a1, 3) * b1)) / (6 * a1 * a1 * b1 * b1 + 4 * a1 * b1 * b1 + pow(b1, 4));

	printf("%.15f", c1);

	printf("\nDouble: ");

	c2 = (pow(a2 + b2, 4) - (pow(a2, 4) + 4 * pow(a2, 3) * b2)) / (6 * a2 * a2 * b2 * b2 + 4 * a2 * b2 * b2 + pow(b2, 4));

	printf("%.15f", c2);

	system("PAUSE");

	return EXIT_SUCCESS;
}
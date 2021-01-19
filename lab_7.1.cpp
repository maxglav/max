#include <iostream>
using namespace std;

struct Number {
	int numerator; // числитель
	int denominator; // знаменатель
	Number(int num = 0, int denom = 1)
		: numerator(num), denominator(denom) {}
	// определяем арифметические действия дробей с целыми числами
	Number operator+ (int i)
	{
		return  Number(i * denominator + numerator, denominator);
	}

	friend Number operator +(const int i, const Number& N)
	{
		return  Number(i * N.denominator + N.numerator, N.denominator);
	}
	friend ostream& operator <<(ostream& os, const Number& N)
	{
		os << N.numerator << " / " << N.denominator;
		return os;
	}

};

int main()
{
	Number test(10, 2);
	std::cout << 2 + test;
	return 0;              // теперь все нормально!
}
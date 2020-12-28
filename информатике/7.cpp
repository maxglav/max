#include <iostream>
#include <math.h>
#include <conio.h>
#include <cstdarg>
#include <iomanip>

using namespace std;

float mpd1(float x) // functions mpd - "metod polovinnogo deleniya"
{
	return (1 / 3 + sin(3.0*0.6 * (x)));
}

float mpd2(float x)
{
	return (x - sin(x));
}

float mpd3(float x)
{
	return (x - log(x));
}

int main()
{
	float a, b, c, e;
	int i = 1, number;
	//clrscr();
	cout << "1 / 3 + sin(3.0 * (x))\n";
	cout << "Enter number: ";
	cin >> number;
	cout << "Start a=";
	cin >> a;
	cout << "End b=";
	cin >> b;
	cout << "Enter accuracy e=";
	cin >> e;
	c = (a + b) / 2;
	cout << "\nc=" << c;

	switch (number)
	{
	case 1:
		while ((fabs(b - a) > e) && (mpd1(c) != 0))
		{
			if (mpd1(a) * mpd1(c) < 0)
				b = c;
			else
				a = c;
			c = (a + b) / 2;
			cout << "c=" << c << endl;
			i++;
		}
		break;

	case 2:
		while ((fabs(b - a) > e) && (mpd2(c) != 0))
		{
			if (mpd2(a) * mpd2(c) < 0)
				b = c;
			else
				a = c;
			c = (a + b) / 2;
			cout << "c=" << c << endl;
			i++;
		}
		break;

	case 3:
		while ((fabs(b - a) > e) && (mpd3(c) != 0))
		{
			if (mpd3(a) * mpd3(c) < 0)
				b = c;
			else
				a = c;
			c = (a + b) / 2;
			cout << "c=" << c << endl;
			i++;
		}
		break;
	default: "invalid number";
	}
	cout << "\nSought number c=" << c << endl;
	cout << "it is found for i=" << i << " steps";
	//getch();
	system("pause");
}
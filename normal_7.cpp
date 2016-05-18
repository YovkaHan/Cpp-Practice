// По заданному вещественному x, вычислить корень кубический из x по следующей итерационной формуле:
                                                           //y(i+1)= 0.5*( y(i) + 3*x / ( 2*y(i2) + x / y(i) )).
#include <iostream>

float my_abs(float a)
{
	if (a < 0)
		return ((-1) * a);
	else
		return a;
}

float my_pow(float a, float b)
{
	float res = 0.0;
	if (b < 0)
	{
		res = my_pow(a, (b + 1))*(1/a);
		return res;
	}
	if (b == 0)
		return 1.0;
	if (b > 0)
	{
		res = a*my_pow(a, b - 1);
		return res;
	}
}

int main()
{
	float x = 27.0, y = x, y_ = 0.0;
	do
	{
		y_ = y;
		y = 0.5 *(y + (3 * x / (2 * y * y + x / y)));
	} while (my_abs(y - y_) >= my_pow(10, -5));
	std::cout << y << std::endl;
	system("pause");
	return 0;
}
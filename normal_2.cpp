//  	Вычисление цепной дроби
#include <iostream>               // cin, cout

float fun(int num)                // Рекурсия
{
	if (num > 1)
	{
		float  result = 1 / (1 + fun(num-1));
		return result;
	}
	else
	{
		return 1.0;
	}
}

void main()
{
	int   count = 0;
	float result = 0.0;

	std::cout << "How much? ";     // Какая "глубина" этой дроби?
	std::cin >> count;

	result = 1 + fun(count);
	std::cout << result << std::endl;

	system("pause");
}
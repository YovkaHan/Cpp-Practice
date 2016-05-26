//Описать функцию аddRightDigit(d, k), которая должна добавлять к целому положительному числу К справа цифру D
// (D — целочисленное значение в диапазоне 0-9, К — целочисленное значение, которое является одновременно входным параметром и модифицируемым значением).
//С помощью этой функции добавить к данному числу К цифры D1 и D2, выводя результат каждого добавления.
#include <iostream>

void аddRightDigit(int d, int &k);   // Добавить цифру справа

int main()
{
	int sum = 0,d = -2;

	while(1)
	{
		std::cout << "\nInput number to add [0 - 9] and input (-1) to exit: ";
		std::cin >> d;
		if (d == -1)               // Выход с цыкла
			break;
		if (d == -2)              // Если на вход поступила не число
		{
			std::cin.clear();
			std::cin.ignore();
		}
		else if (d <= 9 && d >= 0)
		{
			аddRightDigit(d, sum);
			std::cout << "\nResult : " << sum;
		}
		else
		{
			std::cout << "\nPlease input numbers in range [0 - 9]: ";
		}
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}

void аddRightDigit(int d, int &k)
{
	char str1[6], str2[3];             // Буфер 1,2 для трансформации числа в строку и обратно

	if (k == 0)                        // при первом выполнении функции
	{
		_itoa_s(d, str2, 2, 10);
		k = atoi(str2);
	}
	else
	{
		_itoa_s(k, str1, 6, 10);
		_itoa_s(d, str2, 2, 10);
		strcat_s(str1, str2);
		k = atoi(str1);
	}
}
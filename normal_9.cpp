// Генерация случайных чисел в интервале [a;b] и заполнение ими двумерный массив размером 10 на 10
#include <iostream> 
#include <locale>
#include <iomanip>
#include <time.h> 

int main()
{
	setlocale(LC_ALL, "rus");
	float a, b;
	int min[2] = {0, 0};
	float mas[10][10];
	std::cout << "Введите число а: ";
	std::cin >> a;
	std::cout << "Введите число b: ";
	std::cin >> b;
	srand(time(NULL));
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			mas[x][y] = a + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (b - a)));
			if (mas[min[0]][min[1]] > mas[x][y])
			{
				min[0] = x;
				min[1] = y;
			}
		}
	}
	std::cout << "Сгенерированный массив вещественных чисел\n";
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			std::cout << std::setw(7) << std::fixed << std::setprecision(3) << mas[x][y];
		}
		std::cout << std::endl;
	}
	std::cout << "\nНомер строки с минимальным элементом : " << min[0]+1 << std::endl;
	std::cout << "Минимальный элемент : " << mas[min[0]][min[1]] << std::endl << std::endl;
	std::cout << "\nМассив с перестановленными строками\n";
	for (int x = 0; x < 10; x++)
	{
		float buf = mas[0][x];
		mas[0][x] = mas[min[0]][x];
		mas[min[0]][x] = buf;
		for (int y = 0; y < 10; y++)
		{
			std::cout << std::setw(7) << std::fixed << std::setprecision(3) << mas[x][y];
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
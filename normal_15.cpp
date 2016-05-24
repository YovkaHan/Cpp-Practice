//    Значения с двумерного масива перенести в одномерный
//    (для удобства работал сразу с двумя массивами в одном цыкле)

#include <iostream>                // cin, cout
#include <locale>                  // setlocale
#include <iomanip>                 // setw
#include <ctime>                   // time

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL,"rus");
	int str, stl, index = 0;       // строки, столбцы и индекс для инкримента
	int **mas, *mas_s;            // указатели на двумерный и одномерный массивы

	std::cout << "Введите количество строк матрицы : ";
	std::cin >> str;
	std::cout << "Введите количество столбцов матрицы : ";
	std::cin >> stl;

	mas = new int*[str];
	for (int x = 0; x < str; x++)
	{
		mas[x] = new int[stl];
	}

	mas_s = new int[str*stl];
	for (int x = 0; x < str; x++)    // Вывод двумерного массива и заполнение одномерного
	{
		for (int y = 0; y < stl; y++)
		{
			mas[x][y] = rand() % 10;   
			std::cout << std::setw(2) << mas[x][y] << " ";
			mas_s[index] = mas[x][y];
			index++;
		}
		std::cout << "\n";
	}

	// Вывод одномерного массива
	for (int i = 0; i < index; i++)
	{
		if (i == 40)
			std::cout << std::endl;
		std::cout << mas_s[i]<<" ";
	}
	std::cout << std::endl;

	 //-- Освобождение выделеной под массивы памяти
	for (int x = 0; x < str; x++)
	{
		delete[] mas[x];
	}
	delete[] mas_s;
	 //--
	system("pause");
	return 0;
}
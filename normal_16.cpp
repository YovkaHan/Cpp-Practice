      //  Перестановка строк и столбцов для размещения максимального элемента в правый нижний угол матрицы
#include <iostream>         // cin, cout
#include <iomanip>         // setw
#include <locale>         // setlocale

int main()
{
	setlocale(LC_ALL, "rus");
	int n, max = 0, index = 0;   // размерность квадратной матрицы, индекс максимального числа в матрице, индекс
	int **mas;                   // указатель на "матрицу"
	std::cout << "Размер квадратной матрицы : ";
	std::cin >> n;
	std::cout << "Вводите элеиенты матрицы : \n";
	// Выделение памяти под (int*)[n]-масивов, выделение памяти под (каждый из них * n ) и использование в одном цикле 
	mas = new int*[n];
	for (int x = 0; x < n; x++)
	{
		mas[x] = new int[n];
		for (int y = 0; y < n; y++)
		{                                             // Ввод элементов матрици и паралельно нахождение индекса максимального элемента
			std::cin >> mas[x][y];
			if (x > 0) { if (mas[x][y] > mas[max/n][max % n]) { max = index; } }
			else { if (mas[0][y] > mas[0][max]) { max = index; } }
			index++;
		}
	}
	std::cout << "Изначальная матрица : \n";          //--Вывод результатов на данном этапе
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			std::cout << std::setw(3) << mas[x][y];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;                           //--

	int buf = 0;
	if (max / n != (n - 1))        // !(Если максимальный элемент находится в последней строке)
	{
		for (int x = 0; x < n; x++)
		{
			buf = mas[max / n][x];              // 
			mas[max / n][x] = mas[n - 1][x];    //  Свап
			mas[n - 1][x] = buf;                // 
		}
		
		std::cout << "Результат перестановки строк : \n";
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				std::cout << std::setw(3) << mas[x][y];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	if (max != (n*n) - 1)          // !(Если максимальный элемент уже в правом нижнем углу матрицы)
	{
		for (int x = 0; x < n; x++)
		{
			buf = mas[x][max%n];
			mas[x][max%n] = mas[x][n - 1];
			mas[x][n - 1] = buf;
		}
	}
	std::cout << "Результат перестановки столбцов : \n";
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			std::cout << std::setw(3) << mas[x][y];
		}
		std::cout << std::endl;
	}

	// Освобождение памяти которая была выделена под матрицу
	for (int x = 0; x < n; x++)
	{
		delete[]mas[x];
	}

	system("pause");

	return 0;
}
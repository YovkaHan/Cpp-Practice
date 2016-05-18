 // Вычислить произведение матрицы на вектор 
#include <iostream>     // cin, cout
#include <locale>       // setlocale

int max(int *vector, int num)        // Возврат индекс максимального элемента в векторе
{
	int index = 0;
	                    // Назначение первого элемента как максимального и отсчет в цикле перескакивает на 1 вперед
	for (int i = 1, max = vector[0]; i < num; i++)   
	{
		if (max < vector[i])
		{
			max = vector[i];
			index = i;
		}
	}
	return index;
};

int main()
{
	setlocale(LC_ALL, "rus");
	int	stroki = 0, stolbci = 0;

	std::cout << "Введите количество строк матрицы: ";
	std::cin >> stroki;
	std::cout << "Введите количество столбцов матрицы: ";
	std::cin >> stolbci;
	
	int	*vector     = new int[stolbci];          // Вектор(выделение памяти)
	int *vector_res = new int[stroki];           // Результирущий вектор(выделение памяти)

	//-- Матрица (выделение памяти)
	int **mas       = new int*[stroki];          
	for (int count = 0; count < stroki; count++)
		mas[count] = new int[stolbci];           
	//---
	//-- Ввод матрицы
	for(int x = 0; x < stroki; x++)         
	{ 
		for (int y = 0; y < stolbci; y++)
		{
			std::cout << "matrix["<<x+1<<"]["<<y+1<<"] = ";
			std::cin >> *((*(mas + x)) + y);   // Отталкиваеся от адреса первого элемента
		}
	}                                       
	//---
	std::cout <<"Введите элементы вектора: \n";
	for (int index = 0; index < stolbci; index++)
	{
		std::cout << "vector[" << index + 1 << "] = ";
		std::cin >> vector[index];
	}

	std::cout << "Введенная матрица: \n";
	for (int x = 0; x < stroki; x++)
	{
		int buf = 0;
		for (int y = 0; y < stolbci; y++)
		{
			buf += mas[x][y] * vector[y];     // Паралельно выводу матрицы расчитываем результирующий вектор
			std::cout << mas[x][y] << " ";
		}
		vector_res[x] = buf;
		std::cout << std::endl;
	}

	std::cout << "Введенный вектор: \n";
	for (int index = 0; index < stolbci; index++)
	{
		std::cout << vector[index] << std::endl;
	}

	std::cout << "Результирующий вектор: \n";
	for (int index = 0; index < stroki; index++)
	{
		std::cout << vector_res[index] << std::endl;
	}

	std::cout << "Максимальное значение = " << vector_res[max(vector_res, stroki)] << std::endl;

	system("pause");

	for (int count = 0; count < stroki; count++)
		delete[] * (mas + count);

	delete[] vector;
	delete[] vector_res;
	return 0;
}
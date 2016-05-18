// Динамический массив 
// Добавление целого числа в массив при каждом проходе в цикле
#include <iostream>
#include <locale>

int main()
{
	setlocale(LC_ALL, "rus");

	int count = 0,num = 0;
	int *mas = new int[count + 1];
	int *buf;

	std::cout << "Введите целое число: ";
	std::cin >> num;

	mas[count] = num;
	std::cout << mas[0];

	while (1)
	{
		count++;
		std::cout << "\nВведите целое число: ";
		std::cin >> num;

		if (num == -1)           // Выход из цикла  (ввод числа -1)
			break;

		buf = new int[count+1];      
		for (int i = 0; i < count; i++)
			buf[i] = mas[i];
		buf[count] = num;
		delete mas;                 
		mas = new int[count + 1];   
		for (int i = 0; i < count+1; i++)
		{
			mas[i] = buf[i];
			std::cout << mas[i] << " ";
		}
		delete buf;            

	}
	delete[] mas;
	system("pause");
	return 0;
}
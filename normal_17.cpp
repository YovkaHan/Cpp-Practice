// Поменять согласные буквы на гласные во введенной пользователем строке, а гласные — на соответствующий ASCII код
#include <iostream>
#include <ctime>
#include <string>

std::string func(char Alpha[])       // "Бесполезная" функция (как пример генерации символов нижнего регистра и наоборот)
{
	srand(time(NULL));
	char alpha[] = "AEUIYO";
	int n = strlen(alpha);         // Размер строки
	int index = 0;
	char * alpha_m = new char[n * 2];
	n = 0;                         // Повторно использовал как часть механизма
	while (strlen(alpha_m) > n)
	{
		alpha_m[n] = toupper(alpha[index]);  // Возвращает версию ВЕРХНЕГО регистра (alpha[index]),
											 //  если символ уже таков - ничего не изменяется
		n++;
		alpha_m[n] = tolower(alpha[index]);  // Возвращает версию НИЖНЕГО регистра (alpha[index]),
											 //  если символ уже таков - ничего не изменяется
		n++;
		index++;
	}

	index = 0;
	n = 0;
	std::string res;                                 // Часть "костыля" ниже
	while (Alpha[index] != '\0')                      // Выводим либо рандомную гласную букву из сгенерированого массива 
													//  либо код символа (если символом является гласная буква) 
	{
		if (!strchr(alpha_m, Alpha[index]))
		{
			n = rand() % strlen(alpha_m);
			res = res + " " + alpha_m[n];
		}
		else
			// Это решение для тех кто хочет результат работы запихнуть в строку
			// По скольку напрямую код символа не записать в строку прямо
			// можно использовать подобный "костыль"
		{
			int i = int(Alpha[index]);
			char s[4];
			_itoa_s(i, s, 10);
			res = res + " " + s;
		}
		index++;
	}
	return res;
}

int main()
{
	srand(time(NULL));
	char str[100] = "";
	int index = 0;
	int r = 0;
	std::cout << "Enter the string of characters: ";
	std::cin >> str;
	std::cout << std::endl << "Result: " << func(str) << std::endl;
	system("pause");
	return 0;
}
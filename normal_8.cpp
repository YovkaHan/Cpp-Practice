#include <iostream>
#include <locale>
#include <ctype.h>

int main()
{
	setlocale(LC_ALL,"rus");
	char ch[255];
	char act=' ';
	std::cout << "Введите строку \n\n";
	gets_s(ch);
	while (1)
	{
		std::cout << "Для преобразования строки в заглавные буквы нажмите : 1\n"
			<< "Для преобразования строки в нижний регистр нфжмите : 2\n"
			<< "Для преобразования строки с Заглавной Буквы нажмите : 3\n"
			<< "Для преобразования строки в первый символ в нижнем регистре нажмите : 4\n"
			<< "Для преобразования строки как в обычном предложении нажмите : 5\n"
			<< "Для выхода нажмите : f\n Введите необходимое действие : ";
		std::cin >> act;
		switch(act)
		{
		case '1':
			for (int i = 0; i < strlen(ch); i++)
				ch[i] = toupper(ch[i]);
			break;
		case '2':
			for (int i = 0; i < strlen(ch); i++)
				ch[i] = tolower(ch[i]);
			break;
		case '3':
			for (int i = 0; i < strlen(ch); i++)
			{
				if(ch[i-1]==' ' || i == 0)
					ch[i] = toupper(ch[i]);
			}
			break;
		case '4':
			for (int i = 0; i < strlen(ch); i++)
			{
				if (ch[i-1] == ' ' || i == 0)
					ch[i] = tolower(ch[i]);
				else 
					ch[i] = toupper(ch[i]);
			}
			break;
		case '5':
			for (int i = 0; i < strlen(ch); i++)
			{
				ch[i] = tolower(ch[i]);
				if (i == 0)
					ch[i] = toupper(ch[i]);
			}
			break;
		}
		std::cout << ch << std::endl;
		if (act == 'f')
			break;
	}
	system("pause");
	return 0;
}
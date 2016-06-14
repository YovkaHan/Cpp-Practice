// Динамическое выделение памяти для структур С++
#include <iostream>
#include <locale>
#include <string>

struct persona {
	std::string  name;
	int          age;
};

typedef struct persona Persona;

Persona create_persona()
{
	Persona P;

	std::cout << "Имя : ";
	std::cin >> P.name;
	std::cout << "Возраст : ";
	std::cin >> P.age;

	return P;
};

int main() {
	setlocale(LC_ALL, "rus");

	int count    = 0;             // кол-во структур
	int num      = 0;
	Persona *P_s = new Persona[count + 1];         // Начальное выделение памяти под 1 структуру

	P_s[0] = create_persona();
	Persona *buf;

	while (1)
	{
		std::cout << "Внести еще данные — 1, выход — 0: ";
		std::cin >> num;

		if (num == 0)                                       // Выход из цикла
			break;

		count++;                   
		buf = new Persona[count];
		for (int index = 0; index < count; index++)
		{
			buf[index].name = P_s[index].name;
			buf[index].age = P_s[index].age;
		}

		delete [] P_s;

		P_s = new Persona[count + 1];
		Persona P = create_persona();
		P_s[count].name = P.name;
		P_s[count].age = P.age;
		for (int index = 0; index <=count; index++)
		{
			if (index != count)
			{
				P_s[index].name = buf[index].name;
				P_s[index].age = buf[index].age;
			}
			std::cout << index << "-й" << " Элементы структуры объекта Р: " << P_s[index].name <<" : "<< P_s[index].age<< std::endl;
		}

		delete [] buf;
		
	}
	return 0;
}



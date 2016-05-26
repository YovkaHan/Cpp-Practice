// ƒан текст, который пользователь должен ввести в программу, 
// найти наибольшее количество идущих подр¤д букв
#include <iostream>
#include <string>

std::string enter_string();           // ¬вод строки пользователем
int process_data(std::string str);     // ќбработка строки и нахождение макс. количества 
                                       // подр¤д повтор¤ющихс¤ букв

int main()
{
	int answer = -1;                 // ввод меню
	int count_result = -1;           // макс. количества подр¤д повтор¤ющихс¤ букв
	std::string input_str;           // введенна¤ строка
	while (answer!=0)
	{
		answer = -1;
		std::cout << "Menu:\n"
			<< "1 - To enter the string\n"
			<< "2 - To process the data\n"
			<< "3 - To see result\n"
			<< "0 - Exit\n";
		std::cin >> answer;
		if (answer <= 3 && answer>=0)
		{
		}
		else
		{
			if (answer == -1)      // ≈сли на ввод поступила буква
			{
				std::cin.clear();
				std::cin.ignore();
			}
			std::cout << "\nPlease, input in correct form (numbers 1,2,3 or 0):\n";
			continue;
		}
		switch (answer)
		{
		case 1:
			input_str = enter_string();
			break;
		case 2:
			count_result = process_data(input_str);
			break;
		case 3:
			std::cout << "\nYour result : " << count_result;
			std::cout << std::endl;
			break;
		default:
			break;
		}

	}
	return 0;
}

std::string enter_string()
{
	std::string result;
	std::cout << "\nEnter the string :\n";
	std::cin.ignore();
	std::getline(std::cin, result);
	return result;
}

int process_data(std::string str)
{
	int count = 1, max_count = 0;
	std::cout << "\nProcessing the data..\n";
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == str[i - 1])
		{
			count++;
			if (count > max_count)
				max_count = count;
		}
		else
		{
			count = 1;
		}
	}
	return max_count;
}

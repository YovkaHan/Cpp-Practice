//Подсчитать количество повторений элементов, заданного множества символов, во введенной строке.
#include <iostream>
#include <string>
#include <map>
#include <locale>

int main()
{
	setlocale(LC_ALL, "rus");
	std::string st;
	std::map<char, int> myMap;
	std::map<char, int>::iterator it;
	std::cout << "Ввести строку : \n";
	std::getline(std::cin, st);
	for (int index = 0; index < st.length(); index++)
		myMap[st[index]]++;
	for (it = myMap.begin(); it != myMap.end(); ++it)
		std::cout << it->first << "\t" << it->second << '\n';

	system("pause");
	return 0;
}
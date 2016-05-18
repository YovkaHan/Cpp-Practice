//                   Check the balance of { and } 
#include <iostream>          // cin, cout
#include <fstream>           // File in/out
#include <string>            // Work with str  ">>", "getline()"

void main()
{
	std::string path, data;
	char        ch;
	int         rightc = 0, leftc = 0;

	std::cout << "Input the files path with its name :";
	std::cin  >> path;
	std::ifstream fin(path);

	while (std::getline(fin, data))        // Взятие строки с файлового потока вывода
	{
		for (int i = 0; i < data.length(); i++)
		{
			if (data[i] == '}')
			{
				rightc++;
			}
			else if (data[i] == '{')
			{
				leftc++;
			}
		}
	}
	fin.close();
	if (rightc == leftc)
	{
		std::cout << "\nBalance of brekets is safe";
	}
	else
	{
		std::cout << "\nBalance of brekets is not safe ";
	}
}
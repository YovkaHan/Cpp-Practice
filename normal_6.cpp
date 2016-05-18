#include <iostream>
#include <vector>

std::vector<std::vector<int>> myArray;

int main()
{
	int pp = 1;
	int dd = 0;
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		std::vector<int> myarray;
		myArray.push_back(myarray);
	}

	for (int x = 0; x < 10; x++)
	{
		for (int y = dd; y < pp; y++)
		{
			sum++;
			myArray[y].push_back(sum);
		}

		if (pp != 10)
		{
			pp++;
		}
		else
		{
			dd++;
		}

		for (int z = (pp-1); z >= dd; z--)
		{
			sum++;
			myArray[z].push_back(sum);
		}

		if (pp != 10)
		{
			pp++;
		}
		else
		{
			dd++;
		}
	}

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (myArray[x][y] < 10)
			{
				std::cout <<" "<<myArray[x][y] << " ";
			}
			else
			std::cout << myArray[x][y] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
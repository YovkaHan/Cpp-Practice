 // ��������� ������������ ������� �� ������ 
#include <iostream>     // cin, cout
#include <locale>       // setlocale

int max(int *vector, int num)        // ������� ������ ������������� �������� � �������
{
	int index = 0;
	                    // ���������� ������� �������� ��� ������������� � ������ � ����� ������������� �� 1 ������
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

	std::cout << "������� ���������� ����� �������: ";
	std::cin >> stroki;
	std::cout << "������� ���������� �������� �������: ";
	std::cin >> stolbci;
	
	int	*vector     = new int[stolbci];          // ������(��������� ������)
	int *vector_res = new int[stroki];           // ������������� ������(��������� ������)

	//-- ������� (��������� ������)
	int **mas       = new int*[stroki];          
	for (int count = 0; count < stroki; count++)
		mas[count] = new int[stolbci];           
	//---
	//-- ���� �������
	for(int x = 0; x < stroki; x++)         
	{ 
		for (int y = 0; y < stolbci; y++)
		{
			std::cout << "matrix["<<x+1<<"]["<<y+1<<"] = ";
			std::cin >> *((*(mas + x)) + y);   // ������������ �� ������ ������� ��������
		}
	}                                       
	//---
	std::cout <<"������� �������� �������: \n";
	for (int index = 0; index < stolbci; index++)
	{
		std::cout << "vector[" << index + 1 << "] = ";
		std::cin >> vector[index];
	}

	std::cout << "��������� �������: \n";
	for (int x = 0; x < stroki; x++)
	{
		int buf = 0;
		for (int y = 0; y < stolbci; y++)
		{
			buf += mas[x][y] * vector[y];     // ���������� ������ ������� ����������� �������������� ������
			std::cout << mas[x][y] << " ";
		}
		vector_res[x] = buf;
		std::cout << std::endl;
	}

	std::cout << "��������� ������: \n";
	for (int index = 0; index < stolbci; index++)
	{
		std::cout << vector[index] << std::endl;
	}

	std::cout << "�������������� ������: \n";
	for (int index = 0; index < stroki; index++)
	{
		std::cout << vector_res[index] << std::endl;
	}

	std::cout << "������������ �������� = " << vector_res[max(vector_res, stroki)] << std::endl;

	system("pause");

	for (int count = 0; count < stroki; count++)
		delete[] * (mas + count);

	delete[] vector;
	delete[] vector_res;
	return 0;
}
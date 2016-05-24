// Описать класс Работник и возможности для работы с данными этого класса
#include <iostream>
#include <string>

class Worker 
{
	std::string Surname;                 // Фамилия рабочего
	int         Exp;   // in months
	int         Per_H;                           // Зарплата $/h
	int         Hours;                           // Часов отработано 

public:
	Worker();
	Worker(std::string S, int E, int PH, int H);

	inline std::string out_Surname() { return this->Surname; }
	inline int Worker_Salary() { return this->Per_H * this->Hours; }      // Расчет зарплаты рабочего
	inline int Worker_Premium() {                         // Расчет премии рабочего
		return int(this->Worker_Salary() * ((this->Exp / 12) > 5 ? 0.15 : (this->Exp / 12) > 3 ? 0.08 : (this->Exp / 12) > 1 ? 0.05 : 0));
	}

	void out_all();              // Вывод полной инофрмации о работнике
};

Worker::Worker()
{
	std::cout << "\nEnter worker's name: ";
	std::getline(std::cin ,this->Surname);

	std::cout << "\nEnter worker's experience (in months): ";
	std::cin >> this->Exp;

	std::cout << "\nEnter worker's hourly wag: ";
	std::cin >> this->Per_H;

	std::cout << "\nEnter how much hours Denis has worked : ";
	std::cin >> this->Hours;
	std::cout << std::endl;
}

Worker::Worker(std::string S, int E, int PH, int H)
{
	this->Surname = S;
	this->Exp = E;
	this->Per_H = PH;
	this->Hours = H;
}

void Worker::out_all()                      
{
	std::cout << "Worker's surname is " << this->Surname <<".\n";
	std::cout << this->Surname << " experience = " << this->Exp << " months.\n";
	std::cout << this->Surname << " owns " << this->Per_H << "$ / hour.\n";
	std::cout << this->Surname << " has already worked " << this->Hours << " hours in this month.\n";
}

int main()
{
	Worker w;
	w.out_all();
	std::cout << w.out_Surname() << " salary is " << w.Worker_Salary() << "$ and premium is " << w.Worker_Premium() <<"$ \n";
	system("pause");
	return 0;
}
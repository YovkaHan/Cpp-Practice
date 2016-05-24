// Работа с класссом Time
#include <iostream>
#include <locale>

class Time 
{
	int seconds;
	int minutes;
	int hours;

public:
	Time()
	{
		std::cout << "Введите значения времени!\n"
				  << ">> часы: ";
		std::cin >> this->hours;
		std::cout << ">> минуты: ";
		std::cin >> this->minutes;
		std::cout << ">> секунды: ";
		std::cin >> this->seconds;
	}
	Time(int s);
	Time(int s,int m,int h);
	const Time operator+(const Time& rv) const {
		Time t;
		t.hours = this->hours + rv.hours;
		t.minutes = this->minutes + rv.minutes;
		t.seconds = this->seconds + rv.seconds;
		return t;
	}
	const Time operator-(const Time& rv) const {
		Time t(0);
		t.hours = this->hours - rv.hours;
		t.minutes = this->minutes - rv.minutes;
		t.seconds = this->seconds - rv.seconds;
		return t;
	}
	inline void out() { std::cout <<this->hours << ":" << this->minutes << ":" << this->seconds; }
	int num_of_sec();
};

Time::Time(int s, int m, int h)
{
	this->seconds = s;
	this->minutes = m;
	this->hours = h;
};
Time::Time(int s)
{
	this->hours = s / 3600;
	this->minutes = (s / 60) > 60 ? (s - hours * 3600) / 60 : s / 60;
	this->seconds = (s > 60) ? (hours > 0 ? s - (hours * 3600 + minutes * 60) : s - minutes * 60) : s;
}
int Time::num_of_sec()
{
	return (this->hours * 3600 + this->minutes * 60 + this->seconds);
}

int main()
{
	setlocale(LC_ALL, "rus");
	Time t1;
	int sec = 0;
	std::cout << "Введите количество секунд :";
	std::cin >> sec;
	Time t2(sec);
	t1 = t1 - t2;
	std::cout << "Оставшееся время : ";
	t1.out();
	std::cout << "\n";
	Time t3;
	Time t4;
	std::cout << "Количество секунд между введенными моментами времени : " << abs(t3.num_of_sec() - t4.num_of_sec()) << std::endl;
	system("pause");
	return 0;
}
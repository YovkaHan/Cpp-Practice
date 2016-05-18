  //  Программа для работы с данными структуры и с возможностью вывода/ввода данных с файла
                                 //  Сортировка только одна - стандартная (имеется алгоритм быстрой (не мой), но он не задействован)
								 //  Ввод из файла должен иметь формат {Surname;Name;Patronymic;Post;Hr_pay;Hours;
                                 //  Всё рабочее                 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

#define MAXSTACK 2048

using namespace std;

struct Worker {
	static int id_s;
	int        id;                    // id несколько не последователен 
	string     Surname;
	string     Name;
	string     Patronymic;
	string     Post;
	int        Hr_pay;
	int        Hours;
	int        Salary;
	Worker(string);
	void for_edit();
	Worker()
	{                              // По умолчанию строки "---" и "0"
		id = ++id_s;
		Surname = "---";
		Name = "---";
		Patronymic = "-----";
		Post = "---";
		Hr_pay = 0;
		Hours = 0;
		Salary = Hr_pay * Hours;
	}
	/*~Worker() {
		//id_s--;
	}*/
};
//////////////////////// Сортировки
struct sort_class_x
{
	bool operator() (Worker i, Worker j)
	{
		return (i.Salary<j.Salary);
	}
} sort_objectX;

struct rsort_class_x
{
	bool operator() (Worker i, Worker j)
	{
		return (i.Salary>j.Salary);
	}
} rsort_objectX;

int  Worker::id_s = 1;
                                          // Начальная запись в структуры данных пересылаемых в ввиде строки считаной из файла
Worker::Worker(string str)                // (не совсем красиво). Если возможно перечислять элементы структуры то будет смотрется лучше
{
	id = ++id_s;
	size_t index = str.find(";");              // индекс начала
	size_t index_b = 0;                        // буферизированы индекс начала         
						         // Последовательное изьятие данных из строки
	Surname = str.substr(index_b + 1, index-1);
	index_b = index;
	index = str.find(";", index_b+1);
	Name = str.substr(index_b + 1, index - index_b -1);
	index_b = index;
	index = str.find(";", index_b + 1);
	Patronymic = str.substr(index_b + 1, index - index_b - 1);
	index_b = index;
	index = str.find(";", index_b + 1);
	Post = str.substr(index_b + 1, index - index_b - 1);
	index_b = index;
	index = str.find(";", index_b + 1);
	Hr_pay = stoi(str.substr(index_b + 1, index - index_b - 1));
	index_b = index;
	index = str.find(";", index_b + 1);
	Hours = stoi(str.substr(index_b + 1, index - index_b - 1));
	Salary = Hr_pay * Hours;                                       // Вычисление зарплаты
};

void Worker::for_edit()                                   // Редактировать "Рабочего"
{
	Worker *buff_W = new Worker();
	cout << "( " << Surname << " - Surname )   : ";
	cin >> buff_W->Surname;
	if (buff_W->Surname == Surname || buff_W->Surname == "---");
	else
	{
		Surname = buff_W->Surname;
	}
	cout << "( " << Name << " - Name)   : ";
	cin >> buff_W->Name;
	if (buff_W->Name == Name || buff_W->Name == "---");
	else
	{
		Name = buff_W->Name;
	}
	cout << "( " << Patronymic << " - Patronymic)   : ";
	cin >> buff_W->Patronymic;
	if (buff_W->Patronymic == Patronymic || buff_W->Patronymic == "---");
	else
	{
		Patronymic = buff_W->Patronymic;
	}
	cout << "( " << Post << " - Post)   : ";
	cin >> buff_W->Post;
	if (buff_W->Post == Post || buff_W->Post == "---");
	else
	{
		Post = buff_W->Post;
	}
	cout << "( " << Hr_pay << "  - Hr.pay)   : ";
	cin >> buff_W->Hr_pay;
	if (buff_W->Hr_pay == Hr_pay || buff_W->Hr_pay == 0);
	else
	{
		if(Salary !=0)                       //  Переопределяем Salary
			Salary /= Hr_pay;
		Hr_pay = buff_W->Hr_pay;
		Salary *= Hr_pay;
	}
	cout << "( " << Hours << " - Hours)   : ";
	cin >> buff_W->Hours;
	if (buff_W->Hours == Hours || buff_W->Hours == 0);
	else
	{
		Salary /= Hours;
		Hours = buff_W->Hours;
		Salary *= Hours;
	}
	delete buff_W;
}

void out_format_data()             // Формат вывода данных про "Рабочего" (не стабилен)
{
	cout << "\n  id  |"
		"    Surname    |"
		"    Name    |"
		"  Patronymic  |"
		"    Post    |"
		"  Hr_pay  |"
		"  Hours  |"
		"  Salary  \n";
	for (int i = 0; i < 96; i++)
		putchar('-');
};

void output_w_data(Worker W)            // Вывод данных "Рабочего" (не стабилен)
{
	cout << "\n" << setw(4) << W.id << " "
		<< " " << setw(13)<< W.Surname << " "
		<< " " << setw(13) << W.Name << " "
		<< " " << setw(11) << W.Patronymic << " "
		<< " " << setw(10) << W.Post << " "
		<< " " << setw(8) << W.Hr_pay << " "
		<< " " << setw(9) << W.Hours << " "
		<< " " << setw(10) << W.Salary << "\n";
}

void save_file(string fname, vector<Worker> workers)
{
	ofstream file_w(fname, ios_base::out);
	int index = 0;
	while (index < int(workers.size()))
	{
		string str = "{" + workers[index].Surname + ";" + workers[index].Name + ";" + workers[index].Patronymic + ";" + workers[index].Post
			+ ";" + to_string(workers[index].Hr_pay) + ";" + to_string(workers[index].Hours);
		str += "\n";
		file_w << str;
		index++;
	}
	file_w.close();
}

void load_from_file(string fname, vector<Worker> *workers, Worker *w, vector<int>*id_s_mas)
{
	ifstream file_r(fname);           // Файловый вывод

	while (!file_r.eof())             // До начала работы с данными их нужно загрузить в виде элементов конструкции вектора
									  //запись в вектор .push_back происходит до конца файла или до определенного момента 
	{
		string line;                   // Строка считывания с файла
		getline(file_r, line);
		if (line[0] == '{')            // В начале каждой строки в файле "технический" символ '{'
		{
			w = new Worker(line);      // Выделяется память под новый элемент
			id_s_mas->push_back(w->id);
			workers->push_back(*w);
			delete w;                  // Удаляется указатель на участок памяти (но память должна оставатся нетронутой)
		}
	}
	file_r.close();
}

template<class T>
void qSortI(T a[], long size) {

	long i, j;   			// указатели, участвующие в разделении

	long lb, ub;  		// границы сортируемого в цикле фрагмента

	long lbstack[MAXSTACK], ubstack[MAXSTACK]; // стек запросов
											   // каждый запрос задается парой значений,
											   // а именно: левой(lbstack) и правой(ubstack) 
											   // границами промежутка

	long stackpos = 1;   	// текущая позиция стека
	long ppos;            // середина массива
	T pivot;              // опорный элемент
	T temp;

	lbstack[1] = 0;
	ubstack[1] = size - 1;

	do {

		// Взять границы lb и ub текущего массива из стека.

		lb = lbstack[stackpos];
		ub = ubstack[stackpos];
		stackpos--;

		do {
			// Шаг 1. Разделение по элементу pivot

			ppos = (lb + ub) >> 1;
			i = lb; j = ub; pivot = a[ppos];

			do {
				while (a[i] < pivot) i++;
				while (pivot < a[j]) j--;

				if (i <= j) {
					temp = a[i]; a[i] = a[j]; a[j] = temp;
					i++; j--;
				}
			} while (i <= j);

			// Сейчас указатель i указывает на начало правого подмассива,
			// j - на конец левого (см. иллюстрацию выше), lb ? j ? i ? ub.
			// Возможен случай, когда указатель i или j выходит за границу массива

			// Шаги 2, 3. Отправляем большую часть в стек  и двигаем lb,ub

			if (i < ppos) {     // правая часть больше

				if (i < ub) {     //  если в ней больше 1 элемента - нужно 
					stackpos++;       //  сортировать, запрос в стек
					lbstack[stackpos] = i;
					ubstack[stackpos] = ub;
				}
				ub = j;             //  следующая итерация разделения
									//  будет работать с левой частью

			}
			else {       	    // левая часть больше

				if (j > lb) {
					stackpos++;
					lbstack[stackpos] = lb;
					ubstack[stackpos] = j;
				}
				lb = i;
			}

		} while (lb < ub);        // пока в меньшей части более 1 элемента

	} while (stackpos != 0);    // пока есть запросы в стеке
}

int main()
{ 

	vector<Worker> workers;           // Контейнер структур
	vector<Worker> ::iterator it;     // Итератор для работы с контейнером workers
	Worker *w = NULL;                 // Указатель на "технический" объект
	vector<int> id_s_mas;             // Контейнер для id рабочих
	vector<int> ::iterator it_id;     // Итератор для работы с контейнером id_s_mas

	char act = ' ';                   // Действие над структурами вводимое пользователем
	                                  // Указываем файл для считывания и хранения данных
	string fname = "C:/Users/MarineJ/Documents/Visual Studio 2015/normal_tasks/normal_12/file.txt";        // Название файла с данными

	load_from_file(fname, &workers, w, &id_s_mas);
	                                   // После создания контейнера и его заполнения информацией 
	                                   // над ней можно выполнять следующие операции

	while (act!='Q')
	{
		cout << "\nPlease choose action:\n"
			"N New worker.\n"
			"E Edit data.\n"
			"F Find worker.\n"
			"D Delete data.\n"
			"S Save to file.\n"
			"R Load from file.\n"
			"V Show all workers.\n"
			"C Sort data.\n"
			"Q Quit.\n\n";
		cin >> act;
		cin.ignore();
		cout << endl;

		string input, str = "{";

		switch (act)                        // Действия над структурами выбор которых произврдится пользователем
		{
			{case 'N':                         // Добавляем объект в контейнер 
										  // Алгоритм : 1. Создаем нового "Рабочего"
														// а) Возможно через конструктор или отдельную функцию 
														//    с указанием ввода нужной информацией 
														// 2. Заносим его в контейнер
														// 3. Плюсуем "количество рабочих"
				int index = 0;
				while (index < 6)
				{
					if (index == 0)
						cout << "Surname :";
					else if (index == 1)
						cout << "Name :";
					else if (index == 2)
						cout << "Patronymic :";
					else if (index == 3)
						cout << "Post :";
					else if (index == 4)
						cout << "Hr_pay :";
					else if (index == 5)
						cout << "Hours :";
					cin >> input;
					str += input + ";";
					index++;
				}
				w = new Worker(str);
				workers.push_back(*w);
				id_s_mas.push_back(w->id);
				delete w;
				break;
			}
			{case 'E':                        // Редакция данных объектов в контейнере
										 // Алгоритм : 1. Вывод данных о всех структурах в контейнере
													// 2. Выбор (ввод id) нужной структуры
													// 3. Ввод в нужных полях для изменения информации
													//        Формат вывода
													//    id !( Подумать о автоматическом дописовании )
													//    Поле для ввода  (Записаная информация)
													//    Поле для ввода  (Записаная информация)
				out_format_data();   //1. Вывод данных о всех структурах в контейнере
				it = workers.begin();
				while (it != workers.end())
				{
					output_w_data(*it);
					it++;
				}
				cout << "\nInput workers id u want to edit : ";  // 2. Выбор (ввод id) нужной структуры
				int id_w = 0;
				cin >> id_w;

				it = workers.begin();
				int index = 0;
				while (1)
				{
					if (it == workers.end())
					{
						break;
					}
					if (id_w == it->id)
					{
						workers[index].for_edit();
					}
					it++;
					index++;
				}

				break;
			}
			{case 'F':                            // Поиск "Рабочего" по id
				cout << "\nInput workers id u want to find : ";  // 2. Выбор (ввод id) нужной структуры
				int id_w = 0;
				cin >> id_w;
				it_id = id_s_mas.begin();
				int index = 0;
				while (1)
				{
					if (it_id == id_s_mas.end())
					{
						cout << "There are no such id \n";
						break;
					}
					if (id_w == *it_id)
					{
						out_format_data();
						output_w_data(workers[index]);
						break;
					}
					it_id++;
					index++;
				}
					break; 
			}
			{case 'D':                             //  Удаление определенного объекта в контейнере 
											 //  Алгоритм : 1. Вывод данных о всех структурах в контейнере
														 // а) возможно задать вопрос нужно ли выводить данные ?
														 // 2. Запрос ввода информации (id) объекта к удалению
														 // 3. Само удаление (или информация в случае не удалния) 
			// vec.erase(vec.begin() + idx);   // Удаление по индексу
				char inou;
				cout << "\nDo u want to see all workers or just input id? (yes - y, no - n):"; 
				cin >> inou;
				if (inou != 'n')
				{
					out_format_data();   //1. Вывод данных о всех структурах в контейнере
					it = workers.begin();
					while (it != workers.end())
					{
						output_w_data(*it);
						it++;
					}
				}
				cout << "\nInput workers id u want to delete : ";  // 2. Выбор (ввод id) нужной структуры
				int id_w = 0;
				cin >> id_w;

				it_id = id_s_mas.begin();
				int index = 0;
				while (1)
				{
					if (it_id == id_s_mas.end())
					{
						cout << "There are no such id \n";
						break;
					}
					if (id_w == *it_id)
					{
						id_s_mas.erase(id_s_mas.begin() + index);
						workers.erase(workers.begin() + index);
						cout << "Deleted \n";
						break;
					}
					it_id++;
					index++;
				}
				break;
			}
		case 'S':                            // Сохранить результат работы в файл
				save_file(fname, workers);
			break; 
			{case 'R':                       // Подгрузить данные с файла
				char answer;
				string linej;
				cout << "\nDo u want to save all work?(yes - y, no - n) : ";
				cin >> answer;
				if (answer != 'n')
				{
					save_file(fname, workers);
				}
				cin.ignore();
				cout << "\nInput filepath : ";
				std::getline(std::cin, linej);

				it = workers.begin();
				while (it != workers.end())
				{
					it = workers.erase(it);
					id_s_mas.erase(id_s_mas.begin());
				}
				load_from_file(linej, &workers, w,&id_s_mas);
				break;
			}
		case 'V':
			out_format_data();   //1. Вывод данных о всех структурах в контейнере
			it = workers.begin();
			while (it != workers.end())
			{
				output_w_data(*it);
				it++;
			}
			break;
			{case 'C':
				//qSortI(&id_s_mas, id_s_mas.size());
				char ans ='\0';
				cout << "from smallest to biggest or reverse ? (1 or 2) : ";
				cin >> ans;
				if(ans=='1')
					sort(workers.begin(), workers.end(), sort_objectX);
				else if (ans == '2')
					sort(workers.begin(), workers.end(), rsort_objectX);
				break;
			}
		case 'Q': // Exit
			break;
		}
	}
	system("pause");
	return 0;
}



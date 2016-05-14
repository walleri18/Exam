/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/
/*
	Задача №2.
	Написать программу, которая по введённому значению аргумента 
	вычисляет значение функции, заданной в виде графика.
*/

/*
	Псевдо код:
	1. Рассавить все условия;
	2. Сделать расчёты.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>

using namespace std;

// Описание нашего типа Gragic
class Grafic
{
private:

	double argument;// Аргумент
	double result;// Результата вычислений
	
public:

	Grafic();// Конструктор по-умолчанию
	Grafic(double);// Конструктор с вводом аргумента для функции
	~Grafic();// Деструктор по-умолчанию
	void show();// Метод для вывода результата в красивом виде
	void setArgument();// Метод ввода данных

private:

	void calculate();// Метод расчёта функции
};

// Конструктор по-умолчанию
Grafic::Grafic() : argument(0), result(0)
{}

// Конструктор для ввода аргумента
Grafic::Grafic(double arg) : argument(arg), result(0)
{}

// Деструктор по-умолчанию
Grafic::~Grafic()
{}

// Метод для вывода информации в красивом виде
void Grafic::show()
{
	// Делаем необходимые расчёты
	this->calculate();

	cout << endl << "Результаты расчёта: Y(" << argument << ") = " << result << endl << endl;
}

// Метод ввода аргумента
void Grafic::setArgument()
{
	// Ввод аргумента
	cout << endl << "Введите аргумент X: ";
	cin >> argument;
}

// Метод для расчёта 
void Grafic::calculate()
{
	// Первый отрезок
	if (argument <= -2 || argument >= 2)
		result = 0;
	
	// Второй отрезок
	else if (argument > -2 && argument < -1)
		result = -(2 + argument);
	
	// Третий отрезок
	else if (argument > 1 && argument < 2)
		result = 2 - argument;
	
	// Четвёртый отрезок
	else
		result = argument;
}

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	// Приветствие
	cout << endl << "Экзаменационное задание №2" << endl << endl;

	// Создание объекта график
	Grafic grafic;

	// Установка аргумента
	grafic.setArgument();
	
	// Расчёт и вывод результата
	grafic.show();
	
	
	return 0;
}
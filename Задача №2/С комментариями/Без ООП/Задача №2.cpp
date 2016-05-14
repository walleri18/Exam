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

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	// Приветствие
	cout << endl << "Экзаменационное задание №2" << endl << endl;

	double argument;// Аргумент
	double result;// Результата вычислений
	
	// Ввод аргумента
	cout << endl << "Введите аргумент X: ";
	cin >> argument;
	
	// Выполнение вычислений
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
	
	// Вывод результата
	cout << endl << "Результаты расчёта: Y(" << argument << ") = " << result << endl << endl;
	
	return 0;
}
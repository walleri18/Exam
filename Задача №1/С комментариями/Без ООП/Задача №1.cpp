/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/
/*
	Задача №1.
	Задано два момента времени в часах, минутах и секундах (в пределах одних суток).
	Найти длительность промежутка времени между этими моментами в тех же единицах.
*/

/*
	Псевдо код:
	1. Узнать у пользователя моменты времени;
	2. Найти отрезок времени.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>

using namespace std;

// Константы суток
long hours = 24; // Константа количества часов в сутках
long minutes = 60; // Константа количества минут в часе
long seconds = 60; // Константа количества секунд в минуте

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251
	
	// Приветствие
	cout << endl << "Экзаменационное задание №1" << endl << endl;
	
	// Первый момент
	long hour_one;// час
	long minute_one;// минута
	long second_one;// секунда
	
	// Второй момент
	long hour_two;// час
	long minute_two;// минута
	long second_two;// секунда
	
	// Предупреждение об ограничении
	cout << "Расчёт идёт в течении одних суток!!!" << endl << endl; 
	
	char tmp;// буферная переменная для ввода разделителя между числами

	// Ввод первого момента с защитой от дурака
	do
	{
		// Запрос на ввод
		cout << "Введите первый момент времени в формате hh/mm/ss и нажмите Enter(формат 24 часа!!!): ";

		// Ввод данных
		cin >> hour_one >> tmp >> minute_one >> tmp >> second_one;
		
		// Количество часов не может быть отрицательным и больше 24
		// Количество минут не может быть отрицательным и больше 59
		// Количество секунд не может быть отрицательным и больше 59
	} while (((hour_one >= hours) || (hour_one < 0)) || ((minute_one >= minutes) || (minute_one < 0)) || ((second_one >= seconds) || (second_one < 0)));
	
	// Ввод второго момента с защитой от дурака
	do
	{
		// Запрос на ввод
		cout << "Введите второй момент времени в формате hh/mm/ss и нажмите Enter(формат 24 часа!!!): ";

		// Ввод данных
		cin >> hour_two >> tmp >> minute_two >> tmp >> second_two;
		
		// Количество часов не может быть отрицательным и больше 24
		// Количество минут не может быть отрицательным и больше 59
		// Количество секунд не может быть отрицательным и больше 59
	} while (((hour_two >= hours) || (hour_two < 0)) || ((minute_two >= minutes) || (minute_two < 0)) || ((second_two >= seconds) || (second_two < 0)));

	// Буферная переменная секунд и перевод всего в секунды
	long tmp_full_second = abs(hour_one - hour_two) * minutes * seconds + abs(minute_one - minute_two) * seconds + abs(second_one - second_two);

	// Буферные переменные результата
	long hour_result(0), minute_result(0), second_result(0);

	// Вычисление количества часов
	hour_result = tmp_full_second / (minutes * seconds);

	// Вычисление количества минут
	minute_result = (tmp_full_second % (minutes * seconds)) / seconds;

	// Вычисление количества секунд
	second_result = (tmp_full_second % (minutes * seconds)) % seconds;
	
	// Вывод результата
	cout << endl << "Часов = " << hour_result << " Минут = " << minute_result << " Секунд = " << second_result << endl << endl;
	
	return 0;
}
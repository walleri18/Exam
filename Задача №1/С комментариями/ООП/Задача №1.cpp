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

// Предупреждение компилятора об некоторых константах
extern long hours, minutes, seconds;

// Класс времени
class Time
{
// Данные
private:

	// Аргументы
	long hour;// час
	long minute;// минута
	long second;// секунда

	// Системные (для красоты)
	int numberMoment;// номер момента

// Функции (методы)
public:

	Time();// Конструктор по умолчанию
	Time(int);// Конструктор с одним параметром для номера момента
	Time(long, long, long);// Конструктор с тремя параметрами
	~Time();// Деструктор по умолчанию
	void dataEntry();// Ввод данных
	Time& operator - (Time&);// Перевод в секунды и подсчёт разницы по модулю, возврат нового объекта
	void show();// Вывод результата
};

// Константы суток
long hours = 24; // Константа количества часов в сутках
long minutes = 60; // Константа количества минут в часе
long seconds = 60; // Константа количества секунд в минуте

// Конструктор по умолчанию
Time::Time() : hour(0), minute(0), second(0)
{
	numberMoment++;
}

// Конструктор с одним параметром для номера момента
Time::Time(int numberMoment) : numberMoment(numberMoment)
{
}

// Конструктор с треммя параметрами
Time::Time(long hour, long minute, long second) : hour(hour), minute(minute), second(second)
{
}

// Деструктор по умолчанию
Time::~Time()
{
}

// Ввод данных
void Time::dataEntry()
{
	char tmp;// буферная переменная для ввода разделителя между числами

	// Защита от дурака
	do
	{

		// Запрос на ввод
		cout << "Введите " << this->numberMoment << " момент времени в формате hh/mm/ss и нажмите Enter(формат 24 часа!!!): ";

		// Ввод данных
		cin >> hour >> tmp >> minute >> tmp >> second;

	} while (((hour >= hours) || (hour < 0)) || ((minute >= minutes) || (minute < 0)) || ((second >= seconds) || (second < 0)));
}

// Перевод в секунды и подсчёт разницы по модулю, возврат нового объекта
Time& Time::operator - (Time &obj)
{
	// Буферная переменная секунд и перевод всего в секунды
	long tmp = abs(this->hour - obj.hour) * minutes * seconds + abs(this->minute - obj.minute) * seconds + abs(this->second - obj.second);;

	// Буферные переменные результата
	long hour(0), minute(0), second(0);

	// Вычисление количества часов
	hour = tmp / (minutes * seconds);

	// Вычисление количества минут
	minute = (tmp % (minutes * seconds)) / seconds;

	// Вычисление количества секунд
	second = (tmp % (minutes * seconds)) % seconds;

	// Создание объекта в куче
	Time *time = new Time(hour, minute, second);

	// Возврат ссылки на объект
	return *time;
}

// Вывод результата
void Time::show()
{
	cout << endl << "Часов = " << hour << " Минут = " << minute << " Секунд = " << second << endl;
}

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	// Приветствие
	cout << endl << "Экзаменационное задание №1" << endl << endl;

	// Предупреждение об ограничении
	cout << "Расчёт идёт в течении одних суток!!!" << endl << endl; 
	
	// Первый момент
	Time time1(1);

	// Второй момент
	Time time2(2);
	
	// Вводим информацию об первом моменте
	time1.dataEntry();

	// Вводим информацию об втором объекте
	time2.dataEntry();

	// Результирующий
	Time time3;

	// Считаем разницу между объектами по модулю
	time3 = time1 - time2;

	// Выводим информацию результата
	time3.show();

	return 0;
}
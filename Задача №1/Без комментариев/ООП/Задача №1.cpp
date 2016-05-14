#include <locale.h>
#include <Windows.h>
#include <iostream>

using namespace std;

extern long hours, minutes, seconds;

class Time
{
private:

	long hour;
	long minute;
	long second;

public:

	Time();
	Time(long, long, long);
	virtual ~Time();
	void dataEntry();
	Time& operator - (Time&);
	void show();
};

long hours = 24;
long minutes = 60;
long seconds = 60;

Time::Time() : hour(0), minute(0), second(0)
{
}

Time::Time(long hour, long minute, long second) : hour(hour), minute(minute), second(second)
{
}

Time::~Time()
{
}

void Time::dataEntry()
{
	char tmp;

	do
	{
		cout << "Введите момент времени в формате hh/mm/ss и нажмите Enter(формат 24 часа!!!): ";

		cin >> hour >> tmp >> minute >> tmp >> second;

	} while (((hour >= hours) || (hour < 0)) || ((minute >= minutes) 
	|| (minute < 0)) || ((second >= seconds) || (second < 0)));
}

Time& Time::operator - (Time &obj)
{
	long tmp = abs(this->hour - obj.hour) * minutes * seconds 
	+ abs(this->minute - obj.minute) * seconds + abs(this->second - obj.second);;

	long hour(0), minute(0), second(0);

	hour = tmp / (minutes * seconds);

	minute = (tmp % (minutes * seconds)) / seconds;

	second = (tmp % (minutes * seconds)) % seconds;

	Time *time = new Time(hour, minute, second);

	return *time;
}

void Time::show()
{
	cout << endl << "Часов = " << hour << " Минут = " 
	<< minute << " Секунд = " << second << endl;
}

int main(void)
{
	setlocale(LC_ALL, ".1251");

	cout << endl << "Экзаменационное задание №1" << endl << endl;

	cout << "Расчёт идёт в течении одних суток!!!" << endl << endl; 
	
	Time time1();

	Time time2();

	time1.dataEntry();

	time2.dataEntry();

	Time time3;

	time3 = time1 - time2;

	time3.show();

	return 0;
}
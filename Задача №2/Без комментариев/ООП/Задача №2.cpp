#include <locale.h>
#include <Windows.h>
#include <iostream>

using namespace std;

class Grafic
{
private:

	double argument;
	double result;
	
public:

	Grafic();
	Grafic(double);
	void show();
	void setArgument();

private:

	void calculate();
};

Grafic::Grafic() : argument(0), result(0)
{}

Grafic::Grafic(double arg) : argument(arg), result(0)
{}

void Grafic::show()
{
	this->calculate();

	cout << endl << "Результаты расчёта: Y(" << argument << ") = " 
	<< result << endl << endl;
}

void Grafic::setArgument()
{
	cout << endl << "Введите аргумент X: ";
	cin >> argument;
}

void Grafic::calculate()
{
	if (argument <= -2 || argument >= 2)
		result = 0;

	else if (argument > -2 && argument < -1)
		result = -(2 + argument);

	else if (argument > 1 && argument < 2)
		result = 2 - argument;

	else
		result = argument;
}

int main(void)
{
	setlocale(LC_ALL, ".1251");

	cout << endl << "Экзаменационное задание №2" << endl << endl;

	Grafic grafic;

	grafic.setArgument();

	grafic.show();

	return 0;
}
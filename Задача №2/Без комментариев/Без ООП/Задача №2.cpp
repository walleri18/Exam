#include <locale.h>
#include <Windows.h>
#include <iostream>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, ".1251");

	cout << endl << "��������������� ������� �2" << endl << endl;

	double argument;
	double result;

	cout << endl << "������� �������� X: ";
	cin >> argument;

	if (argument <= -2 || argument >= 2)
		result = 0;

	else if (argument > -2 && argument < -1)
		result = -(2 + argument);

	else if (argument > 1 && argument < 2)
		result = 2 - argument;

	else
		result = argument;

	cout << endl << "���������� �������: Y(" << argument << ") = " << result << endl << endl;
	
	return 0;
}
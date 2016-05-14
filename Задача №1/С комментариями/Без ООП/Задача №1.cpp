/*
	��������� � �����������.
	�����: ����� ������� �������������
	������: 514
*/
/*
	������ �1.
	������ ��� ������� ������� � �����, ������� � �������� (� �������� ����� �����).
	����� ������������ ���������� ������� ����� ����� ��������� � ��� �� ��������.
*/

/*
	������ ���:
	1. ������ � ������������ ������� �������;
	2. ����� ������� �������.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>

using namespace std;

// ��������� �����
long hours = 24; // ��������� ���������� ����� � ������
long minutes = 60; // ��������� ���������� ����� � ����
long seconds = 60; // ��������� ���������� ������ � ������

// ����� �����

int main(void)
{
	setlocale(LC_ALL, ".1251"); // ��������� ��������� windows-1251
	
	// �����������
	cout << endl << "��������������� ������� �1" << endl << endl;
	
	// ������ ������
	long hour_one;// ���
	long minute_one;// ������
	long second_one;// �������
	
	// ������ ������
	long hour_two;// ���
	long minute_two;// ������
	long second_two;// �������
	
	// �������������� �� �����������
	cout << "������ ��� � ������� ����� �����!!!" << endl << endl; 
	
	char tmp;// �������� ���������� ��� ����� ����������� ����� �������

	// ���� ������� ������� � ������� �� ������
	do
	{
		// ������ �� ����
		cout << "������� ������ ������ ������� � ������� hh/mm/ss � ������� Enter(������ 24 ����!!!): ";

		// ���� ������
		cin >> hour_one >> tmp >> minute_one >> tmp >> second_one;
		
		// ���������� ����� �� ����� ���� ������������� � ������ 24
		// ���������� ����� �� ����� ���� ������������� � ������ 59
		// ���������� ������ �� ����� ���� ������������� � ������ 59
	} while (((hour_one >= hours) || (hour_one < 0)) || ((minute_one >= minutes) || (minute_one < 0)) || ((second_one >= seconds) || (second_one < 0)));
	
	// ���� ������� ������� � ������� �� ������
	do
	{
		// ������ �� ����
		cout << "������� ������ ������ ������� � ������� hh/mm/ss � ������� Enter(������ 24 ����!!!): ";

		// ���� ������
		cin >> hour_two >> tmp >> minute_two >> tmp >> second_two;
		
		// ���������� ����� �� ����� ���� ������������� � ������ 24
		// ���������� ����� �� ����� ���� ������������� � ������ 59
		// ���������� ������ �� ����� ���� ������������� � ������ 59
	} while (((hour_two >= hours) || (hour_two < 0)) || ((minute_two >= minutes) || (minute_two < 0)) || ((second_two >= seconds) || (second_two < 0)));

	// �������� ���������� ������ � ������� ����� � �������
	long tmp_full_second = abs(hour_one - hour_two) * minutes * seconds + abs(minute_one - minute_two) * seconds + abs(second_one - second_two);

	// �������� ���������� ����������
	long hour_result(0), minute_result(0), second_result(0);

	// ���������� ���������� �����
	hour_result = tmp_full_second / (minutes * seconds);

	// ���������� ���������� �����
	minute_result = (tmp_full_second % (minutes * seconds)) / seconds;

	// ���������� ���������� ������
	second_result = (tmp_full_second % (minutes * seconds)) % seconds;
	
	// ����� ����������
	cout << endl << "����� = " << hour_result << " ����� = " << minute_result << " ������ = " << second_result << endl << endl;
	
	return 0;
}
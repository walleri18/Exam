/*
	��������� � �����������.
	�����: ����� ������� �������������
	������: 514
*/

/*
	������ �13.
	����������� ����������� �������-������ ��� ������� ���������� �������� ������������ �������� �����. 
	�������� ������� ���������� ������ � �����������.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

/*
	���������
*/
// ������� ���������� ����� ������������
template <class Type>
void sortQuickIn(Type*, int, int);

// ������� ���������� ����� ���������
template <class Type>
void sortQuickDec(Type*, int, int);

// ������� ������ ����������
template <class Type>
void sort(Type*, int, const char);

// ����� �����

int main(void)
{
	// ����� �������
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // ��������� ������� ���������

	cout << endl << endl << "����������������� ������� �12" << endl << endl;

	// ������ �������
	int size;

	// ������ ������� �������
	cout << "������� ������ ������� ���� INT: ";
	cin >> size;

	// �������� ������� ���� INT ������� size
	int *dataInt = new int[size];

	// ��������� �������� ��� ������� ���� INT
	for (int i = 0; i < size; i++)
		dataInt[i] = rand() % (100 - (-100) + 1) + (-100);

	cout << endl << endl
		<< "����� ���������������� �������: " << endl << endl;

	// ����� ������������������ ������� ���� INT
	for (int i = 0; i < size; i++)
		cout << dataInt[i] << " ";

	cout << endl << endl;

	// ���������� ������� ��-�����������
	sort(dataInt, size, '+');

	// ����� ���������������� ������� ��-�����������
	cout << "��������������� ������ ��-�����������: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << dataInt[i] << " ";

	cout << endl << endl;

	// ���������� ������� ��-��������
	sort(dataInt, size, '-');

	// ����� ���������������� ������� ��-��������
	cout << "��������������� ������ ��-��������: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << dataInt[i] << " ";

	cout << endl << endl;

	// ������ ������� �������
	cout << "������� ������ ������� ���� DOUBLE: ";
	cin >> size;

	// �������� ������� ���� DOUBLE ������� size
	double *dataDouble = new double[size];

	// ��������� �������� ��� ������� ���� INT
	for (int i = 0; i < size; i++)
		dataDouble[i] = rand() % (100 - (-100) + 1) + (-100) + 0.5;

	cout << endl << endl
		<< "����� ���������������� �������: " << endl << endl;

	// ����� ������������������ ������� ���� DOUBLE
	for (int i = 0; i < size; i++)
		cout << dataDouble[i] << " ";

	cout << endl << endl;

	// ���������� ������� ��-�����������
	sort(dataDouble, size, '+');

	// ����� ���������������� ������� ��-�����������
	cout << "��������������� ������ ��-�����������: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << dataDouble[i] << " ";

	cout << endl << endl;

	// ���������� ������� ��-��������
	sort(dataDouble, size, '-');

	// ����� ���������������� ������� ��-��������
	cout << "��������������� ������ ��-��������: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << dataDouble[i] << " ";

	cout << endl << endl;

	return 0;
}

/*
	����������
*/
// ������� ���������� ����� ������������
template <class Type>
void sortQuickIn(Type *data, int begin_0, int end_0)
{
	// �����������(�������, ������������ �������� ����� ������ ������ �������(��-��������, � �� �� ������)) ��� ����������� ���������
	auto divider = data[end_0];

	// ������ �� ������ �������
	auto begin = begin_0;

	// ������ �� ����� �������
	auto end = end_0;

	do
	{
		// ����� �������� �������� �����������
		while (data[begin] < divider)
			++begin;

		// ����� �������� ������ �����������
		while (data[end] > divider)
			--end;

		// ���� ������ � ����� �� ����� ���� �� �����
		if (begin <= end)
		{
			// ������ �������� �������
			swap(data[begin], data[end]);

			// ����������� �������, ����� ����� �� ����� ��������� do-while
			++begin;
			--end;
		}
	} while (begin <= end);

	// ������� ������������ ����� ����� ������
	if (end > begin_0)
		sortQuickIn(data, begin_0, end);

	// ����� ������������ ������ ����� ������
	else if (begin < end_0)
		sortQuickIn(data, begin, end_0);
}

// ������� ���������� ����� ���������
template <class Type>
void sortQuickDec(Type *data, int begin_0, int end_0)
{
	// �����������(�������, ������������ �������� ����� ������ ������ �������(��-��������, � �� �� ������)) ��� ����������� ���������
	auto divider = data[end_0];

	// ������ �� ������ �������
	auto begin = begin_0;

	// ������ �� ����� �������
	auto end = end_0;

	do
	{
		// ����� �������� �������� �����������
		while (data[begin] > divider)
			++begin;

		// ����� �������� ������ �����������
		while (data[end] < divider)
			--end;

		// ���� ������ � ����� �� ����� ���� �� �����
		if (begin <= end)
		{
			// ������ �������� �������
			swap(data[begin], data[end]);

			// ����������� �������, ����� ����� �� ����� ��������� do-while
			++begin;
			--end;
		}
	} while (begin <= end);

	// ������� ������������ ����� ����� ������
	if (end > begin_0)
		sortQuickDec(data, begin_0, end);

	// ����� ������������ ������ ����� ������
	else if (begin < end_0)
		sortQuickDec(data, begin, end_0);
}

// ������� ����������
template <class Type>
void sort(Type *data, int size, const char vector)
{
	// ���� ������ ������ �� �����������
	if (vector == '+')
		sortQuickIn(data, 0, size - 1);

	// ���� ������ ������ �� ��������
	else if (vector == '-')
		sortQuickDec(data, 0, size - 1);
}
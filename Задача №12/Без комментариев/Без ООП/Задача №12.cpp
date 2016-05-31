#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

void sortQuickIn(int*, int, int);

void sortQuickDec(int*, int, int);

void sort(int*, int, const char);

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Экзаменационное задание №12" << endl << endl;

	int size;

	cout << "Введите размер массива типа INT: ";
	cin >> size;

	int *data = new int[size];

	for (int i = 0; i < size; i++)
		data[i] = rand() % (100 - (-100) + 1) + (-100);

	cout << endl << endl
		<< "Вывод несортированного массива: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << data[i] << " ";

	cout << endl << endl;

	sort(data, size, '+');

	cout << "Отсортированный массив по-возростанию: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << data[i] << " ";

	cout << endl << endl;

	sort(data, size, '-');

	cout << "Отсортированный массив по-убыванию: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << data[i] << " ";

	cout << endl << endl;

	return 0;
}

void sortQuickIn(int *data, int begin_0, int end_0)
{
	auto divider = data[end_0];

	auto begin = begin_0;

	auto end = end_0;

	do
	{
		while (data[begin] < divider)
			++begin;

		while (data[end] > divider)
			--end;

		if (begin <= end)
		{
			swap(data[begin], data[end]);

			++begin;
			--end;
		}
	} while (begin <= end);

	if (end > begin_0)
		sortQuickIn(data, begin_0, end);

	else if (begin < end_0)
		sortQuickIn(data, begin, end_0);
}

void sortQuickDec(int *data, int begin_0, int end_0)
{
	auto divider = data[end_0];

	auto begin = begin_0;

	auto end = end_0;

	do
	{
		while (data[begin] > divider)
			++begin;

		while (data[end] < divider)
			--end;

		if (begin <= end)
		{
			swap(data[begin], data[end]);

			++begin;
			--end;
		}
	} while (begin <= end);

	if (end > begin_0)
		sortQuickDec(data, begin_0, end);

	else if (begin < end_0)
		sortQuickDec(data, begin, end_0);
}

void sort(int *data, int size, const char vector)
{
	if (vector == '+')
		sortQuickIn(data, 0, size - 1);

	else if (vector == '-')
		sortQuickDec(data, 0, size - 1);
}
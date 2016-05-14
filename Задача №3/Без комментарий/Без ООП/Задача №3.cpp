#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "��������������� ������� �3" << endl << endl;

	int *data(NULL);
	int size(0);

	int indexMinimumElement(0);
	int minimumElement(0);
	int indexMaximumElement(0);
	int maximumElement(0);
	int numberElements(0);
	
	cout << endl << "����������, ������� ������ �������: ";
	cin >> size;

	data = new int[size];

	cout << endl << "���������� �������:" << endl;

	for (int i = 0; i < size; i++)
		data[i] = rand() % (100 - (-100) + 1) + (-100);
	
	minimumElement = data[0];

	for (int i = 1; i < size; i++)
	{
		if (data[i] < minimumElement) {
			minimumElement = data[i];
			indexMinimumElement = i;
		}
	}
	
	indexMaximumElement = data[0];

	for (int i = 1; i < size; i++)
	{
		if (data[i] > maximumElement) {
			maximumElement = data[i];
			indexMaximumElement = i;
		}
	}

	if (indexMinimumElement > indexMaximumElement) {

		for (int i = indexMaximumElement + 1; i < indexMinimumElement; i++)
		{
			if (data[i] > 0) numberElements++;
		}
	}

	else if (indexMaximumElement > indexMinimumElement) {

		for (int i = indexMinimumElement + 1; i < indexMaximumElement; i++)
		{
			if (data[i] > 0) numberElements++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (i < size - 1)
			cout << data[i] << ", ";
		else
			cout << data[i] << endl << endl;
	}

	cout << endl << "����������� ������� �������: " << minimumElement 
	<< ". ��� ������: " << indexMinimumElement << endl
		<< "������������ ������� �������: " << maximumElement 
		<< ". ��� ������: " << indexMaximumElement << endl
		<< "���������� ��������� �������, ����� ����������� �������� � �����������: " 
		<< numberElements << endl;

	delete[] data;

	return 0;
}
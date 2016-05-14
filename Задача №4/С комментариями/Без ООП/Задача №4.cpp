/*
	��������� � �����������.
	�����: ����� ������� �������������
	������: 514
*/

/*
	������ �4.
	�� ������������� ������� N, ����� ���������� �������������� ��������, ��������� ����� ��������� �������.
*/

/*
	������ ���:
	1. �������� ������������ � ���, ������ ������� ������;
	2. ������� ������������ ������� ������;
	3. ����� ������������ �������� ��� ���������� �������;
	4. ���������� ������ � ����� ������ ���������� �������������� ��������;
	5. ��������� ����� ���������, ������������� ������ ���������� �������������� �������� � �������.
*/
#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;


// ����� �����

int main(void)
{
	// ����� �������
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // ��������� ��������� windows-1251

	cout << endl << endl << "��������������� ������� �4" << endl << endl;

	/*
		�������� ������
	*/
	double *data(NULL);// ��������� �� ������ ������������ �����
	int size(0);// ������ �������

	/*
		�������������� ������
	*/
	int indexLastNegative(0);// ������ ���������� �������������� �����
	double lastNegativeElement(0);// �������� ���������� �������������� ��������
	int summaAfterIndexLastNegative(0);// ����� ����� ����� ���������� ����������� �����
	bool isNegativElement(false);// ���� �� ������������� �������� � �������
	
	// ������ � ������������ � ������� ��������� �������
	cout << endl << "����������, ������� ������ �������: ";
	cin >> size;
	
	// �������� �������
	data = new double[size];

	// ���������� �������
	for (int i = 0; i < size; i++)
	{
		// ���������� ������� ���������� ������� �� -100 �� 100

		//������� ���������� ����� � ��������� [min, max]:
		//random_number = rand() % (max - min + 1) + min;

		data[i] = rand() % (100 - (-100) + 1) + (-100);
	}
	
	// ����� ���������� �������������� �����
	// ���������� ������������� ���������
	int numberNegativeElements(0);
	
	// ������� � ���� ��������� ������������� �������
	for (int i = indexLastNegative + 1; i < size; i++)
	{
		if (data[i] < 0) {
			numberNegativeElements++;
			lastNegativeElement = data[i];
			indexLastNegative = i;
		}
	}
	
	// ������������� ��������� ���������� ������� � ������ - ���� �� � ��� ������ ������������� ��������
	isNegativElement = (numberNegativeElements > 0) ? true : false;
	
	// ���� ���� ������������� ��������, �� ��������� ����� ���������� �����
	if (isNegativElement)
	{
		// ������������
		for (int i = indexLastNegative + 1; i < size; i++)
		{
			summaAfterIndexLastNegative += data[i];
		}
	}
	
	// ����� ���������������� �������
	for (int i = 0; i < size; i++)
	{
		if (i < size - 1)
			cout << data[i] << ", ";
		else
			cout << data[i] << endl << endl;
	}

	// ����� ����������
	if (isNegativElement)
	{
		// ����� ����������
		cout << endl << "�������� ���������� �������������� �������� �������: " << lastNegativeElement << ". ��� ������: " << indexLastNegative << endl
			<< "����� ���������, ������������� ������ ���������� �������������� ��������: " << summaAfterIndexLastNegative << endl;
	}
	else
	{
		cout << endl << "� ������� ��� ������������� ���������!!!";
	}
	
	// ������� ������
	delete[] data;

	return 0;
}
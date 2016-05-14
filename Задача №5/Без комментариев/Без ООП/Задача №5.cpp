#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "��������������� ������� �5" << endl << endl;

	int line(0), column(0);

	cout << endl << "����������, ������� ����������� ���������� ����� � �������: ";
	cin >> line;

	cout << endl << "����������, ������� ����������� ���������� �������� � �������: ";
	cin >> column;

	int **massif = new int* [line];
	for (int i = 0; i < line; i++) 
		massif[i] = new int[column];

	int *numberPositive = new int[line];
	for (int i = 0; i < line; i++) 
		numberPositive[i] = 0;

	int *numberNegative = new int[line];
	for (int i = 0; i < line; i++) 
		numberNegative[i] = 0;

	for (int i = 0; i < line; i++)
		for (int j = 0; j < column; j++)
			massif[i][j] = rand() % (100 - (-100) + 1) + (-100);

	cout << endl;

	double arithmeticMean(0.0);

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arithmeticMean += massif[i][j];
		}
	}

	arithmeticMean /= (line * column);

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (massif[i][j] > 0) 
				numberPositive[i]++;
			
			else if (massif[i][j] < 0) 
			numberNegative[i]++;
		}
	}

	cout << endl << "������� �������������� ��������� �������: " << arithmeticMean << endl;
	
	for (int i = 0; i < line; i++)
	{
		cout << "-------------------------------------------------------------------" << endl
				<< "���������� ������������� ��������� ������� � " << i + 1 
				<< " ������: " << numberPositive[i] << " ���������" << endl
				<< "���������� ������������� ��������� ������� � " << i + 1 
				<< " ������: " << numberNegative[i] << " ���������" << endl
				<< "-------------------------------------------------------------------"
				<< endl << endl;
	}

	delete[] numberNegative;
	delete[] numberPositive;

	for (int i = 0; i < line; i++)
		delete[] massif[i];

	delete[] massif;

	return 0;
}
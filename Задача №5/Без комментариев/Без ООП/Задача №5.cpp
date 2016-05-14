#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Экзаменационное задание №5" << endl << endl;

	int line(0), column(0);

	cout << endl << "Пожалуйста, введите необходимое количество строк в матрице: ";
	cin >> line;

	cout << endl << "Пожалуйста, введите необходимое количество столбцов в матрице: ";
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

	cout << endl << "Среднее арифметическое элементов матрицы: " << arithmeticMean << endl;
	
	for (int i = 0; i < line; i++)
	{
		cout << "-------------------------------------------------------------------" << endl
				<< "Количество положительных элементов матрицы в " << i + 1 
				<< " строке: " << numberPositive[i] << " элементов" << endl
				<< "Количество отрицательных элементов матрицы в " << i + 1 
				<< " строке: " << numberNegative[i] << " элементов" << endl
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
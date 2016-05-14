/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №5.
	Из целочисленной матрицы NxM, найти среднее арифметическое её элементов и количество отрицательных и положительных элементов в каждой строке.
*/

/*
	Псевдо код:
	1. Спросить пользователя о том, сколько строк и столбцов в матрице;
	2. Создать определённого размера матрицу(двумерный массив);
	3. Пусть пользователь заполнит его случайными числами;
	4. Найдём среднее арифметическое элементов матрицы;
	5. Посчитаем количество положительных и отрицательных элементов в каждой строке.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

// Точка входа

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	cout << endl << endl << "Экзаменационное задание №5" << endl << endl;

	int line(0), column(0); // Количество строк и колонн в матрице

	cout << endl << "Пожалуйста, введите необходимое количество строк в матрице: ";
	cin >> line;

	cout << endl << "Пожалуйста, введите необходимое количество столбцов в матрице: ";
	cin >> column;

	// Создание матрицы
	int **massif = new int* [line];// Создаём строки
	for (int i = 0; i < line; i++) 
		massif[i] = new int[column];// В строках создаём столбцы

	// Количество положительных элементов
	int *numberPositive = new int[line];
	for (int i = 0; i < line; i++) 
		numberPositive[i] = 0;

	// Количество отрицательных элементов
	int *numberNegative = new int[line];
	for (int i = 0; i < line; i++) 
		numberNegative[i] = 0;

	//Заполняем матрицу
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			massif[i][j] = rand() % (100 - (-100) + 1) + (-100);
		}
	}

	cout << endl;

	// Среднее арифметическое
	double arithmeticMean(0.0);
	
	// Подсчёт среднего арифметического
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arithmeticMean += massif[i][j];
		}
	}

	arithmeticMean /= (line * column);

	// Подсчёт количества положительных и отрицательных элементов матрицы в каждой строке
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

	// Вывод результата
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

	// Очистка памяти
	delete[] numberNegative;
	delete[] numberPositive;

	for (int i = 0; i < line; i++)
		delete[] massif[i];

	delete[] massif;

	return 0;
}
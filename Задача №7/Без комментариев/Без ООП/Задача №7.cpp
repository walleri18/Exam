#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

double arithmeticMean(int*, int);

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Экзаменационное задание №7" << endl << endl;

	int size1(0), size2(0);

	cout << "Пожалуйста, введите размер массива №1: ";
	cin >> size1;

	cout << "Пожалуйста, введите размер массива №2: ";
	cin >> size2;

	int *massiv1 = new int[size1], *massiv2 = new int[size2];

	for (int i = 0; i < size1; i++)
		massiv1[i] = 0;
	

	for (int i = 0; i < size2; i++)
		massiv2[i] = 0;

	for (int i = 0; i < size1; i++)
		massiv1[i] = rand() % (100 - (-100) + 1) + (-100);

	for (int i = 0; i < size2; i++)
		massiv2[i] = rand() % (100 - (-100) + 1) + (-100);

	if (arithmeticMean(massiv1, size1) > arithmeticMean(massiv2, size2)) 
		cout << endl << "Среднее арифметическое массива №1 больше \
	среднего арифметического массива №2!" << endl;
	
	else if (arithmeticMean(massiv1, size1) < arithmeticMean(massiv2, size2))
		cout << endl << "Среднее арифметическое массива №1 меньше \
	среднего арифметического массива №2!" << endl;
	
	else 
		cout << endl << "Среднее арифметическое массива №1 равно \
	среднему арифметическому массива №2!" << endl;
	

	cout << "Среднее арифметическое массива №1: " << arithmeticMean(massiv1, size1) << endl
		<< "Среднее арифметическое массива №2: " << arithmeticMean(massiv2, size2) << endl;

	delete[] massiv1;
	delete[] massiv2;

	return 0;
}

double arithmeticMean(int *massiv, int size)
{
	double varArithmeticMean = 0.0;

	for (int i = 0; i < size; i++)
		varArithmeticMean += massiv[i];

	varArithmeticMean /= size;

	return varArithmeticMean;
}
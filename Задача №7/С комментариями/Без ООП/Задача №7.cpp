/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №7.
	Даны два массива из N целых чисел каждый. 
	Определить, для какого из них среднее арифметическое значение элементов больше. 
	Для решения задачи написать функцию, принимающую массив в качестве параметра и возвращающую среднее значение.
*/

/*
	Псевдо код:
	1. Запросить пользователя размер желаемого массива номер один и массива номер два;
	2. Предоставить пользовалю заполнить массивы случайным образом;
	3. Передать каждый массив в функцию по подсчёту средней арифметического;
	4. Сравнить среднее арифметические и сказать кто больше;
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

// Прототипы
double arithmeticMean(int*, int);

// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка русской раскладки

	cout << endl << endl << "Экзаменационное задание №7" << endl << endl;

	int size1(0), size2(0); // Размеры массивов

	// Ввод размеров массивов
	cout << "Пожалуйста, введите размер массива №1: ";
	cin >> size1;

	cout << "Пожалуйста, введите размер массива №2: ";
	cin >> size2;

	// Создание массивов соответствоющего размера
	int *massiv1 = new int[size1], *massiv2 = new int[size2];

	// Обнуление массивов
	for (int i = 0; i < size1; i++)
	{
		massiv1[i] = 0;
	}

	for (int i = 0; i < size2; i++)
	{
		massiv2[i] = 0;
	}

	// Заполнение массивов

	for (int i = 0; i < size1; i++)
	{
		massiv1[i] = rand() % (100 - (-100) + 1) + (-100);
	}

	for (int i = 0; i < size2; i++)
	{
		massiv2[i] = rand() % (100 - (-100) + 1) + (-100);
	}

	// Вывод результатов
	if (arithmeticMean(massiv1, size1) > arithmeticMean(massiv2, size2)) {
		cout << endl << "Среднее арифметическое массива №1 больше среднего арифметического массива №2!" << endl;
	}
	else if (arithmeticMean(massiv1, size1) < arithmeticMean(massiv2, size2)) {
		cout << endl << "Среднее арифметическое массива №1 меньше среднего арифметического массива №2!" << endl;
	}
	else {
		cout << endl << "Среднее арифметическое массива №1 равно среднему арифметическому массива №2!" << endl;
	}

	cout << "Среднее арифметическое массива №1: " << arithmeticMean(massiv1, size1) << endl
		<< "Среднее арифметическое массива №2: " << arithmeticMean(massiv2, size2) << endl;

	// Освобождение памяти
	delete[] massiv1;
	delete[] massiv2;

	return 0;
}

// Функция подсчёта среднего арифметического массива элементов
double arithmeticMean(int *massiv, int size)
{
	double varArithmeticMean = 0.0;

	for (int i = 0; i < size; i++)
	{
		varArithmeticMean += massiv[i];
	}

	varArithmeticMean /= size;

	return varArithmeticMean;
}
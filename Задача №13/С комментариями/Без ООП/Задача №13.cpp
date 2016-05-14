/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №13.
	Реализовать рекурсивную функцию-шаблон для быстрой сортировки массивов произвольных числовых типов. 
	Алгоритм быстрой сортировки описан в «Приложении».
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

/*
	Прототипы
*/
// Функция сортировки Хоара возрастающая
template <class Type>
void sortQuickIn(Type*, int, int);

// Функция сортировки Хоара убывающая
template <class Type>
void sortQuickDec(Type*, int, int);

// Функция вызова сортировки
template <class Type>
void sort(Type*, int, const char);

// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка русской раскладки

	cout << endl << endl << "Эказаменнационное задание №12" << endl << endl;

	// Размер массива
	int size;

	// Запрос размера массива
	cout << "Введите размер массива типа INT: ";
	cin >> size;

	// Создание массива типа INT размера size
	int *dataInt = new int[size];

	// Генерация значений для массива типа INT
	for (int i = 0; i < size; i++)
		dataInt[i] = rand() % (100 - (-100) + 1) + (-100);

	cout << endl << endl
		<< "Вывод несортированного массива: " << endl << endl;

	// Вывод неотсортированного массива типа INT
	for (int i = 0; i < size; i++)
		cout << dataInt[i] << " ";

	cout << endl << endl;

	// Сортировка массива по-возростанию
	sort(dataInt, size, '+');

	// Вывод отсортированного массива по-возростанию
	cout << "Отсортированный массив по-возростанию: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << dataInt[i] << " ";

	cout << endl << endl;

	// Сортировка массива по-убыванию
	sort(dataInt, size, '-');

	// Вывод отсортированного массива по-убыванию
	cout << "Отсортированный массив по-убыванию: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << dataInt[i] << " ";

	cout << endl << endl;

	// Запрос размера массива
	cout << "Введите размер массива типа DOUBLE: ";
	cin >> size;

	// Создание массива типа DOUBLE размера size
	double *dataDouble = new double[size];

	// Генерация значений для массива типа INT
	for (int i = 0; i < size; i++)
		dataDouble[i] = rand() % (100 - (-100) + 1) + (-100) + 0.5;

	cout << endl << endl
		<< "Вывод несортированного массива: " << endl << endl;

	// Вывод неотсортированного массива типа DOUBLE
	for (int i = 0; i < size; i++)
		cout << dataDouble[i] << " ";

	cout << endl << endl;

	// Сортировка массива по-возростанию
	sort(dataDouble, size, '+');

	// Вывод отсортированного массива по-возростанию
	cout << "Отсортированный массив по-возростанию: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << dataDouble[i] << " ";

	cout << endl << endl;

	// Сортировка массива по-убыванию
	sort(dataDouble, size, '-');

	// Вывод отсортированного массива по-убыванию
	cout << "Отсортированный массив по-убыванию: " << endl << endl;

	for (int i = 0; i < size; i++)
		cout << dataDouble[i] << " ";

	cout << endl << endl;

	return 0;
}

/*
	Реализации
*/
// Функция сортировки Хоара возрастающая
template <class Type>
void sortQuickIn(Type *data, int begin_0, int end_0)
{
	// Разделитель(элемент, относительно которого будем делить массив пополам(по-значению, а не по идексу)) для сравнивания элементов
	auto divider = data[end_0];

	// Индекс на начало массива
	auto begin = begin_0;

	// Индекс на конец массива
	auto end = end_0;

	do
	{
		// Поиск элемента большего разделителя
		while (data[begin] < divider)
			++begin;

		// Поиск элемента меньше разделителя
		while (data[end] > divider)
			--end;

		// Если начало и конец не вышли друг за друга
		if (begin <= end)
		{
			// Меняем элементы местами
			swap(data[begin], data[end]);

			// Увеличиваем индексы, чтобы выйти из цикла обработки do-while
			++begin;
			--end;
		}
	} while (begin <= end);

	// Сначало обрабатываем левую часть массив
	if (end > begin_0)
		sortQuickIn(data, begin_0, end);

	// Потом обрабатываем правую часть массив
	else if (begin < end_0)
		sortQuickIn(data, begin, end_0);
}

// Функция сортировки Хоара убывающая
template <class Type>
void sortQuickDec(Type *data, int begin_0, int end_0)
{
	// Разделитель(элемент, относительно которого будем делить массив пополам(по-значению, а не по идексу)) для сравнивания элементов
	auto divider = data[end_0];

	// Индекс на начало массива
	auto begin = begin_0;

	// Индекс на конец массива
	auto end = end_0;

	do
	{
		// Поиск элемента большего разделителя
		while (data[begin] > divider)
			++begin;

		// Поиск элемента меньше разделителя
		while (data[end] < divider)
			--end;

		// Если начало и конец не вышли друг за друга
		if (begin <= end)
		{
			// Меняем элементы местами
			swap(data[begin], data[end]);

			// Увеличиваем индексы, чтобы выйти из цикла обработки do-while
			++begin;
			--end;
		}
	} while (begin <= end);

	// Сначало обрабатываем левую часть массив
	if (end > begin_0)
		sortQuickDec(data, begin_0, end);

	// Потом обрабатываем правую часть массив
	else if (begin < end_0)
		sortQuickDec(data, begin, end_0);
}

// Функция управления
template <class Type>
void sort(Type *data, int size, const char vector)
{
	// Если сделан запрос на возростание
	if (vector == '+')
		sortQuickIn(data, 0, size - 1);

	// Если сделан запрос на убывание
	else if (vector == '-')
		sortQuickDec(data, 0, size - 1);
}
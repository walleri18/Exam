/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №8.
	Написать программу, которая для одномерного массива произвольного числового типа 
	определяет значение максимального и минимального элемента, а также среднее арифметическое значение элементов. 
	Использовать шаблон функции, которая принимает массив в качестве входного параметра, 
	возвращает минимум и максимум через выходные параметры, а среднее – через возвращаемое значение.
*/

/*
	Псевдо код:
	1. Дать пользоватлею выбор, какой массив он хочет;
	2. Попросить пользователя выбрать размер выбранного типа массива;
	3. Попросить пользователя заполнить массив тем что он хочет;
	4. Через шаблонную функцию вычислить максимальное, минимальное значение и среднее арифметическое;
*/


#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Прототипы
template <class Type>
double arithmeticMean(const Type*, const int, Type&, Type&);

// Наш класс массивов
template <class Type>
class Array
{
private:
	/*
		Основные данные
	*/
	Type *data;// Указатель на первый элемент массива
	int size;// Размер массива

public:
	Array();// Конструктор по-умолчанию
	~Array();// Деструктор по-умолчанию
	const Type* getData() const;// Геттер указателя на массив данных
	const int getSize() const;// Геттер размера массива

private:
	void sizeRequest();// Запрос размера массива
	void createMassiv();// Создание массива
	void addMassiv();// Заполнение массива
};

// Конструктор по-умолчанию
template<class Type>
Array<Type>::Array<Type>() : data(NULL), size(0) 
{
	// Узнаём желаемый размер
	this->sizeRequest();

	// Создаём
	this->createMassiv();

	// Заполняем
	this->addMassiv();
}

// Деструктор по-умолчанию
template<class Type>
Array<Type>::~Array<Type>()
{
	delete[] this->data;
}

// Геттер указателя на массив данных
template<class Type>
const Type * Array<Type>::getData() const
{
	return this->data;
}

// Геттер размера массива
template<class Type>
const int Array<Type>::getSize() const
{
	return this->size;
}

// Запрос размера массива
template<class Type>
void Array<Type>::sizeRequest()
{
	cout << endl << "Пожалуйста введите размер вашего массива: ";
	cin >> this->size;
}

// Создание массива
template<class Type>
void Array<Type>::createMassiv()
{
	this->data = new Type[this->size];
}

// Заполнение массива
template<class Type>
void Array<Type>::addMassiv()
{
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = rand() % (100 - (-100) + 1) + (-100);
	}
}

// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка русской раскладки

	cout << endl << endl << "Экзаменационное задание №8" << endl << endl;
	
	// Сообщение о том какой массив мы заполняем
	cout << "Массив типа INT" << endl << endl;

	// Массив целочисленный
	Array<int> array_int;
	int min_int = array_int.getData()[0];
	int max_int = array_int.getData()[0];
	double arithmeticMeanInt = arithmeticMean(array_int.getData(), array_int.getSize(), min_int, max_int);

	// Сообщение о том какой массив мы заполняем
	cout << endl << endl << "Массив типа DOUBLE" << endl << endl;

	// Массив вещественный
	Array<double> array_double;
	double min_double = array_double.getData()[0];
	double max_double = array_double.getData()[0];
	double arithmeticMeanDouble = arithmeticMean(array_double.getData(), array_double.getSize(), min_double, max_double);

	// Сообщение о том какой массив мы заполняем
	cout << endl << endl << "Массив типа CHAR" << endl << endl;

	// Массив символьный
	Array<char> array_char;
	char min_char = array_char.getData()[0];
	char max_char = array_char.getData()[0];
	double arithmeticMeanChar = arithmeticMean(array_char.getData(), array_char.getSize(), min_char, max_char);

	// Вывод
	cout << endl << endl << "Массив типа int:" << endl
		<< "Среднее арифметическое: " << arithmeticMeanInt << endl
		<< "Минимальное: " << min_int << endl
		<< "Максимальное: " << max_int << endl << endl
		<< "Массив типа double:" << endl
		<< "Среднее арифметическое: " << arithmeticMeanDouble << endl
		<< "Минимальное: " << min_double << endl
		<< "Максимальное: " << max_double << endl << endl
		<< "Массив типа char:" << endl
		<< "Среднее арифметическое: " << arithmeticMeanChar << endl
		<< "Минимальное: " << min_char << endl
		<< "Максимальное: " << max_char << endl << endl;

	return 0;
}

// Функция-шаблон подсчёта среднего арифметического, минимума и максимума массива элементов
template <class Type> 
double arithmeticMean(const Type *massiv, const int size, Type &min, Type &max)
{
	// Хранение среднего арифметического
	double varArithmeticMean = 0.0;

	// Считаем среднее арифметическое и ищем максимальное значение и минимальное
	for (int i = 0; i < size; i++)
	{
		
		varArithmeticMean += massiv[i];

		if (massiv[i] > max) 
			max = massiv[i];

		else if (massiv[i] < min) min = massiv[i];
	}

	varArithmeticMean /= size;

	return varArithmeticMean;
}
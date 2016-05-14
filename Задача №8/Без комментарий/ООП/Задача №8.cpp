#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <class Type>
double arithmeticMean(const Type*, const int, Type&, Type&);

template <class Type>
class Array
{
private:

	Type *data;
	int size;

public:
	Array();
	~Array();
	const Type* getData() const;
	const int getSize() const;

private:
	void sizeRequest();
	void createMassiv();
	void addMassiv();
};

template<class Type>
Array<Type>::Array<Type>() : data(NULL), size(0) 
{
	this->sizeRequest();

	this->createMassiv();

	this->addMassiv();
}

template<class Type>
Array<Type>::~Array<Type>()
{
	delete[] this->data;
}

template<class Type>
const Type * Array<Type>::getData() const
{
	return this->data;
}

template<class Type>
const int Array<Type>::getSize() const
{
	return this->size;
}

template<class Type>
void Array<Type>::sizeRequest()
{
	cout << endl << "Пожалуйста введите размер вашего массива: ";
	cin >> this->size;
}

template<class Type>
void Array<Type>::createMassiv()
{
	this->data = new Type[this->size];
}

template<class Type>
void Array<Type>::addMassiv()
{
	for (int i = 0; i < this->size; i++)
		this->data[i] = rand() % (100 - (-100) + 1) + (-100);
}

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Экзаменационное задание №8" << endl << endl;
	
	cout << "Массив типа INT" << endl << endl;

	Array<int> array_int;
	int min_int = array_int.getData()[0];
	int max_int = array_int.getData()[0];
	double arithmeticMeanInt = arithmeticMean(array_int.getData(), array_int.getSize(), min_int, max_int);

	cout << endl << endl << "Массив типа DOUBLE" << endl << endl;

	Array<double> array_double;
	double min_double = array_double.getData()[0];
	double max_double = array_double.getData()[0];
	double arithmeticMeanDouble = arithmeticMean(array_double.getData(), array_double.getSize(), min_double, max_double);

	cout << endl << endl << "Массив типа CHAR" << endl << endl;

	Array<char> array_char;
	char min_char = array_char.getData()[0];
	char max_char = array_char.getData()[0];
	double arithmeticMeanChar = arithmeticMean(array_char.getData(), array_char.getSize(), min_char, max_char);

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

template <class Type> 
double arithmeticMean(const Type *massiv, const int size, Type &min, Type &max)
{
	double varArithmeticMean = 0.0;

	for (int i = 0; i < size; i++)
	{
		varArithmeticMean += massiv[i];

		if (massiv[i] > max) 
			max = massiv[i];

		else if (massiv[i] < min) 
			min = massiv[i];
	}

	varArithmeticMean /= size;

	return varArithmeticMean;
}
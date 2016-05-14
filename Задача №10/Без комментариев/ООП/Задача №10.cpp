#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

template <class Type>
class DynamicArrayOfIntegers
{
private:

	Type *massiv;
	int sizeMassiv;
	int indexOfTheLast;

public:

	DynamicArrayOfIntegers();
	~DynamicArrayOfIntegers();
	int getSize() const;
	void addElement(Type);
	int getNumberOfElements() const;
	Type& operator [] (int index) const;

	friend ostream& operator << (ostream &stream, DynamicArrayOfIntegers<Type> &object)
	{
		stream << endl;

		for (int i = 0; i <= object.indexOfTheLast; i++)
			stream << "Элемент №" << i + 1 << ": " << right << object[i] << endl;

		return stream;
	}

private:

	void increasingTheSizeOfTheArray();
	bool isSizeMassivTheindexOfLast() const;
};

template <class Type>
DynamicArrayOfIntegers<Type>::DynamicArrayOfIntegers()
{
	this->massiv = new Type[10];
	this->sizeMassiv = 10;
	this->indexOfTheLast = -1;
}

template <class Type>
DynamicArrayOfIntegers<Type>::~DynamicArrayOfIntegers()
{
	delete[] this->massiv;
}

template <class Type>
int DynamicArrayOfIntegers<Type>::getSize() const
{
	return this->sizeMassiv;
}

template <class Type>
void DynamicArrayOfIntegers<Type>::addElement(Type number)
{
	if (this->isSizeMassivTheindexOfLast()) 
		increasingTheSizeOfTheArray();

	this->massiv[indexOfTheLast + 1] = number;
	this->indexOfTheLast++;
}

template <class Type>
int DynamicArrayOfIntegers<Type>::getNumberOfElements() const
{
	return this->indexOfTheLast + 1;
}

template <class Type>
Type& DynamicArrayOfIntegers<Type>::operator [] (int index) const
{
	return this->massiv[index];
}

template <class Type>
void DynamicArrayOfIntegers<Type>::increasingTheSizeOfTheArray()
{
	Type *newMassiv = new Type[this->sizeMassiv * 2];

	for (int i = 0; i <= this->indexOfTheLast; i++)
		newMassiv[i] = massiv[i];

	delete[] this->massiv;

	this->massiv = newMassiv;
	this->sizeMassiv *= 2;
}

template <class Type>
bool DynamicArrayOfIntegers<Type>::isSizeMassivTheindexOfLast() const
{
	return (this->indexOfTheLast == this->sizeMassiv - 1);
}

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Эказаменнационное задание №10" << endl << endl;

	cout << "Массив целых чисел" << endl << endl;

	DynamicArrayOfIntegers<int> massivInt;
	
	for (int i = 0; i < 100; i++)
		massivInt.addElement(rand() % (100 - (-100) + 1) + (-100));
	
	cout << massivInt;

	cout << endl << endl << "Массив вещественных чисел:" << endl << endl;

	DynamicArrayOfIntegers<double> massivDouble;

	for (int i = 0; i < 100; i++)
		massivDouble.addElement(rand() % (100 - (-100) + 1) + (-100) + 0.5);

	cout << massivDouble;

	return 0;
}
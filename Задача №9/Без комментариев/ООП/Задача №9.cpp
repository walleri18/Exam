#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class DynamicArrayOfIntegers
{
private:

	int *massiv;
	int sizeMassiv;
	int indexOfTheLast;

public:

	DynamicArrayOfIntegers();
	~DynamicArrayOfIntegers();
	int getSize() const;
	void addElement(int);
	int getNumberOfElements() const;
	int& operator [] (int index) const;
	friend ostream& operator << (ostream&, DynamicArrayOfIntegers&);

private:

	void increasingTheSizeOfTheArray();
	bool isSizeMassivTheindexOfLast() const;
};

DynamicArrayOfIntegers::DynamicArrayOfIntegers()
{
	this->massiv = new int[10];
	this->sizeMassiv = 10;
	this->indexOfTheLast = -1;
}

DynamicArrayOfIntegers::~DynamicArrayOfIntegers()
{
	delete[] this->massiv;
}

int DynamicArrayOfIntegers::getSize() const
{
	return this->sizeMassiv;
}

void DynamicArrayOfIntegers::addElement(int number)
{
	if (this->isSizeMassivTheindexOfLast()) 
		increasingTheSizeOfTheArray();

	this->massiv[indexOfTheLast + 1] = number;
	this->indexOfTheLast++;
}

int DynamicArrayOfIntegers::getNumberOfElements() const
{
	return this->indexOfTheLast + 1;
}

int& DynamicArrayOfIntegers::operator [] (int index) const
{
	return this->massiv[index];
}

void DynamicArrayOfIntegers::increasingTheSizeOfTheArray()
{
	int *newMassiv = new int[this->sizeMassiv * 2];

	for (int i = 0; i <= this->indexOfTheLast; i++)
		newMassiv[i] = massiv[i];

	delete[] this->massiv;

	this->massiv = newMassiv;
	this->sizeMassiv *= 2;
}

bool DynamicArrayOfIntegers::isSizeMassivTheindexOfLast() const
{
	return (this->indexOfTheLast == this->sizeMassiv - 1);
}

ostream & operator << (ostream &stream, DynamicArrayOfIntegers &object)
{
	stream << endl;

	for (int i = 0; i <= object.indexOfTheLast; i++)
		stream << "Элемент №" << i + 1 << ": " << right << object[i] << endl;

	return stream;
}

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Эказаменнационное задание №9" << endl << endl;

	DynamicArrayOfIntegers massiv;
	
	for (int i = 0; i < 100; i++)
		massiv.addElement(rand() % (100 - (-100) + 1) + (-100));

	cout << massiv;

	return 0;
}
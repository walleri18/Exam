#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class Array
{
private:

	int *data;
	int size;

	int indexMinimumElement;
	int minimumElement;
	int indexMaximumElement;
	int maximumElement;
	int numberElements;

public:

	Array();
	virtual ~Array();
	
private:

	void sizeRequest();
	void add();
	void show();
	void createArray();
	void wantedIndexMinimumElement();
	void wantedIndexMaximumElement();
	void wantedIndexElement();
	void thinkPositive(int, int);
	void countingNumber();
	
};

Array::Array()
{
	this->show();
}

Array::~Array()
{
	delete[] this->data;
}

void Array::sizeRequest()
{
	cout << endl << "Пожалуйста, введите размер массива: ";
	cin >> this->size;

	this->createArray();

	this->add();
}

void Array::createArray()
{
	this->data = new int[this->size];
}

void Array::wantedIndexMinimumElement()
{
	int minElement = this->data[0];
	int minIndex = 0;

	for (int i = 1; i < this->size; i++)
	{
		if (this->data[i] < minElement) {
			minElement = this->data[i];
			minIndex = i;
		}
	}

	this->indexMinimumElement = minIndex;

	this->minimumElement = minElement;
}

void Array::wantedIndexMaximumElement()
{
	int maxElement = this->data[0];
	int maxIndex = 0;

	for (int i = 1; i < this->size; i++)
	{
		if (this->data[i] > maxElement) {
			maxElement = this->data[i];
			maxIndex = i;
		}
	}

	this->indexMaximumElement = maxIndex;

	this->maximumElement = maxElement;
}

void Array::wantedIndexElement()
{
	this->wantedIndexMaximumElement();
	this->wantedIndexMinimumElement();
}

void Array::thinkPositive(int min, int max)
{
	int enumerator(0);

	for (int i = min + 1; i < max; i++)
	{
		if (this->data[i] > 0) enumerator++;
	}

	this->numberElements = enumerator;
}

void Array::add()
{
	cout << endl << "Заполнение массива:" << endl;

	for (int i = 0; i < size; i++)
		data[i] = rand() % (100 - (-100) + 1) + (-100);
	
}

void Array::show()
{
	this->sizeRequest();

	this->countingNumber();

	for (int i = 0; i < this->size; i++)
	{
		if (i < this->size - 1)
			cout << this->data[i] << ", ";
		else
			cout << this->data[i] << endl << endl;
	}

	cout << endl << "Минимальный элемент массива: " << this->minimumElement 
	<< ". Его индекс: " << this->indexMinimumElement << endl
		<< "Максимальный элемент массива: " << this->maximumElement 
		<< ". Его индекс: " << this->indexMaximumElement << endl
		<< "Количество элементов массива, между масимальным значение и минимальным: " 
		<< this->numberElements << endl;
}

void Array::countingNumber()
{
	this->wantedIndexElement();

	if (this->indexMinimumElement > this->indexMaximumElement) 
		thinkPositive(this->indexMaximumElement, this->indexMinimumElement);

	else if (this->indexMaximumElement > this->indexMinimumElement) 
		thinkPositive(this->indexMinimumElement, this->indexMaximumElement);
}

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Экзаменационное задание №3" << endl << endl;

	Array massiv;

	return 0;
}
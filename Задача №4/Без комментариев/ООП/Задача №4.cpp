#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class Array
{
private:

	double *data;
	int size;

	int indexLastNegative;
	double lastNegativeElement;
	double summaAfterIndexLastNegative;
	bool isNegativElement;

public:
	Array();
	~Array();
	
private:
	void sizeRequest();
	void createArray();
	void add();
	void wantedLastNegativeElement();
	void summation();
	void show();
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
	this->data = new double[this->size];
}

void Array::add()
{
	cout << endl << "Заполнение массива:" << endl;

	for (int i = 0; i < size; i++)
		data[i] = rand() % (100 - (-100) + 1) + (-100);
}

void Array::wantedLastNegativeElement()
{
	double lastNegativeElement(0);

	int indexLastNegativeElement(0);

	int numberNegativeElements(0);

	for (int i = indexLastNegativeElement + 1; i < size; i++)
	{
		if (this->data[i] < 0) {
			numberNegativeElements++;
			lastNegativeElement = this->data[i];
			indexLastNegativeElement = i;
		}
	}
	
	isNegativElement = (numberNegativeElements > 0) ? true : false;

	this->indexLastNegative = indexLastNegativeElement;
	this->lastNegativeElement = lastNegativeElement;
}

void Array::summation()
{
	this->wantedLastNegativeElement();

	double summa(0);
	
	if (isNegativElement)
		for (int i = this->indexLastNegative + 1; i < this->size; i++)
			summa += this->data[i];

	this->summaAfterIndexLastNegative = summa;
}

void Array::show()
{
	this->sizeRequest();

	this->summation();
	
	for (int i = 0; i < this->size; i++)
	{
		if (i < this->size - 1)
			cout << this->data[i] << ", ";
		else
			cout << this->data[i] << endl << endl;
	}

	if (isNegativElement)
		cout << endl << "Значение последнего отрицательного элемента массива: " 
		<< this->lastNegativeElement << ". Его индекс: " << this->indexLastNegative << endl
		<< "Сумма элементов, расположенных правее последнего отрицательного элемента: " 
		<< this->summaAfterIndexLastNegative << endl;
	else
		cout << endl << "В массиве нет отрицательных элементов!!!";
}


int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Экзаменационное задание №4" << endl << endl;

	Array mass;

	return 0;
}
#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Экзаменационное задание №4" << endl << endl;

	double *data(NULL);
	int size(0);

	int indexLastNegative(0);
	double lastNegativeElement(0);
	int summaAfterIndexLastNegative(0);
	bool isNegativElement(false);

	cout << endl << "Пожалуйста, введите размер массива: ";
	cin >> size;

	data = new double[size];

	for (int i = 0; i < size; i++)
		data[i] = rand() % (100 - (-100) + 1) + (-100);

	int numberNegativeElements(0);

	for (int i = indexLastNegative + 1; i < size; i++)
	{
		if (data[i] < 0) {
			numberNegativeElements++;
			lastNegativeElement = data[i];
			indexLastNegative = i;
		}
	}

	isNegativElement = (numberNegativeElements > 0) ? true : false;

	if (isNegativElement)
		for (int i = indexLastNegative + 1; i < size; i++)
			summaAfterIndexLastNegative += data[i];

	for (int i = 0; i < size; i++)
	{
		if (i < size - 1)
			cout << data[i] << ", ";
		else
			cout << data[i] << endl << endl;
	}

	if (isNegativElement)
		cout << endl << "Значение последнего отрицательного элемента массива: " << 
	lastNegativeElement << ". Его индекс: " << indexLastNegative << endl
			<< "Сумма элементов, расположенных правее последнего отрицательного элемента: " 
			<< summaAfterIndexLastNegative << endl;
	else
		cout << endl << "В массиве нет отрицательных элементов!!!";

	delete[] data;

	return 0;
}
/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №4.
	Из вещественного массива N, после последнего отрицательного элемента, посчитать сумму элементов массива.
*/

/*
	Псевдо код:
	1. Спросить пользователя о том, какого размера массив;
	2. Создать определённого размера массив;
	3. Пусть пользователь заполнит его случайными числами;
	4. Обработаем массив и найдём индекс последнего отрицательного элемента;
	5. Посчитаем сумму элементов, расположенных правее последнего отрицательного элемента в массиве.
*/
#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class Array
{
	
// Данные
private:

	/*
		Основные данные
	*/
	double *data;// Указатель на массив вещественных чисел
	int size;// Размер массива

	/*
		Дополнительные данные
	*/
	int indexLastNegative;// Индекс последнего отрицательного числа
	double lastNegativeElement;// Значение последнего отрицательного элемента
	double summaAfterIndexLastNegative;// Сумма чисел после последнего негативного числа
	bool isNegativElement;// Есть ли отрицательные элементы в массиве

// Функции (методы)
public:
	Array();// Конструктор по умолчанию без параметров
	~Array();// Деструктор по умолчанию
private:
	void sizeRequest();// Запрос размера массива
	void createArray();// Создание массива определённого размера
	void add(); // Заполнение массива
	void wantedLastNegativeElement();// Поиск последнего отрицательного элемента
	void summation();// Суммирование чисел после последнего отрицательного элемента
	void show();// Вывод результата
};

// Конструктор по умолчанию без параметров
Array::Array()
{
	this->show();
}

// Деструктор по умолчанию
Array::~Array()
{
	delete[] this->data;
}

// Запрос пользователя о размере массива
void Array::sizeRequest()
{
	// Запрос у пользователя о размере желаемого массива
	cout << endl << "Пожалуйста, введите размер массива: ";
	cin >> this->size;

	// Создание массива определённого размера
	this->createArray();

	// Заполнение массива
	this->add();
}

// Создание массива в области
void Array::createArray()
{
	// Выделение области памяти на массив определённого размера
	this->data = new double[this->size];
}

// Добавление элементов в массив
void Array::add()
{
	// Призыв заполнения массива
	cout << endl << "Заполнение массива:" << endl;

	// Заполнение массива
	for (int i = 0; i < size; i++)
	{
		// Заполнение массива случайными числами от -100 до 100

		//Формула случайного числа в диапозоне [min, max]:
		//random_number = rand() % (max - min + 1) + min;

		data[i] = rand() % (100 - (-100) + 1) + (-100);
	}
}

// Поиск последнего отрицательного элемента
void Array::wantedLastNegativeElement()
{
	//Последний отрицательный элемент
	double lastNegativeElement(0);

	// Индекс последнего отрицательного элемента
	int indexLastNegativeElement(0);

	// Количество отрицательных элементов
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
	
	// Запись данных
	this->indexLastNegative = indexLastNegativeElement;
	this->lastNegativeElement = lastNegativeElement;
}

// Суммирование чисел после последнего отрицательного элемента
void Array::summation()
{
	// Поиск последнего отрицательного элемента
	this->wantedLastNegativeElement();

	// Локальная сумма
	double summa(0);
	
	if (isNegativElement)
	{
		// Суммирование
		for (int i = this->indexLastNegative + 1; i < this->size; i++)
		{
			summa += this->data[i];
		}
	}
	
	// Запись суммы
	this->summaAfterIndexLastNegative = summa;
}

// Вывод результата
void Array::show()
{
	// Создание массива
	this->sizeRequest();

	// Начало суммирования
	this->summation();
	
	// Вывог сгенерированного массива
	for (int i = 0; i < this->size; i++)
	{
		if (i < this->size - 1)
			cout << this->data[i] << ", ";
		else
			cout << this->data[i] << endl << endl;
	}

	if (isNegativElement)
	{
		// Вывод результата
		cout << endl << "Значение последнего отрицательного элемента массива: " << this->lastNegativeElement << ". Его индекс: " << this->indexLastNegative << endl
			<< "Сумма элементов, расположенных правее последнего отрицательного элемента: " << this->summaAfterIndexLastNegative << endl;
	}
	else
	{
		cout << endl << "В массиве нет отрицательных элементов!!!";
	}
}

// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	cout << endl << endl << "Экзаменационное задание №4" << endl << endl;

	// Создание объекта массив и выполнение всей программы
	Array mass;

	return 0;
}
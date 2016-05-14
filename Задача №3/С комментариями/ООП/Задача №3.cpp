/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №3.
	Из целочисленного массива N, между максимальным и минимальным элементом подсчитать количество положительных чисел.
*/

/*
	Псевдо код:
	1. Спросить пользователя о том, какого размера массив;
	2. Создать определённого размера массив;
	3. Пусть пользователь заполнит его случайными числами;
	4. Обработаем массив и найдём индексы максимального элемента массива и минимального;
	5. С самого минимального индекса начнём поиск положительны чисел и подсчитаем их.
*/
#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

// Наш тип массива
class Array
{
	
// Данные
private:

	/*
		Основные данные объекта
	*/
	int *data;// Указатель на первый элемент массива
	int size;// Размер массива

	/*
		Дополнительные данные объекта
	*/
	int indexMinimumElement;// Индекс минимального элемента массива
	int minimumElement;// Минимальный элемент
	int indexMaximumElement;// Индекс максимального элемента массива
	int maximumElement;// Максимальный элемент
	int numberElements;// Количество элементов между минимальным и максимальным элементов массива
	
// Функции (методы)
public:

	Array();// Конструктор по умолчанию
	~Array();// Деструктор по умолчанию
	
private:

	void sizeRequest();// Запрос пользователя о размере массива
	void add();// Добавление элементов в массив
	void show();// Вывод результата
	void createArray();// Создание массива в области
	void wantedIndexMinimumElement();// Поиск минимального элемента массива
	void wantedIndexMaximumElement();// Поиск максимального элемента массива
	void wantedIndexElement();// Для вызова wantedIndexMinimumElement и wantedIndexMaximumElement
	void thinkPositive(int, int);// Подсчёт количества положительных элементов
	void countingNumber();// Подсчёт количества элементов между максимальным и минимальным
	
};

// Конструктор по умолчанию
Array::Array()
{
	// Я знаю, что так делать не надо, но ведь работает)	
	// Вывод
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
	this->data = new int[this->size];
}

// Поиск минимального элемента массива
void Array::wantedIndexMinimumElement()
{
	// Примем условно, что первый элемент массива минимальный
	int minElement = this->data[0];
	int minIndex = 0;

	// Поиск самого маленького элемента массива
	for (int i = 1; i < this->size; i++)
	{
		// Если текущий элемент массива меньше минимального
		if (this->data[i] < minElement) {
			// Присваиваем минимальному элементу значение текущего и запоминаем его индекс
			minElement = this->data[i];
			minIndex = i;
		}
	}

	// Записываем индекс минимального элемента
	this->indexMinimumElement = minIndex;

	// Записываем минимальный элемент
	this->minimumElement = minElement;
}

// Поиск максимального элемента массива
void Array::wantedIndexMaximumElement()
{
	// Примем условно, что первый элемент массива максимальный
	int maxElement = this->data[0];
	int maxIndex = 0;

	// Поиск самого большого элемента массива
	for (int i = 1; i < this->size; i++)
	{
		// Если текущий элемент массива больше минимального
		if (this->data[i] > maxElement) {
			// Присваиваем максимальному элементу значение текущего и запоминаем его индекс
			maxElement = this->data[i];
			maxIndex = i;
		}
	}

	// Записываем индекс максимального элемента
	this->indexMaximumElement = maxIndex;

	// Записываем максимальный элемент
	this->maximumElement = maxElement;
}

// Для вызова wantedIndexMinimumElement и wantedIndexMaximumElement
void Array::wantedIndexElement()
{
	this->wantedIndexMaximumElement();
	this->wantedIndexMinimumElement();
}

// Подсчёт количества элементов
void Array::thinkPositive(int min, int max)
{
	// Количество положительных элементов
	int enumerator(0);

	// Подсчёт количества положительных элементов
	for (int i = min + 1; i < max; i++)
	{
		if (this->data[i] > 0) enumerator++;
	}

	// Запись количества положительных элементов
	this->numberElements = enumerator;
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

void Array::show()
{
	// Запрос и создание массива
	this->sizeRequest();

	// Вычисления(выполнение условий задачи)
	this->countingNumber();

	// Вывод сгенерированных элементов массива
	for (int i = 0; i < this->size; i++)
	{
		if (i < this->size - 1)
			cout << this->data[i] << ", ";
		else
			cout << this->data[i] << endl << endl;
	}

	// Вывод результата
	cout << endl << "Минимальный элемент массива: " << this->minimumElement << ". Его индекс: " << this->indexMinimumElement << endl
		<< "Максимальный элемент массива: " << this->maximumElement << ". Его индекс: " << this->indexMaximumElement << endl
		<< "Количество элементов массива, между масимальным значение и минимальным: " << this->numberElements << endl;
}

// Подсчёт количества элементов между максимальным и минимальным
void Array::countingNumber()
{
	// Поис индексов элементов
	this->wantedIndexElement();

	// Если индекс минимального элемента больше индекса максимального элемента
	if (this->indexMinimumElement > this->indexMaximumElement) 
		thinkPositive(this->indexMaximumElement, this->indexMinimumElement);

	// Если индекс максимального элемента больше индекса минимального элемента
	else if (this->indexMaximumElement > this->indexMinimumElement) 
		thinkPositive(this->indexMinimumElement, this->indexMaximumElement);
}

// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	cout << endl << endl << "Экзаменационное задание №3" << endl << endl;

	// Создание объекта массив и выполнение над операций
	Array massiv;

	return 0;
}
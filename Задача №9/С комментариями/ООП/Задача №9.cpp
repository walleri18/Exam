/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №9.
	Описать класс «динамический массив целых чисел». 
	В классе реализовать конструктор по умолчанию, деструктор, метод добавления элемента в массив, 
	метод получения количества элементов в массиве, 
	операцию индексирования (параметр операции – целочисленный индекс элемента, 
	возвращаемое значение – ссылка на элемент массива, соответствующий индексу). 
	Перегрузить операцию вывода массива в стандартный поток ostream.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class DynamicArrayOfIntegers
{
// Данные
private:
	/*
		Основные данные
	*/
	int *massiv;// Указатель на первый элемент массива
	int sizeMassiv;// Размер массива
	int indexOfTheLast;// Индекс последнего элемента массива

// Функции (методы)
public:

	DynamicArrayOfIntegers();// Конструктор по-умолчанию
	~DynamicArrayOfIntegers();//Деструктор по-умолчанию
	int getSize() const;// Геттер размера массива
	void addElement(int);// Метод добавления элемента в массив
	int getNumberOfElements() const;// Метод получения количества элементов в массиве
	int& operator [] (int index) const;// Операция индексирования
	friend ostream& operator << (ostream&, DynamicArrayOfIntegers&);// Операция вывода в поток

private:

	void increasingTheSizeOfTheArray();// Метод увеличения массива
	bool isSizeMassivTheindexOfLast() const;// Метод проверка вышел ли массив за пределы
};

// Конструктор без параметров
DynamicArrayOfIntegers::DynamicArrayOfIntegers()
{
	// Начальные настройки
	this->massiv = new int[10];
	this->sizeMassiv = 10;
	this->indexOfTheLast = -1;
}

//Деструктор без параметров
DynamicArrayOfIntegers::~DynamicArrayOfIntegers()
{
	delete[] this->massiv;
}


// Геттер размера массива
int DynamicArrayOfIntegers::getSize() const
{
	return this->sizeMassiv;
}

// Метод добавления элемента в массив
void DynamicArrayOfIntegers::addElement(int number)
{
	// Если массив выходит за пределы, то увеличиваем его размер в два раза
	if (this->isSizeMassivTheindexOfLast()) 
		increasingTheSizeOfTheArray();

	// Добавляем новые значения
	this->massiv[indexOfTheLast + 1] = number;
	this->indexOfTheLast++;
}

// Метод получения количества элементов в массиве
int DynamicArrayOfIntegers::getNumberOfElements() const
{
	return this->indexOfTheLast + 1;
}

// Операция индексирования
int& DynamicArrayOfIntegers::operator [] (int index) const
{
	return this->massiv[index];
}

// Метод увеличения массива
void DynamicArrayOfIntegers::increasingTheSizeOfTheArray()
{
	// Выделение памяти на массив в два раза больше предыдущий
	int *newMassiv = new int[this->sizeMassiv * 2];

	// Копирование элементов в новый массив
	for (int i = 0; i <= this->indexOfTheLast; i++)
	{
		newMassiv[i] = massiv[i];
	}
	
	// Удаление старой памяти
	delete[] this->massiv;

	// Занесение новых значений в объект
	this->massiv = newMassiv;
	this->sizeMassiv *= 2;
}

// Метод проверка вышел ли массив за пределы
bool DynamicArrayOfIntegers::isSizeMassivTheindexOfLast() const
{
	// Если последний элемент массива равен размер минус единица, то возвращаем true, в противном случае false
	return (this->indexOfTheLast == this->sizeMassiv - 1);
}

// Операция вывода в поток
ostream & operator << (ostream &stream, DynamicArrayOfIntegers &object)
{
	stream << endl;

	for (int i = 0; i <= object.indexOfTheLast; i++)
		stream << "Элемент №" << i + 1 << ": " << right << object[i] << endl;

	return stream;
}

// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка русской раскладки

	cout << endl << endl << "Эказаменнационное задание №9" << endl << endl;

	// Создаём динамический массив
	DynamicArrayOfIntegers massiv;
	
	// Заполняем его случайными числами от -100 до 100
	for (int i = 0; i < 100; i++)
	{
		massiv.addElement(rand() % (100 - (-100) + 1) + (-100));
	}
	
	// Выводим массив на консоль
	cout << massiv;

	return 0;
}
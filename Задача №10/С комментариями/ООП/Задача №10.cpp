/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №10.
	Описать шаблон класс «динамический массив». 
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

template <class Type>
class DynamicArrayOfIntegers
{
// Данные
private:
	/*
		Основные данные
	*/
	Type *massiv;// Указатель на первый элемент массива
	int sizeMassiv;// Размер массива
	int indexOfTheLast;// Индекс последнего элемента массива

// Функции (методы)
public:

	DynamicArrayOfIntegers();// Конструктор по-умолчанию
	~DynamicArrayOfIntegers();//Деструктор по-умолчанию
	int getSize() const;// Геттер размера массива
	void addElement(Type);// Метод добавления элемента в массив
	int getNumberOfElements() const;// Метод получения количества элементов в массиве
	Type& operator [] (int index) const;// Операция индексирования

	// Операция вывода в поток
	friend ostream& operator << (ostream &stream, DynamicArrayOfIntegers<Type> &object)
	{
		stream << endl;

		for (int i = 0; i <= object.indexOfTheLast; i++)
			stream << "Элемент №" << i + 1 << ": " << right << object[i] << endl;

		return stream;
	}

private:

	void increasingTheSizeOfTheArray();// Метод увеличения массива
	bool isSizeMassivTheindexOfLast() const;// Метод проверка вышел ли массив за пределы
};

// Конструктор без параметров
template <class Type>
DynamicArrayOfIntegers<Type>::DynamicArrayOfIntegers()
{
	// Начальные настройки
	this->massiv = new Type[10];
	this->sizeMassiv = 10;
	this->indexOfTheLast = -1;
}

//Деструктор без параметров
template <class Type>
DynamicArrayOfIntegers<Type>::~DynamicArrayOfIntegers()
{
	delete[] this->massiv;
}


// Геттер размера массива
template <class Type>
int DynamicArrayOfIntegers<Type>::getSize() const
{
	return this->sizeMassiv;
}

// Метод добавления элемента в массив
template <class Type>
void DynamicArrayOfIntegers<Type>::addElement(Type number)
{
	// Если массив выходит за пределы, то увеличиваем его размер в два раза
	if (this->isSizeMassivTheindexOfLast()) 
		increasingTheSizeOfTheArray();

	// Добавляем новые значения
	this->massiv[indexOfTheLast + 1] = number;
	this->indexOfTheLast++;
}

// Метод получения количества элементов в массиве
template <class Type>
int DynamicArrayOfIntegers<Type>::getNumberOfElements() const
{
	return this->indexOfTheLast + 1;
}

// Операция индексирования
template <class Type>
Type& DynamicArrayOfIntegers<Type>::operator [] (int index) const
{
	return this->massiv[index];
}

// Метод увеличения массива
template <class Type>
void DynamicArrayOfIntegers<Type>::increasingTheSizeOfTheArray()
{
	// Выделение памяти на массив в два раза больше предыдущий
	Type *newMassiv = new Type[this->sizeMassiv * 2];

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
template <class Type>
bool DynamicArrayOfIntegers<Type>::isSizeMassivTheindexOfLast() const
{
	// Если последний элемент массива равен размер минус единица, то возвращаем true, в противном случае false
	return (this->indexOfTheLast == this->sizeMassiv - 1);
}

// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка русской раскладки

	cout << endl << endl << "Эказаменнационное задание №10" << endl << endl;

	cout << "Массив целых чисел" << endl << endl;

	// Создаём динамический массив
	DynamicArrayOfIntegers<int> massivInt;
	
	// Заполняем его случайными числами от -100 до 100
	for (int i = 0; i < 100; i++)
	{
		massivInt.addElement(rand() % (100 - (-100) + 1) + (-100));
	}
	
	// Выводим массив на консоль
	cout << massivInt;

	cout << endl << endl << "Массив вещественных чисел:" << endl << endl;

	// Создаём динамический массив
	DynamicArrayOfIntegers<double> massivDouble;

	// Заполняем его случайными числами от -100 до 100
	for (int i = 0; i < 100; i++)
	{
		massivDouble.addElement(rand() % (100 - (-100) + 1) + (-100) + 0.5);
	}

	// Выводим массив на консоль
	cout << massivDouble;

	return 0;
}
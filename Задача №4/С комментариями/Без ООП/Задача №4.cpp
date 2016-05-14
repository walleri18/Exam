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


// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	cout << endl << endl << "Экзаменационное задание №4" << endl << endl;

	/*
		Основные данные
	*/
	double *data(NULL);// Указатель на массив вещественных чисел
	int size(0);// Размер массива

	/*
		Дополнительные данные
	*/
	int indexLastNegative(0);// Индекс последнего отрицательного числа
	double lastNegativeElement(0);// Значение последнего отрицательного элемента
	int summaAfterIndexLastNegative(0);// Сумма чисел после последнего негативного числа
	bool isNegativElement(false);// Есть ли отрицательные элементы в массиве
	
	// Запрос у пользователя о размере желаемого массива
	cout << endl << "Пожалуйста, введите размер массива: ";
	cin >> size;
	
	// Создание массива
	data = new double[size];

	// Заполнение массива
	for (int i = 0; i < size; i++)
	{
		// Заполнение массива случайными числами от -100 до 100

		//Формула случайного числа в диапозоне [min, max]:
		//random_number = rand() % (max - min + 1) + min;

		data[i] = rand() % (100 - (-100) + 1) + (-100);
	}
	
	// Поиск последнего отрицательного числа
	// Количество отрицательных элементов
	int numberNegativeElements(0);
	
	// Считаем и ищем последний отрицательный элемент
	for (int i = indexLastNegative + 1; i < size; i++)
	{
		if (data[i] < 0) {
			numberNegativeElements++;
			lastNegativeElement = data[i];
			indexLastNegative = i;
		}
	}
	
	// Воспользуемся тернарным оператором условия и узнаем - есть ли у нас вообще отрицательные элементы
	isNegativElement = (numberNegativeElements > 0) ? true : false;
	
	// Если есть отрицательные элементы, то суммируем после последнего числа
	if (isNegativElement)
	{
		// Суммирование
		for (int i = indexLastNegative + 1; i < size; i++)
		{
			summaAfterIndexLastNegative += data[i];
		}
	}
	
	// Вывод сгенерированного массива
	for (int i = 0; i < size; i++)
	{
		if (i < size - 1)
			cout << data[i] << ", ";
		else
			cout << data[i] << endl << endl;
	}

	// Вывод результата
	if (isNegativElement)
	{
		// Вывод результата
		cout << endl << "Значение последнего отрицательного элемента массива: " << lastNegativeElement << ". Его индекс: " << indexLastNegative << endl
			<< "Сумма элементов, расположенных правее последнего отрицательного элемента: " << summaAfterIndexLastNegative << endl;
	}
	else
	{
		cout << endl << "В массиве нет отрицательных элементов!!!";
	}
	
	// Очистка памяти
	delete[] data;

	return 0;
}
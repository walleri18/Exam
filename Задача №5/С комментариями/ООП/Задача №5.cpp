/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №5.
	Из целочисленной матрицы NxM, найти среднее арифметическое её элементов и количество отрицательных и положительных элементов в каждой строке.
*/

/*
	Псевдо код:
	1. Спросить пользователя о том, сколько строк и столбцов в матрице;
	2. Создать определённого размера матрицу(двумерный массив);
	3. Пусть пользователь заполнит его случайными числами;
	4. Найдём среднее арифметическое элементов матрицы;
	5. Посчитаем количество положительных и отрицательных элементов в каждой строке.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class Matrix
{
// Данные
private:

	/*
		Основные данные
	*/
	int line_matrix;// Количество строк
	int column_matrix;// Количество колонн
	int **matrix;// Указатель на первый элемент матрицы
	
	/*
		Дополнительные данные
	*/
	int *numberPositive;// Массив с количествами положительных элементов в строке
	int *numberNegative;// Массив с количествами отрицательных элементов в строке
	double arithmeticMean_matrix;// Среднее арифметическое матрицы
	
public:
	Matrix();// Конструктор по-умолчанию
	~Matrix();// Деструктор по-умолчанию

private:
	void sizeRequest();// Запрос размера матрицы
	void createMatrix();// Создание матрицы определённого размера
	void add(); // Заполнение матрицы
	void calculateArithmeticMean();// Расчёт среднего арифметического
	void calculatePositiveNegative();// Подсчёт положительных и отрицательных элементов в строках матрицы
	void calculate();// Вычисления и все остальные запросы
	void show();// Вывод результата
};

// Конструктор по-умолчанию
Matrix::Matrix() : line_matrix(0), column_matrix(0), 
	matrix(NULL), numberPositive(NULL), 
	numberNegative(NULL), arithmeticMean_matrix(0)
{
	// Так делать не рекумендуется, но зато в main всего лишь нужна одна строчка для запуска
	this->show();
}

// Деструктор по-умолчанию
Matrix::~Matrix()
{
	// Удаление под-массивов(столбцов)
	for (int i = 0; i < this->line_matrix; i++)
	{
		delete[] this->matrix[i];
	}
	
	// Удаление строк
	delete[] this->matrix;

	delete[] this->numberNegative;
	delete[] this->numberPositive;
}

// Запрос размера матрицы
void Matrix::sizeRequest()
{
	cout << endl << "Пожалуйста, введите необходимое количество строк в матрице: ";
	cin >> this->line_matrix;

	cout << endl << "Пожалуйста, введите необходимое количество столбцов в матрице: ";
	cin >> this->column_matrix;
}

// Создание матрицы
void Matrix::createMatrix()
{
	// Создаём строки
	this->matrix = new int* [this->line_matrix];
	
	// Создаём столбцы
	for (int i = 0; i < this->line_matrix; i++) 
		this->matrix[i] = new int[this->column_matrix];
	
	// Создаём массив для количества положительных элементов
	this->numberPositive = new int[this->line_matrix];
	
	// Зануляем массив для хранения количества положительных элементов
	for (int i = 0; i < this->line_matrix; i++) 
		this->numberPositive[i] = 0;
	
	// Создаём массив для количества отрицательных элементов
	this->numberNegative = new int[this->line_matrix];
	
	// Зануляем массив для хранения количества отрицательных элементов
	for (int i = 0; i < this->line_matrix; i++) 
		this->numberNegative[i] = 0;
}

// Заполнение матрицы
void Matrix::add()
{
	for (int i = 0; i < this->line_matrix; i++)
	{		
		for (int j = 0; j < this->column_matrix; j++)
		{			
			this->matrix[i][j] = rand() % (100 - (-100) + 1) + (-100);
		}
	}
}

// Расчёт среднего арифметического матрицы
void Matrix::calculateArithmeticMean()
{
	// Суммирование всех элементов
	for (int i = 0; i < this->line_matrix; i++)
	{
		for (int j = 0; j < this->column_matrix; j++)
		{
			this->arithmeticMean_matrix += this->matrix[i][j];
		}
	}
	
	// Деление суммы всех элементов на их количество
	this->arithmeticMean_matrix /= (this->line_matrix * this->column_matrix);
}

// Подсчёт положительных и отрицательных элементов в строках матрицы
void Matrix::calculatePositiveNegative()
{
	for (int i = 0; i < this->line_matrix; i++)
	{
		for (int j = 0; j < this->column_matrix; j++)
		{
			// В случае если число положительное
			if (this->matrix[i][j] > 0) 
				this->numberPositive[i]++;
			
			// В случае если число отрицательное
			else if (this->matrix[i][j] < 0) 
				this->numberNegative[i]++;
		}
	}
}

// Вычисление с остальными запросами
void Matrix::calculate()
{
	// Запсрос размеров матрицы
	this->sizeRequest();
	
	// Создание матрицы
	this->createMatrix();
	
	// Заполнение матрицы
	this->add();
	
	// Вычисление среднего арифметического матрицы
	this->calculateArithmeticMean();
	
	// Подсчёт положительных и отрицательных элементов в каждой строке
	this->calculatePositiveNegative();
}

// Вывод
void Matrix::show()
{
	// Вычисление с остальными запросами
	this->calculate();
	
	cout << endl << "Среднее арифметическое элементов матрицы: " << this->arithmeticMean_matrix << endl;
	
	for (int i = 0; i < this->line_matrix; i++)
	{
		cout << "-------------------------------------------------------------------" << endl
			<< "Количество положительных элементов матрицы в " << i + 1
			<< " строке: " << this->numberPositive[i] << " элементов" << endl
			<< "Количество отрицательных элементов матрицы в " << i + 1
			<< " строке: " << this->numberNegative[i] << " элементов" << endl
			<< "-------------------------------------------------------------------"
			<< endl << endl;
	}
}

// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	cout << endl << endl << "Эказаменационная задача №5" << endl << endl;
	
	// Выполнение программы
	Matrix matrix;

	return 0;
}
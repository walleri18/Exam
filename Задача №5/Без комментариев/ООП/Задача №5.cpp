#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class Matrix
{
private:

	int line_matrix;
	int column_matrix;
	int **matrix;

	int *numberPositive;
	int *numberNegative;
	double arithmeticMean_matrix;
	
public:
	Matrix();
	~Matrix();

private:
	void sizeRequest();
	void createMatrix();
	void add();
	void calculateArithmeticMean();
	void calculatePositiveNegative();
	void calculate();
	void show();
};

Matrix::Matrix() : line_matrix(0), column_matrix(0), 
	matrix(NULL), numberPositive(NULL), 
	numberNegative(NULL), arithmeticMean_matrix(0)
{
	this->show();
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->line_matrix; i++)
	{
		delete[] this->matrix[i];
	}

	delete[] this->matrix;

	delete[] this->numberNegative;
	delete[] this->numberPositive;
}

void Matrix::sizeRequest()
{
	cout << endl << "Пожалуйста, введите необходимое количество строк в матрице: ";
	cin >> this->line_matrix;

	cout << endl << "Пожалуйста, введите необходимое количество столбцов в матрице: ";
	cin >> this->column_matrix;
}

void Matrix::createMatrix()
{
	this->matrix = new int* [this->line_matrix];
	
	for (int i = 0; i < this->line_matrix; i++) 
		this->matrix[i] = new int[this->column_matrix];
	
	this->numberPositive = new int[this->line_matrix];
	
	for (int i = 0; i < this->line_matrix; i++) 
		this->numberPositive[i] = 0;
	
	this->numberNegative = new int[this->line_matrix];
	
	for (int i = 0; i < this->line_matrix; i++) 
		this->numberNegative[i] = 0;
}

void Matrix::add()
{
	for (int i = 0; i < this->line_matrix; i++)
		for (int j = 0; j < this->column_matrix; j++)	
			this->matrix[i][j] = rand() % (100 - (-100) + 1) + (-100);
}

void Matrix::calculateArithmeticMean()
{
	for (int i = 0; i < this->line_matrix; i++)
		for (int j = 0; j < this->column_matrix; j++)
			this->arithmeticMean_matrix += this->matrix[i][j];
		
	this->arithmeticMean_matrix /= (this->line_matrix * this->column_matrix);
}

void Matrix::calculatePositiveNegative()
{
	for (int i = 0; i < this->line_matrix; i++)
		for (int j = 0; j < this->column_matrix; j++)
		{
			if (this->matrix[i][j] > 0) 
				this->numberPositive[i]++;
			
			else if (this->matrix[i][j] < 0) 
				this->numberNegative[i]++;
		}
}

void Matrix::calculate()
{
	this->sizeRequest();
	
	this->createMatrix();
	
	this->add();
	
	this->calculateArithmeticMean();
	
	this->calculatePositiveNegative();
}

void Matrix::show()
{
	this->calculate();
	
	cout << endl << "Среднее арифметическое элементов матрицы: " 
	<< this->arithmeticMean_matrix << endl;
	
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

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Эказаменационная задача №5" << endl << endl;
	
	Matrix matrix;

	return 0;
}
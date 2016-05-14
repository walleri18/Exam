/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №6.
	Есть строка и слово. Подсчитать количество повторений букв слова в строке.
*/

/*
	Псевдо код:
	1. Попросить пользователя ввести слово;
	2. Попросить ввести пользователя строку;
	3. Разбить слово и строку на символьные массивы;
	4. Поэлементно проверить массив строки на совпадение элементов слова;
	5. Подсчитать количество совпадений каждой буквы слова в массиве строки.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class CStringWord
{
// Данные
private:
	/*
		Основные данные
	*/
	char *slovoChar;// Массив со словом
	char *strokaChar;// Массив со строкой
	
	/*
		Дополнительные данные
	*/
	int slovoLenght_nullSymbol;// Длина слова с нулевым символом
	int strokaLenght_nullSymbol;// Длина слова с нулевым символом
	int *counterLetters;// Количество повторений символов слова в строке
	
public:
	CStringWord();// Конструктор по-умолчанию
	~CStringWord();// Деструктор по-умолчанию
private:
	void createAdd();// Создание массивов и их заполнение
	void calculate();// Вычисления и все остальные запросы
	void show();// Вывод результата
};

// Конструктор по-умолчанию
CStringWord::CStringWord() : slovoChar(NULL), strokaChar(NULL), slovoLenght_nullSymbol(0), strokaLenght_nullSymbol(0)
{
	// Вызываем показ вывода с предварительным вычислением
	this->show();
}

// Деструктор по-умолчанию
CStringWord::~CStringWord()
{
	// Очищаем память
	delete[] this->slovoChar;
	delete[] this->strokaChar;
	delete[] this->counterLetters;
}

// Создание массивов и их заполнение
void CStringWord::createAdd()
{
	// Временные переменные, где мы будем хранить строку и слово
	string stroka(""); // Исследуемая строка
	string slovo(""); //Исследуемое слово

	// Ввод слова
	cout << "Пожалуйста, введите исследуемое слово: ";
	getline(cin, slovo, '\n');// принимаем символы до перехода строки

	// Ввод строки
	cout << "Пожалуйста, введите исследуемую строку: ";
	getline(cin, stroka, '\n');// принимаем символы до перехода строки
	
	// Длины массивов
	this->slovoLenght_nullSymbol = slovo.length() + 1;
	this->strokaLenght_nullSymbol = stroka.length() + 1;
	
	// Создаём массивы
	slovoChar = new char[this->slovoLenght_nullSymbol];
	strokaChar = new char[this->strokaLenght_nullSymbol];
	
	// Заполняем массивы
	strcpy(slovoChar, slovo.c_str());
	strcpy(strokaChar, stroka.c_str());
}

// Вычисления и все остальные запросы
void CStringWord::calculate()
{
	this->counterLetters = new int[slovoLenght_nullSymbol - 1];

	//Обнулим массив счётчик
	for (int i = 0; i < slovoLenght_nullSymbol - 1; i++)
	{
		this->counterLetters[i] = 0;
	}

	// Начнём считать
	for (int i = 0; i < this->slovoLenght_nullSymbol - 1; i++)
	{
		for (int j = 0; j < this->strokaLenght_nullSymbol - 1; j++)
		{
			if (this->strokaChar[j] == this->slovoChar[i]) 
				this->counterLetters[i]++;
		}
	}
}

void CStringWord::show()
{
	// Создание и заполнение
	this->createAdd();
	
	// Подсчёт
	this->calculate();
	
	// Вывод результата
	for (int i = 0; i < slovoLenght_nullSymbol - 1; i++)
	{
		cout << endl << "Символ \"" << this->slovoChar[i] << "\" повторялся: " << this->counterLetters[i] << endl;
	}
}

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка русской раскладки

	cout << endl << endl << "Экзаменационное задание №6" << endl << endl
		<< "Вводить ТОЛЬКО на АНГЛИЙСКОМ" << endl << endl;

	// Запуск нашего решения
	CStringWord stringWord;

	return 0;
}
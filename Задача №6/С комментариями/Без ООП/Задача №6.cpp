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

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка русской раскладки

	cout << endl << endl << "Экзаменационное задание №6" << endl << endl
		<< "Вводить ТОЛЬКО на АНГЛИЙСКОМ" << endl << endl;

	string stroka(""); // Исследуемая строка
	string slovo(""); //Исследуемое слово

	// Ввод слова
	cout << "Пожалуйста, введите исследуемое слово: ";
	getline(cin, slovo, '\n');// принимаем символы до перехода строки

	// Ввод строки
	cout << "Пожалуйста, введите исследуемую строку: ";
	getline(cin, stroka, '\n');// принимаем символы до перехода строки
	
	// Длины массивов
	int slovoLenght = slovo.length(), strokaLenght = stroka.length();
	
	// Создание первого массива символов слова
	char *slovoChar = new char[slovoLenght + 1];
	
	// Создание первого массива символов строки
	char *strokaChar = new char[strokaLenght + 1];
	
	// Копирование в массив
	strcpy(slovoChar, slovo.c_str());
	strcpy(strokaChar, stroka.c_str());

	// Создадим особый массив, где будем хранить количество повторений символов слова в строке
	int *counterLetters = new int[slovoLenght];

	//Обнулим массив счётчик
	for (int i = 0; i < slovoLenght; i++)
	{
		counterLetters[i] = 0;
	}

	// Начнём считать
	for (int i = 0; i < slovoLenght; i++)
	{
		for (int j = 0; j < strokaLenght; j++)
		{
			if (strokaChar[j] == slovoChar[i]) 
				counterLetters[i]++;
		}
	}

	// Вывод результата
	for (int i = 0; i < slovoLenght; i++)
	{
		cout << endl << "Символ \"" << slovoChar[i] << "\" повторялся: " << counterLetters[i] << endl;
	}
	
	// Очищаем память
	delete[] slovoChar;
	delete[] strokaChar;
	delete[] counterLetters;

	return 0;
}
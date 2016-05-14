#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class CStringWord
{
private:

	char *slovoChar;
	char *strokaChar;

	int slovoLenght_nullSymbol;
	int strokaLenght_nullSymbol;
	int *counterLetters;
	
public:
	CStringWord();
	~CStringWord();
private:
	void createAdd();
	void calculate();
	void show();
};

CStringWord::CStringWord() : slovoChar(NULL), strokaChar(NULL), slovoLenght_nullSymbol(0), strokaLenght_nullSymbol(0)
{
	this->show();
}

CStringWord::~CStringWord()
{
	delete[] this->slovoChar;
	delete[] this->strokaChar;
	delete[] this->counterLetters;
}

void CStringWord::createAdd()
{
	string stroka("");
	string slovo("");

	cout << "Пожалуйста, введите исследуемое слово: ";
	getline(cin, slovo, '\n');

	cout << "Пожалуйста, введите исследуемую строку: ";
	getline(cin, stroka, '\n');

	this->slovoLenght_nullSymbol = slovo.length() + 1;
	this->strokaLenght_nullSymbol = stroka.length() + 1;

	slovoChar = new char[this->slovoLenght_nullSymbol];
	strokaChar = new char[this->strokaLenght_nullSymbol];

	strcpy(slovoChar, slovo.c_str());
	strcpy(strokaChar, stroka.c_str());
}

void CStringWord::calculate()
{
	this->counterLetters = new int[slovoLenght_nullSymbol - 1];

	for (int i = 0; i < slovoLenght_nullSymbol - 1; i++)
		this->counterLetters[i] = 0;

	for (int i = 0; i < this->slovoLenght_nullSymbol - 1; i++)
		for (int j = 0; j < this->strokaLenght_nullSymbol - 1; j++)
			if (this->strokaChar[j] == this->slovoChar[i]) 
				this->counterLetters[i]++;
}

void CStringWord::show()
{
	this->createAdd();

	this->calculate();

	for (int i = 0; i < slovoLenght_nullSymbol - 1; i++)
		cout << endl << "Символ \"" << this->slovoChar[i] 
		<< "\" повторялся: " << this->counterLetters[i] << endl;
	
}

int main(void)
{
	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Экзаменационное задание №6" << endl << endl
		<< "Вводить ТОЛЬКО на АНГЛИЙСКОМ" << endl << endl;

	CStringWord stringWord;

	return 0;
}
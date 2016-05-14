/*
	��������� � �����������.
	�����: ����� ������� �������������
	������: 514
*/

/*
	������ �6.
	���� ������ � �����. ���������� ���������� ���������� ���� ����� � ������.
*/

/*
	������ ���:
	1. ��������� ������������ ������ �����;
	2. ��������� ������ ������������ ������;
	3. ������� ����� � ������ �� ���������� �������;
	4. ����������� ��������� ������ ������ �� ���������� ��������� �����;
	5. ���������� ���������� ���������� ������ ����� ����� � ������� ������.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

// ����� �����

int main(void)
{
	setlocale(LC_ALL, ".1251"); // ��������� ������� ���������

	cout << endl << endl << "��������������� ������� �6" << endl << endl
		<< "������� ������ �� ����������" << endl << endl;

	string stroka(""); // ����������� ������
	string slovo(""); //����������� �����

	// ���� �����
	cout << "����������, ������� ����������� �����: ";
	getline(cin, slovo, '\n');// ��������� ������� �� �������� ������

	// ���� ������
	cout << "����������, ������� ����������� ������: ";
	getline(cin, stroka, '\n');// ��������� ������� �� �������� ������
	
	// ����� ��������
	int slovoLenght = slovo.length(), strokaLenght = stroka.length();
	
	// �������� ������� ������� �������� �����
	char *slovoChar = new char[slovoLenght + 1];
	
	// �������� ������� ������� �������� ������
	char *strokaChar = new char[strokaLenght + 1];
	
	// ����������� � ������
	strcpy(slovoChar, slovo.c_str());
	strcpy(strokaChar, stroka.c_str());

	// �������� ������ ������, ��� ����� ������� ���������� ���������� �������� ����� � ������
	int *counterLetters = new int[slovoLenght];

	//������� ������ �������
	for (int i = 0; i < slovoLenght; i++)
	{
		counterLetters[i] = 0;
	}

	// ����� �������
	for (int i = 0; i < slovoLenght; i++)
	{
		for (int j = 0; j < strokaLenght; j++)
		{
			if (strokaChar[j] == slovoChar[i]) 
				counterLetters[i]++;
		}
	}

	// ����� ����������
	for (int i = 0; i < slovoLenght; i++)
	{
		cout << endl << "������ \"" << slovoChar[i] << "\" ����������: " << counterLetters[i] << endl;
	}
	
	// ������� ������
	delete[] slovoChar;
	delete[] strokaChar;
	delete[] counterLetters;

	return 0;
}
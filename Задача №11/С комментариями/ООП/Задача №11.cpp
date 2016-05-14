/*
	Программа с пояснениями.
	Автор: Туров Виталий Александрович
	Группа: 514
*/

/*
	Задача №11.
	Создать шаблон класса «очередь». 
	Данные добавляются в «хвост» очереди и извлекаются с «головы». 
	В шаблоне реализовать конструктор, деструктор, метод добавления данных в очередь, метод извлечения данных из очереди. 
	Перегрузить операцию вывода элементов очереди в стандартный поток ostream.
*/

#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

// Следование 0 -> 1 -> 2 -> 3 -> и так далее, где 0 - это голова очереди
// Очередь на основе односвязанного списка!!!

// Класс "Очереди"
template <class Type>
class Queue
{
// Данные
private:

	// Структура элемента очереди
	struct Element
	{
	public:
		Type data;// Информация
		Element *next;// Указатель на следующий элемент
	};

	/*
		Основные данные
	*/

	Element *head;// Указатель на голову очереди
	Element *tail;// Указатель на хвост очереди

// Функции (методы)
public:
	Queue();// Конструктор по-умолчанию
	~Queue();// Деструктор по-умолчанию
	void addElement(Type);// Метод добавления элемента в очередь
	Type pullElement();// Метод извлечения элемента из очереди

	// Операция вывода очереди в поток (на консоль)
	friend ostream& operator << (ostream&stream, Queue<Type>& queue)
	{
		stream << endl;

		// Текущий элемент
		Element *current = queue.head;

		// Выводим полезную информацию из элементов
		for (int i = 0; current != NULL; current = queue.getNextElement(current), i++)
		{
			// Выводим информацию в поток
			stream << "Элемент №" << i + 1 << ": " << right << current->data << endl;
		}

		return stream;
	}

private:

	// Метод получения следующего элемента
	Element* getNextElement(Element *element) const
	{
		return element->next;
	}
};

// Конструктор по-умолчанию
template <class Type>
Queue<Type>::Queue() : head(NULL), tail(NULL) {}

// Деструктор по-умолчанию
template <class Type>
Queue<Type>::~Queue()
{
	// Текущий элемент
	Element *current = this->head;

	// Пока текущий элемент не будет равен хвосту
	while (current != NULL)
	{
		// Получаем новую голову
		this->head = getNextElement(current);

		// Удаляем старую голову
		delete current;

		// Устанавливаем новую голову текущей
		current = this->head;
	}
}

// Метод добавления элемента в очередь
template <class Type>
void Queue<Type>::addElement(Type info)
{
	// Создаём новый элемент
	Element *newElement = new Element;

	// Заполняем новый элемент
	newElement->data = info;
	newElement->next = NULL;

	// Следующий элемент, после старого хвоста.
	// Если это первый раз, то старый хвост есть новый хвост и новая голова
	if (this->tail)
		this->tail->next = newElement;

	else 
		this->head = newElement;
	
	// Устанавливаем новый хвост
	this->tail = newElement;

}

// Метод извлечения элемента из очереди
template <class Type>
Type Queue<Type>::pullElement()
{
	// Текущий элемент, является старой головой
	Element *oldHead = this->head;

	// Устанавливаем новую голову
	this->head = getNextElement(oldHead);

	// Копируем данные старой головы
	Type data = oldHead->data;

	// Удалаем старую голову
	delete oldHead;

	// Возвращаем полезную информацию
	return data;
}

// Точка входа

int main(void)
{
	// Зерно рандома
	srand(time(NULL));

	setlocale(LC_ALL, ".1251"); // Установка русской раскладки

	cout << endl << endl << "Эказаменнационное задание №11" << endl << endl;

	cout << "Очередь INT:" << endl << endl;

	// Создаём объект очереди
	Queue<int> queueInt;

	// Добавляем элементы в очередь
	for (int i = 0; i < 10; i++)
	{
		queueInt.addElement(rand() % (100 - (-100) + 1) + (-100));
	}

	// Показываем очередь
	cout << "Исходные элементы очереди: " << queueInt << endl << endl << "Удалённые элементы: " << endl << endl;

	// Удаляем несколько элементов из очереди
	for (int i = 0; i < 5; i++)
	{
		cout << queueInt.pullElement() << endl;
	}

	cout << endl << endl << "После удаления элементы: " << queueInt << endl << endl;

	cout << "Очередь DOUBLE:" << endl << endl;

	// Создаём объект очереди
	Queue<double> queueDouble;

	// Добавляем элементы в очередь
	for (int i = 0; i < 10; i++)
	{
		queueDouble.addElement(rand() % (100 - (-100) + 1) + (-100) + 0.5);
	}

	// Показываем очередь
	cout << "Исходные элементы очереди: " << queueDouble << endl << endl << "Удалённые элементы: " << endl << endl;

	// Удаляем несколько элементов из очереди
	for (int i = 0; i < 5; i++)
	{
		cout << queueDouble.pullElement() << endl;
	}

	cout << endl << endl << "После удаления элементы: " << queueDouble << endl << endl;

	return 0;
}
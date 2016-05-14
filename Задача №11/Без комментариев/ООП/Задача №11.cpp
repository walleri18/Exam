#include <locale.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

template <class Type>
class Queue
{
private:

	struct Element
	{
	public:
		Type data;
		Element *next;
	};

	Element *head;
	Element *tail;

public:
	Queue();
	~Queue();
	void addElement(Type);
	Type pullElement();

	friend ostream& operator << (ostream&stream, Queue<Type>& queue)
	{
		stream << endl;

		Element *current = queue.head;

		for (int i = 0; current != NULL; current = queue.getNextElement(current), i++)
			stream << "Ёлемент є" << i + 1 << ": " << right << current->data << endl;

		return stream;
	}

private:

	Element* getNextElement(Element *element) const
	{
		return element->next;
	}
};

template <class Type>
Queue<Type>::Queue() : head(NULL), tail(NULL) {}

template <class Type>
Queue<Type>::~Queue()
{
	Element *current = this->head;

	while (current != NULL)
	{
		this->head = getNextElement(current);
		
		delete current;

		current = this->head;
	}
}

template <class Type>
void Queue<Type>::addElement(Type info)
{
	Element *newElement = new Element;

	newElement->data = info;
	newElement->next = NULL;

	if (this->tail)
		this->tail->next = newElement;

	else 
		this->head = newElement;
	
	this->tail = newElement;

}

template <class Type>
Type Queue<Type>::pullElement()
{
	Element *oldHead = this->head;

	this->head = getNextElement(oldHead);

	Type data = oldHead->data;

	delete oldHead;

	return data;
}

int main(void)
{
	srand(time(NULL));

	setlocale(LC_ALL, ".1251");

	cout << endl << endl << "Ёказаменнационное задание є11" << endl << endl;

	cout << "ќчередь INT:" << endl << endl;

	Queue<int> queueInt;

	for (int i = 0; i < 10; i++)
		queueInt.addElement(rand() % (100 - (-100) + 1) + (-100));

	cout << "»сходные элементы очереди: " << queueInt 
	<< endl << endl << "”далЄнные элементы: " << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << queueInt.pullElement() << endl;
	}

	cout << endl << endl << "ѕосле удалени¤ элементы: " << queueInt << endl << endl;

	cout << "ќчередь DOUBLE:" << endl << endl;

	Queue<double> queueDouble;

	for (int i = 0; i < 10; i++)
		queueDouble.addElement(rand() % (100 - (-100) + 1) + (-100) + 0.5);

	cout << "»сходные элементы очереди: " << queueDouble 
	<< endl << endl << "”далЄнные элементы: " << endl << endl;

	for (int i = 0; i < 5; i++)
		cout << queueDouble.pullElement() << endl;

	cout << endl << endl << "ѕосле удалени¤ элементы: " << queueDouble << endl << endl;

	return 0;
}
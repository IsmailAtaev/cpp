#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
struct Node 
{
	T data;
	Node<T>* next = NULL;
	Node<T>* prev = NULL;
};

template<typename T>
class Queue
{
private:
	int Size;
	Node<T>* head;
	Node<T>* tail;
public:
	Queue() : head(NULL), tail(NULL), Size(0) {}
	~Queue();
	Queue(const Queue<T>& obj);
	void Delete(int index);
	void show();
	T& operator[](int index);
	void enqueue(T data);
	bool is_Empty();
	int getSize();
	T dequeue();
	void Clear();
};

template<typename T>
inline Queue<T>::~Queue()
{
	Clear();
}

template<typename T>
inline Queue<T>::Queue(const Queue<T>& obj)
{
	this->head = obj.head;
	this->Size = obj.Size;
	this->tail = obj.tail;
}

template<typename T>
inline void Queue<T>::Delete(int index)
{
	Node<T>* temp = head;
	if (index < 0 || index > Size)
		return;
	if (index == 1) 
	{
		if (!(head)) return;
		Node<T>* temp = head;
		head = head->next;
		if (head) head->prev = nullptr;
		delete temp;
		Size--;
		return;
	}
	else if (index == Size) 
	{
		dequeue();
		return;
	}
	else
	{
		for (int i = 1; i < index; i++)
		{
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	delete temp;
	Size--;
}

template<typename T>
inline void Queue<T>::show()
{
	Node<T>* temp = head;
	for (int i = 0; i < Size; i++) {
		cout << setw(2) << i + 1;
		temp->data.Show();
		cout << endl;
		temp = temp->next;
	}
}

template<typename T>
inline T& Queue<T>::operator[](int index)
{
	Node<T>* curr = head;
	if (index >= Size || index < 0)
		return curr->data;

	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}


template<typename T>
inline void Queue<T>::enqueue(T data)
{
	if (Size == 0) {
		head = new Node<T>;
		head->prev = NULL;
		head->next = NULL;
		head->data = data;
		tail = head;
		Size++;
		return;
	}
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->prev = nullptr;
	temp->next = head;
	head->prev = temp;
	head = temp;
	Size++;
}

template<typename T>
inline bool Queue<T>::is_Empty()
{
	return Size == 0;
}

template<typename T>
inline int Queue<T>::getSize()
{
	return Size;
}


template<typename T>
inline T Queue<T>::dequeue()
{
	if (!(tail)) return T();
	T data = tail->data;
	Node<T>* temp = tail;
	tail = tail->prev;
	if (tail)
		tail->next = nullptr;
	delete temp;
	Size--;
	return data;
}

template<typename T>
inline void Queue<T>::Clear()
{
	while (Size != 0) {
		dequeue();
	}
}
#pragma once
#include <iostream>
#include <iomanip>

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
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    Queue() : head(NULL), tail(NULL), size(0) {}
    ~Queue() { this->Clear(); }
    Queue(const Queue<T>& obj);
    void Enqueue(T& data);
    T Dequeue();
    void Dequeue1();
    void Clear();
    int GetSize() { return size; }
    bool Empty() { return size == 0; }
    T& Peek();
    T& operator[](int index);
    void show();
    //Queue<T>* sSearch();
    //void Edit();
    static void Title() {
        T tit{};
        tit.title();
    }
    //void BubleSort();

    class Iter
    {
    private:
        Node<T>* ptr;
    public:
        Iter(Node<T>* p) { ptr = p; }
        Iter(const Iter& it) : ptr(it.ptr) { }
        Iter& operator=(const Iter& it) {
            ptr = it.ptr;
            return *this;
        }
        Iter() { ptr = NULL; }
        ~Iter() { }
        Node<T>* getPtr() { return ptr; }
        Iter operator++(int) {
            if (ptr->prev == NULL) {
                ptr = NULL;
                return Iter(ptr);
            }
            ptr = ptr->prev;
            return *this;
        }
        Iter operator++() {
            if (ptr->prev == NULL) {
                ptr = NULL;
                return Iter(ptr);
            }
            ptr = ptr->prev;
            return *this;
        }
        Iter operator--(int) {
            if (ptr->next == NULL) {
                ptr = NULL;
                return Iter(ptr);
            }
            ptr = ptr->next;
            return *this;
        }
        Iter operator--() {
            if (ptr->next == NULL) {
                ptr = NULL;
                return Iter(ptr);
            }
            ptr = ptr->next;
            return *this;
        }
        T& operator *() { return this->ptr->data; }
        bool operator ==(const Iter& x) { return (ptr == x.ptr); }
        bool operator!=(const Iter& x) { return (ptr != x.ptr); }

    };

    Iter begin() { return Iter(head); }
    Iter end() { return Iter(tail->prev); }

    Iter r_begin() { return Iter(tail); }
    Iter r_end() { return Iter(head->next); }
};

template<typename T>
inline void Queue<T>::show()
{
    if (this->Empty())
        return;
    Node<T>* temp = head;
    for (int i = 0; i < size; i++)
    {
        std::cout << "|" << std::setw(2) << i + 1 << "|" << temp->data << std::endl;
        temp = temp->prev;
    }
}


/*
template<typename T>
inline Queue<T>* Queue<T>::sSearch()
{
    Queue<T>* geler = new Queue<T>();
    if (this->Empty())
    {
        std::cout << " Очередь пуст нечего искать ! " << std::endl;
    }
    else {
        T ress{};
        ress.vvodSearch();
        Node<T>* temp = head;
        while (temp != NULL)
        {
            if (temp->data == ress)
            {
                T www = temp->data;
                geler->Enqueue(www);
            }
            temp = temp->prev;
        }
    }
    return geler;
}*/

/*template<typename T>
inline void Queue<T>::Edit()
{
    if (this->Empty())
    {
        std::cout << "\tПусто" << std::endl;
        return;
    }
    else {
        T perem{};
        this->show();
        std::cout << " Номер редактируемого элемента: ";
        int  k;
        std::cin >> k;
        if (k > this->GetSize() || k <= 0)
        {
            std::cout << " Выхад за предел " << std::endl;
        }
        else
        {
            (*this)[--k].edit();
        }
    }
}*/

/*template<typename T>
inline void Queue<T>::BubleSort()
{

    if (this->GetSize() == 0)
    {
        std::cout << " Нет элементов для сортировки" << std::endl;
        return;
    }

    T temp{};
    for (Node<T>* i = head; i != NULL; i = i->prev)
    {
        for (Node<T>* j = i->prev; j != NULL; j = j->prev)
        {
            if ((i->data) > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
*/

template<typename T>
inline T& Queue<T>::operator[](int index)
{
    Node<T>* curr = head;
    if (index >= size || index < 0)
        return curr->data;

    for (int i = 0; i < index; i++)
    {
        curr = curr->prev;
    }
    return curr->data;
}

template<typename T>
inline T& Queue<T>::Peek()
{
    if (head != NULL)
        return head->data;
    else {
        return T();
    }
}


template<typename T>
inline void Queue<T>::Enqueue(T& data)
{
    if (size == 0)
    {
        head = new Node<T>;
        head->prev = NULL;
        head->next = NULL;
        head->data = data;
        tail = head;
        size++;
        return;
    }
    Node<T>* temp = new Node<T>;
    temp->data = data;
    temp->next = tail;
    tail->prev = temp;
    tail = temp;
    size++;
}

template<typename T>
inline T Queue<T>::Dequeue()
{
    if (!(head))
        return T();

    T data = head->data;
    Node<T>* temp = head;
    head = head->prev;
    if (head)
        head->next = nullptr;
    delete temp;
    size--;
    return data;
}

template<typename T>
inline void Queue<T>::Dequeue1()
{
    if (!(head))
        return;
    Node<T>* temp = head;
    if (head)
        head->next = nullptr;
    head = head->prev;
    delete temp;
    size--;
}

template<typename T>
inline void Queue<T>::Clear()
{
    if (this->Empty())
    {
        std::cout << " Пусто!" << std::endl;
        return;
    }

    while (this->size != 0)
    {
        Dequeue1();
    }
}

template<typename T>
Queue<T>::Queue(const Queue<T>& obj)
{
    this->size = obj.size;
    this->head = obj.head;
    this->tail = obj.tail;
}

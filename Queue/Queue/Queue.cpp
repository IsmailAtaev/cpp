#include <iostream>
#include <string>

using namespace std;

#include <Windows.h>
#include <algorithm>

template <typename T>
class Queue
{
private:
    T* array;
    int version;
    int head;
    int tail;
    int size;
    int arrayLength;
    float growFactor;
    void SetCapacity(int capacity);
public:
    Queue(int capacity);
    T Dequeue();
    void Enqueue(T& x);
    bool TryDequeue(T& result);
    T Peek();
    int Size();
    bool IsEmpty();
    T Search(T element);
    ~Queue();
};



template <typename T>
Queue<T>::Queue(int capacity)
{
    // edit
    this->growFactor = 2.0;
    this->head = 0;
    this->size = 0;
    this->tail = 0;
    this->version = 0;
    this->array = new T[capacity];
    this->arrayLength = capacity;
}
template <typename T>
Queue<T>::~Queue()
{
    delete[] this->array;
}

template <typename T>
void Queue<T>::SetCapacity(int capacity)
{
    T* arr = new T[capacity];
    if (this->size > 0)
    {
        if (this->head < this->tail)
        {
            std::copy(this->array + this->head, this->array + this->tail, arr + 0);
        }
        else
        {
            std::copy(this->array + this->head, this->array + this->arrayLength, arr + 0);
            std::copy(this->array + 0, this->array + this->tail, arr + this->arrayLength - this->head);
        }
    }

    delete[]this->array;
    this->array = arr;
    this->arrayLength = capacity;
    this->head = 0;
    this->tail = (this->size == capacity) ? 0 : this->size;
    this->version++;
}


template <typename T>
T Queue<T>::Dequeue()
{
    if (this->size == 0)
    {
        T* result = 0;
        return *result;
    }

    T result = this->array[this->head]; 
    this->head = (this->head + 1) % this->arrayLength;
    this->size--;
    this->version++;
    return result;
}

template <typename T>
bool Queue<T>::TryDequeue(T& result)
{
    if (size == 0)
    {
        return false;
    }
    T res = this->array[this->head];
    this->head = (this->head + 1) % this->arrayLength;
    this->size--;
    this->version++;
    result = res;
    return true;
}

template <typename T>
void Queue<T>::Enqueue(T& item)
{
    if (this->size == this->arrayLength)
    {
        int num = (int)(this->arrayLength * this->growFactor);
        if (num < this->arrayLength + 4)
        {
            num = this->arrayLength + 4;
        }

        this->SetCapacity(num);
    }

   this->array[this->tail] = item;
    this->tail = (this->tail + 1) % this->arrayLength;
    this->size++;
    this->version++;
}

template <typename T>
T Queue<T>::Peek() // posmotret
{ 
    if (this->size == 0) {
        T* temp = 0;
        return *temp;
    }
    T result = this->array[head];
    return result;
}

template <typename T>
int Queue<T>::Size()
{
    int result = this->size;
    return result;
}

template <typename T>
bool Queue<T>::IsEmpty()
{
    return (Size() == 0);
}


template <typename T>
T Queue<T>::Search(T element)
{
    if (this->size > 0)
    {
        if (this->head < this->tail)
        {
            for (int i = this->head; i < this->tail; i++)
            {
                if (this->array[i] == element)
                    return this->array[i];
            }
        }
        else
        {

            for (int i = this->head; i < this->arrayLength; i++)
            {
                if (this->array[i] == element)
                    return this->array[i];
            }

            for (int i = 0; i < this->tail; i++)
            {
                if (this->array[i] == element)
                    return this->array[i];
            }
        }
    }

    return NULL;
}

class person 
{
private:
    string name;
    int age;
public:
    person(string name ="" , int age = 0) {
        this->name = name;
        this->age = age;
    }

    person(const person& obj) {
        this->age =  obj.age;
        this->name = obj.name;
    }
    person& operator =(const person & obj) 
    {
        if (this != &obj) 
        {
            this->name = obj.name;
            this->age = obj.age;
        }
        return *this;
    }

    void setName(const string& obj) {
        this->name = obj;
    }
    void setAge(const int& age) {
        this->age = age;
    }

    string getName() {
        return this->name;
    }
    int getAge() {
        return this->age;
    }

    friend istream& operator >>(istream & fin,person& obj) {
       
        cout << "enter name " << endl;
        getline(fin ,obj.name);
        cout << "enter age" << endl;
        fin >> obj.age;
        return fin;
    }
    friend ostream& operator << (ostream& fout, person& obj) {
        cout << "answer" << endl;
        fout << obj.name << endl;
        fout << obj.age << endl;    
        return fout;
    }
    ~person() { }
};



int main() {

    Queue<person>* pers = new Queue<person>(10);
    person p; 
    cin >> p;
    pers->Enqueue(p);
    person  p2 = pers->Peek();
    cout << p2 << endl;
    p2.setAge(200);
    p = p2;

    cout << p << endl;
    
    person q = pers->Peek();
    cout << q << endl;
    
    delete pers;
    return 0;
}
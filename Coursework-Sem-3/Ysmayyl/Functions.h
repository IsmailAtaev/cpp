//Functions.h
#pragma once
#include "Header.h"
#include "Queue.h"
#include "File.h"

constexpr auto min = 3;  
constexpr auto max = 20;  

template <class T>
void ReadDataFromFile(Queue<T>*& obj, char* filename);

template <class T>
void WriteDataToFile(Queue<T>*& obj, char* filename);

template<class T>
inline void ReadDataFromFile(Queue<T>*& obj, char* filename)
{
	File<T> file(filename);
	T data;
	obj->Clear();
	while (1) 
	{
		file.ReadData(data);
		if (file.REndFile()) break;
		obj->enqueue(data);
	}
}

template<class T>
inline void WriteDataToFile(Queue<T>*& obj, char* filename)
{
	File<T> file(filename);
	while (obj->getSize() != 0)
	{
		T d = obj->dequeue();
		file.WriteData(d);
	}
}

template<typename T>
inline T enterInt(T mini, T maxi)
{
	T i;
	bool flag = true;
	do {
		flag = true;
		cin >> i;
		if (!cin.good() || cin.peek() != '\n') 
		{
			cout << "___ ¬ведено не число" << endl;
			flag = false;
			rewind(stdin); 
			cout << endl;
			cin.clear();
		}
		else if (i < mini || i > maxi)
		{
			flag = false;
			cout << "___ ¬ведите число в интервале от " << mini << " до " << maxi << endl;
			rewind(stdin);
			cout << endl;
			cin.clear();
		}
	} while (flag!= true);
	return i;
}

char* enterCharOnly();

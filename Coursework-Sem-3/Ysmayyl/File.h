#pragma once
#include "Header.h"

template <class T>
class File
{
private:
	fstream filestream;
	char filename[30];
public:
	File();
	File(char* filename);
	~File() { filestream.close(); }

	void WriteData(T& obj);
	void ReadData(T& obj);

	bool REndFile();
	void OpenEnd(char* filename);

	void closeFile();
};

template<class T>
inline void File<T>::WriteData(T& obj)
{
	filestream << obj;
}

template<class T>
inline void File<T>::ReadData(T& obj)
{
	filestream >> obj;
}

template<class T>
inline bool File<T>::REndFile()
{
	if (filestream.eof())
		return true;
	else
		return false;
}

template<class T>
inline void File<T>::OpenEnd(char* filename)
{
	strcpy_s(this->filename, filename);
	filestream.open(this->filename, ios::app);
	if (!filestream.is_open()) 
	{
		cout << "___ Ошибка открытие файла" << endl;
		return;
	}
}

template<class T>
inline void File<T>::closeFile()
{
	filestream.close();
}


template<class T>
inline File<T>::File()
{ }

template<class T>
inline File<T>::File(char* f)
{
	strcpy_s(this->filename, f);
	filestream.open(f, ios::in | ios::out);

	if (!filestream.is_open())
	{
		cout << "___ Ошибка открытие файла" << endl;
		return;
	}
}

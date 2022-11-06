#pragma once

#pragma once
#include "Queue.h"

template<class T>
void Print(typename Queue<T>::Iter it_b, typename Queue<T>::Iter it_e)
{
	try {
		if (it_b == NULL) {
			throw myExeption_Inpit(96, " Нет элементов для вывода.");
		}

		for (int i = 1; it_b != it_e; it_b++, ++i)
		{
			std::cout << std::setw(2) << i << "|" << *it_b << std::endl;
		}
	}
	catch (myExeption_Inpit& ex) {
		ex.Print();
	}
	catch (...) {
		std::cout << "  catch(...) в алгоритме выводе Print()" << std::endl;
	}
}
/*{
	if (!obj->Empty()) {
		int i = 0;
		obj->Title();
		for (typename Queue<T>::Iter it = obj->begin(); it != obj->end(); it++, i++)
			std::cout << std::setw(4) << i + 1 << "|" << *it << std::endl;
	}
	else {
		std::cout << " There is nothing " << std::endl;
	}
}*/

template<typename T>
Queue<T>* Searche(typename Queue<T>::Iter it_begin, typename Queue<T>::Iter it_end, bool (*predicate)(T a, T b))
{
	Queue<T>* temp = new Queue<T>;
	if (it_begin != NULL)
	{
		T count{};
		count.vvodSearch();
		while (it_begin != it_end)
		{
			if (predicate(*it_begin, count))
				temp->Enqueue(*it_begin);
			it_begin++;
		}
		return temp;
	}
	else {
		return temp;
	}
}

template <class T>
void Edited(typename Queue<T>::Iter it_begin, typename Queue<T>::Iter it_end, int count, int size_obj)
{
	try {
		if (count > size_obj || count < 0) {
			throw myExeption_Inpit(71, " Выход за пределы контейнера !");
		}

		for (int i = 0; it_begin != it_end; it_begin++) {
			if (i == count) {
				(*it_begin).Edit();
				break;
			}
			i++;
		}


		//		for (int i = 0; i < count; i++,it_begin++){}

	}
	catch (myExeption_Inpit exection) {
		exection.Print();
	}
	catch (...) {
		std::cout << "Что-то пошдо не так вызов исключения Алгоритма Edited() " << std::endl;
	}
}
/*template <class T>
inline void Edited(Queue<T>* obj)
{
	if (!obj->Empty()) {
		Print(obj);
		std::cout << " Enter number for edit " << std::endl;
		int count = input_INT(std::cin, 1, obj->GetSize());
		--count;
		if (count < obj->GetSize()) {
			typename Queue<T>::Iter it = obj->begin();
			for (int i = 0; i < count; i++)
				it++;

			(*it).Edit();
		}
	}
	else {
		std::cout << " There is nothing " << std::endl;
	}
}*/

template<class T>
inline void BubbleSort(typename Queue<T>::Iter it_begin, typename Queue<T>::Iter it_end, bool (*predicate)(T a, T b))
{
	for (typename Queue<T>::Iter i = it_begin; i != it_end; ++i)
		for (typename Queue<T>::Iter j = it_begin; j != i; j++)
			if (predicate(*j, *i))
			{
				T temp = *i;
				*i = *j;
				*j = temp;
			}
}

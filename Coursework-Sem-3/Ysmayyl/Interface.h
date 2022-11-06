#pragma once
#include "Queue.h"
#include "File.h"
#include "Order.h"
#include "Ticket.h"
#include "Functions.h"
#include "Client.h"

template <class T>
class Interface 
{
	Queue<T>* queue;
	Queue<Order>* orders;
	Queue<Ticket>* tickets;
	char filename[30];

public:
	Interface(char* f);
	~Interface();
	void add();
	void del();
	void edit();
	void show();
	void start();
	void setFilename(char* f);
};

template<class T>
inline Interface<T>::Interface(char* f)
{
	queue = new Queue<T>;
	orders = new Queue<Order>;
	tickets = new Queue<Ticket>;
	setFilename(f);
}

template<class T>
inline Interface<T>::~Interface()
{
	delete queue;
	delete orders;
	delete tickets;
}

template<class T>
inline void Interface<T>::add()
{
	T object;
	object.PutData();
	queue->enqueue(object);
	cout << "___ Успешно!" << endl;
}

template<class T>
inline void Interface<T>::del()
{
	if (queue->is_Empty()) 
	{
		cout << "___ Пусто" << endl;
		return;
	}
	
	this->show();
	cout << endl;
	cout << "___ Номер удаляемого элемента: ";
	int k;
	k = enterInt(1, queue->getSize());
	queue->Delete(k);
	cout << "___ Успешно";
}

template<class T>
inline void Interface<T>::edit()
{
	if (queue->is_Empty()) 
	{
		cout << "___ Пусто" << endl;
		return;
	}

	show();
	cout << "___ Номер редактируемого элемента: ";
	int k;
	k = enterInt(1, queue->getSize());
	(*queue)[k - 1].Edit();
	cout << "___ Успешно" << endl;
}

template<class T>
inline void Interface<T>::show()
{
	if (queue->is_Empty())
	{
		cout << "___ Пусто" << endl;
		return;
	}
	T::header();
	queue->show();
	T::headerLine();
	cout << endl;
}

template<class T>
inline void Interface<T>::start()
{
	int choice;
	char ti[30] = "tickets.txt";
	char r[30] = "orders.txt";

	ReadDataFromFile(queue, filename);
	ReadDataFromFile(orders, r);
	ReadDataFromFile(tickets, ti);

	do {
		
		system("cls");
		cout << "___ Меню редактирование" << endl;
		cout << "1__ Добавить" << endl;
		cout << "2__ Удалить" << endl;
		cout << "3__ Изменить" << endl;
		cout << "4__ Сортировать" << endl;
		cout << "5__ Заказы на тур" << endl;
		cout << "6__ Билеты" << endl;
		cout << "7__ Сохранить данные" << endl;
		cout << "8__ Читат с файла" << endl;
		cout << "9__ ПРОСМОТР" << endl;
		cout << "0__ Назад" << endl;
		choice = enterInt(0, 9);

		cout << endl << endl;
		switch (choice)
		{
			case 1:
			{
				add();
				break;
			}
			case 2:
			{
				del();
				break;
			}
			case 3: 
			{
				edit();
				break;
			}
			case 4: 
			{
				cout << "1__ Сортировать по названию" << endl;
				cout << "2__ Сортировать по виду туров" << endl;
				int o;
				o = enterInt(1, 2);
				if (o == 1) 
				{
					for (int i = 0; i < queue->getSize(); i++)
					{
						for (int j = i + 1; j < queue->getSize(); j++)
							if ((*queue)[i].getTourName() > (*queue)[j].getTourName())
							{
								T temp = (*queue)[i];
								(*queue)[i] = (*queue)[j];
								(*queue)[j] = temp;
						    }
					}
				}
				else 
				{
					for (int i = 0; i < queue->getSize(); i++)
					{
						for (int j = i + 1; j < queue->getSize(); j++)
							if ((*queue)[i].getTourType() > (*queue)[j].getTourType()) 
							{
								T temp = (*queue)[i];
								(*queue)[i] = (*queue)[j];
								(*queue)[j] = temp;
							}
					}
				}
				break;
			}

			case 5:
			{
				Queue<Order> temp;
				for (int i = 0; i < orders->getSize(); i++)
				{
					for (int j = 0; j < queue->getSize(); j++) 
					{
						if ((*orders)[i].getTourCode() == (*queue)[j].getTourCode())
						{
							temp.enqueue((*orders)[i]);
						}
					}
				}

				Order::header();
				temp.show();
				Order::headerLine();

				cout << "1__ Подтвердить заказ и создать билет" << endl;
				cout << "0__ Назад" << endl;
			
				int y;
				y = enterInt(0,1);
			
				if (y == 1)
				{
					cout << "___ Введите номер заказа: ";
					int ll;
					ll = enterInt(1, temp.getSize());
					ll--;
					Ticket t;
					t.setUserCode(temp[ll].getClientCode());
					t.PutData();
					tickets->enqueue(t);
					cout << "___ Билет успешно создан" << endl;
				}
				break;
			}
			case 6: 
			{
				cout << "___ Список билетов" << endl << endl;
				if (tickets->getSize() == 0)
				{
					cout << "___ Пусто" << endl;
					break;
				}
				Ticket::header();
				tickets->show();
				Ticket::headerLine();
				cout << endl;
				break;
			}
			case 7:
			{
				char ti[30] = "tickets.txt";
				char r[30] = "orders.txt";
				WriteDataToFile(queue, filename);
				WriteDataToFile(orders, r); 
				WriteDataToFile(tickets, ti);
				break;
			}
			case 8:
			{
				ReadDataFromFile(queue, filename);
				char ti[30] = "tickets.txt";
				char r[30] = "orders.txt";
				ReadDataFromFile(orders, r);
				ReadDataFromFile(tickets, ti);
				break;
			}
			case 9: 
			{
				this->show();
				break;
			}
			default:
				break;
		}
			cout << endl;
			system("pause");
	} while (choice != 0);
}

template<class T>
inline void Interface<T>::setFilename(char* f)
{
	strcpy_s(filename, f);
}

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
	cout << "___ �������!" << endl;
}

template<class T>
inline void Interface<T>::del()
{
	if (queue->is_Empty()) 
	{
		cout << "___ �����" << endl;
		return;
	}
	
	this->show();
	cout << endl;
	cout << "___ ����� ���������� ��������: ";
	int k;
	k = enterInt(1, queue->getSize());
	queue->Delete(k);
	cout << "___ �������";
}

template<class T>
inline void Interface<T>::edit()
{
	if (queue->is_Empty()) 
	{
		cout << "___ �����" << endl;
		return;
	}

	show();
	cout << "___ ����� �������������� ��������: ";
	int k;
	k = enterInt(1, queue->getSize());
	(*queue)[k - 1].Edit();
	cout << "___ �������" << endl;
}

template<class T>
inline void Interface<T>::show()
{
	if (queue->is_Empty())
	{
		cout << "___ �����" << endl;
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
		cout << "___ ���� ��������������" << endl;
		cout << "1__ ��������" << endl;
		cout << "2__ �������" << endl;
		cout << "3__ ��������" << endl;
		cout << "4__ �����������" << endl;
		cout << "5__ ������ �� ���" << endl;
		cout << "6__ ������" << endl;
		cout << "7__ ��������� ������" << endl;
		cout << "8__ ����� � �����" << endl;
		cout << "9__ ��������" << endl;
		cout << "0__ �����" << endl;
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
				cout << "1__ ����������� �� ��������" << endl;
				cout << "2__ ����������� �� ���� �����" << endl;
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

				cout << "1__ ����������� ����� � ������� �����" << endl;
				cout << "0__ �����" << endl;
			
				int y;
				y = enterInt(0,1);
			
				if (y == 1)
				{
					cout << "___ ������� ����� ������: ";
					int ll;
					ll = enterInt(1, temp.getSize());
					ll--;
					Ticket t;
					t.setUserCode(temp[ll].getClientCode());
					t.PutData();
					tickets->enqueue(t);
					cout << "___ ����� ������� ������" << endl;
				}
				break;
			}
			case 6: 
			{
				cout << "___ ������ �������" << endl << endl;
				if (tickets->getSize() == 0)
				{
					cout << "___ �����" << endl;
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

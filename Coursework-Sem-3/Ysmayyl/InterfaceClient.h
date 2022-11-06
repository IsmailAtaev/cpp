#pragma once
#include "Queue.h"
#include "Order.h"
#include "Client.h"
#include "Ticket.h"
#include "File.h"
#include "Functions.h"
#include "LandInternational.h"
#include "SeaInternational.h"
#include "LocalTour.h"

class InterfaceClient
{
private:
	Client client;
	Queue<Order>* orders;
	Queue<Ticket>* tickets;
public:
	InterfaceClient(Client obj);
	~InterfaceClient();
	void start();
	template<class T>
	void makeOrder(Queue<T> *q);
	void loadTicket();
	void loadOrder();
	void writeOrder();
};


inline InterfaceClient::InterfaceClient(Client obj)
{
	orders = new Queue<Order>;
	tickets = new Queue<Ticket>;
	client = obj;
}

inline InterfaceClient::~InterfaceClient()
{
	delete orders;
	delete tickets;
}

inline void InterfaceClient::start()
{
	int vybor;
	do {
		Queue<LandInternational>* lands = new Queue<LandInternational>;
		char filename1[30] = "landtours.txt";
		ReadDataFromFile(lands, filename1);

		char filename2[30] = "seatours.txt";
		Queue<SeaInternational>* sea = new Queue<SeaInternational>;
		ReadDataFromFile(sea, filename2);

		char filename3[30] = "localtours.txt";
		Queue<LocalTour>* localtours = new Queue<LocalTour>;
		ReadDataFromFile(localtours, filename3);

		char filename4[30] = "orders.txt";
		ReadDataFromFile(orders, filename4);

		char filename5[30] = "tickets.txt"; //билет
		ReadDataFromFile(tickets, filename5);

		system("cls");
		cout << "___ Меню клиента" << endl << endl;
		cout << "___ Список" << endl;
		cout << "1__ Сухопутные туры" << endl;
		cout << "2__ Морские туры" << endl;
		cout << "3__ Местные туров" << endl << endl;

		cout << "___ Раздел заказы" << endl;

		cout << "4__ Бронировать" << endl;
		cout << "5__ Мои заказы" << endl;
		cout << "6__ Мои билеты" << endl;
		cout << "0__ Выход" << endl;
	
		vybor = enterInt(0,6);

		switch (vybor)
		{
			case 1:
			{
				LandInternational::header();
				lands->show();
				LandInternational::headerLine();
				break;
			}
			case 2:
			{
				SeaInternational::header();
				sea->show();
				SeaInternational::headerLine();
				break;
			}
			case 3:
			{
				LocalTour::header();
				localtours->show();
				LocalTour::headerLine();
				break;
			}
			case 4:
			{
				cout << "1__ Сухопутные туры" << endl;
				cout << "2__ Морские туры" << endl;
				cout << "3__ Местные туров" << endl << endl;
				cout << "___ Выберите тип тура: ";

				int chj;
				chj = enterInt(1,3);
				switch (chj)
				{
					case 1: 
					{
						LandInternational::header();
						lands->show();
						LandInternational::headerLine();
						makeOrder(lands);
						break;
					}
					case 2: 
					{
						SeaInternational::header();
						sea->show();
						SeaInternational::headerLine();
						makeOrder(sea);
						break;
					}
					case 3:
					{
						LocalTour::header();
						localtours->show();
						LocalTour::headerLine();
						makeOrder(localtours);
						break;
					}
					default: break;
				}
				break;
			}
			case 5: 
			{
				cout << "___ Мои заказы" << endl << endl;
				int l = 0;
				cout << "1__ Сухопутные туры" << endl << endl;
				
				LandInternational::header();

				for (int i = 0; i < orders->getSize(); i++)
				{
					if ((*orders)[i].getClientCode() == client.getClientCode()) 
					{
						for (int j = 0; j < lands->getSize(); j++) 
						{
							if ((*orders)[i].getTourCode() == (*lands)[j].getTourCode()) 
							{
								(*lands)[j].Show();
								cout << endl;
								l++;
							}
						}
					}
				}
				LandInternational::headerLine();
				if (l == 0) cout << "___ Пусто" << endl;
				cout << "\n\n";
				l = 0;
				cout << "2__ Морские туры" << endl << endl;	
				SeaInternational::header();
				for (int i = 0; i < orders->getSize(); i++)
				{
					if ((*orders)[i].getClientCode() == client.getClientCode())
					{
						for (int j = 0; j < sea->getSize(); j++) 
						{
							if ((*orders)[i].getTourCode() == (*sea)[j].getTourCode())
							{
								(*sea)[j].Show();
								cout << endl;
								l++;
							}
						}
					}
				}

				SeaInternational::headerLine();
				
				if (l == 0) cout << "___ Пусто" << endl;
				cout << "\n\n";
				l = 0;
				cout << "3__ Местные туров" << endl << endl;
				LocalTour::header();
				for (int i = 0; i < orders->getSize(); i++)
				{
					if ((*orders)[i].getClientCode() == client.getClientCode())
					{
						for (int j = 0; j < localtours->getSize(); j++) {
							if ((*orders)[i].getTourCode() == (*localtours)[j].getTourCode()) 
							{
								(*localtours)[j].Show();
								cout << endl;
								l++;
							}
						}
					}
				}
				LocalTour::headerLine();
				if (l == 0) cout << "___ Пусто" << endl;
				break;
			}
			case 6: 
			{
				cout << "___ Мои билеты" << endl << endl;

				Ticket::header();
				for (int i = 0; i < tickets->getSize(); i++)
				{
					if ((*tickets)[i].getUserCode() == client.getClientCode())
					{
						//
						cout << " " << i + 1;
						(*tickets)[i].Show();
						cout << endl;
					}
				}
				Ticket::headerLine();
				break;
			}
		}
		cout << endl;
		system("pause");

		writeOrder();
	} while (vybor != 0);
}

inline void InterfaceClient::loadTicket()
{
	char filename[30] = "tickets.txt";
	File<Ticket> f(filename);
	Ticket t;
	while (1) {
		f.ReadData(t);
		if (f.REndFile())
			break;
		tickets->enqueue(t);
	}
}

inline void InterfaceClient::loadOrder()
{
	char filename[30] = "orders.txt";
	
}

inline void InterfaceClient::writeOrder()
{
	char filename[30] = "orders.txt";
	File<Order> f(filename);
	while (orders->getSize()!=0)
	{
		Order t = orders->dequeue();
		f.WriteData(t);
	}
}

template<class T>
inline void InterfaceClient::makeOrder(Queue<T>* q)
{
	cout << "___ Введите номер тура" << endl;
	int k;
	cin >> k;
	k--;
	Order r;
	r.setClientCode(client.getClientCode());
	r.setTourCode((*q)[k].getTourCode());
	orders->enqueue(r);
}

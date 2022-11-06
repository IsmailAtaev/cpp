#include "Header.h"
#include "Interface.h"
#include "Client.h"
#include "File.h"
#include "Order.h"
#include "SeaInternational.h"
#include "LandInternational.h"
#include "LocalTour.h"
#include "Ticket.h"
#include "InterfaceClient.h"
#include "Functions.h"

void AdminMenu();

int main() 
{
	system("chcp 1251");
	setlocale(LC_ALL, "rus");
	system("cls");

	int vybor;
	char f[30] = "clients.txt";

	Queue<Client>* clients = new Queue<Client>;

	ReadDataFromFile(clients, f);

	do {
		system("cls");
		cout << "___ ����� ���������� � ������� �������������� ���������!" << endl << endl;
		cout << "1__ ����� � �������" << endl;
		cout << "2__ �����������" << endl;
		cout << "3__ ����� �� ���������" << endl << endl;
		
		vybor = enterInt(1, 3);
		cout << endl;
		
		if (vybor == 1)
		{
			string _log, _pas;
			cout << "___ �����: "; cin >> _log;
			cout << "___ ������: ";	cin >> _pas;

			if (_log == "admin" && _pas == "admin")
			{
				AdminMenu();
			}
			else 
			{
				bool found = false;
				int k;
				for (int i = 0; i < clients->getSize(); i++) 
				{
					if ((*clients)[i].getLogin() == _log && (*clients)[i].getPassword() == _pas)
					{
						found = true;
						k = i;
						break;
					}
				}

				if (found)
				{
					cout << "___ �������" << endl << endl;
					system("pause");

					InterfaceClient interfaceCC((*clients)[k]);
					interfaceCC.start();
				}
				else 
				{
					cout << "___ ������������ ������" << endl;
				}
			}
		}
		else if (vybor == 2) 
		{
			Client obj;
			obj.PutData();
			clients->enqueue(obj);
		}
		system("pause");
	} while (vybor != 3);
	
	WriteDataToFile(clients, f);
	return 0;
}

void AdminMenu()
{
	int vybor;
	do {
		system("cls");
		cout << "___ ���� ��������������" << endl << endl;
		cout << "1__ ������ ���������� ����" << endl;
		cout << "2__ ������ ������� ����" << endl;
		cout << "3__ ������ ������� ����" << endl;
		cout << "0__ ����� �� ���������" << endl;

		vybor = enterInt(0, 3);
		switch (vybor) 
		{
			case 1: 
			{
				char filename[30] = "landtours.txt";
				Interface<LandInternational> LAND_TOUR_INTERFACE(filename);
				LAND_TOUR_INTERFACE.start();
				break;
			}
			case 2: 
			{
				char filename[30] = "seatours.txt";
				Interface<SeaInternational> SEA_TOUR_INTERFACE(filename);
				SEA_TOUR_INTERFACE.start();
				break;
			}
			case 3:
			{
				char filename[30] = "localtours.txt";
				Interface<LocalTour> LOCAL_TOUR_INTERFACE(filename);
				LOCAL_TOUR_INTERFACE.start();
				break;
			}
			default: break;
		}
	} while (vybor != 0);
}
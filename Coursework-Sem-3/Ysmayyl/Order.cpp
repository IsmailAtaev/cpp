#include "Order.h"
#include "Functions.h"

Order::Order() { }

Order::~Order() { }

Order::Order(const Order& obj)
{
	clientCode = obj.clientCode;
	tourCode = obj.tourCode;
}

Order& Order::operator=(const Order& obj)
{
	if (this != &obj) 
	{
		clientCode = obj.clientCode;
		tourCode = obj.tourCode;
	}
	return *this;
}

string Order::getClientCode()
{
	return clientCode;
}

void Order::setClientCode(string clientCode)
{
	this->clientCode = clientCode;
}

string Order::getTourCode()
{
	return tourCode;
}

void Order::setTourCode(string _t)
{
	tourCode = _t;
}

void Order::Edit()
{
	cout << " ___ �������� ����� ���� ��������" << endl << endl;

	cout << "1___ ����� �������\n";
	cout << "2___ ��� ����\n";
	cout << "0___ �����\n";

	int choice;

	choice = enterInt(0, 2);

	switch (choice)
	{
		case 1:
		{
			cout << "1___ ����� �������: ";
			clientCode = enterCharOnly();
			break;
		}
		case 2: 
		{
			cout << "2___ ��� ����: ";
			tourCode = enterCharOnly();
			break;
		}
	}
}

void Order::PutData()
{
	cout << " ___ ������� ������" << endl << endl;

	cout << "1___ ������� ��� ���������� ���: ";
	clientCode = enterCharOnly();
	cout << "2___ ��� ����: ";
	tourCode = enterCharOnly();
}

void Order::Show()
{
	cout << setw(16) << clientCode << " " << setw(16) << tourCode;
}

void Order::header()
{
	cout << "--- --------------- ---------------" << endl;
	cout << " �      ID �������         ID ���� " << endl;
	cout << "--- --------------- ---------------" << endl;
}

void Order::headerLine()
{
	cout << "--- --------------- ---------------" << endl;
}

fstream& operator<<(fstream& f, Order& obj)
{
	f << obj.clientCode << " " << obj.tourCode << endl;
	return f;
}

fstream& operator>>(fstream& f, Order& obj)
{
	f >> obj.clientCode >> obj.tourCode;
	
	//getline(f, obj.tourCode, '\n');
	
	return f;
}

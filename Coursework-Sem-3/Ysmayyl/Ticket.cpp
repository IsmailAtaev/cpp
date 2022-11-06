#include "Ticket.h"
#include "Functions.h"

Ticket::Ticket() { }

Ticket::~Ticket() { }

Ticket::Ticket(string _tCode, string _uCode, string _tType, string _dPoint, string _aPoint, string _dData)
{
	ticketCode = _tCode;
	userCode = _uCode;
	transportType = _tType;
	departurePoint = _dPoint;
	arrivalPoint = _aPoint;
	deprtureData = _dData;
}

Ticket::Ticket(const Ticket& obj)
{
	ticketCode = obj.ticketCode;
	userCode = obj.userCode;
	transportType = obj.transportType;
	departurePoint = obj.departurePoint;
	arrivalPoint = obj.arrivalPoint;
	deprtureData = obj.deprtureData;
	//arrivalData = obj.arrivalData;
}

void Ticket::setTicketCode(string _s)
{
	ticketCode = _s;
}

void Ticket::setUserCode(string _s)
{
	userCode = _s;
}

void Ticket::setTransportType(string _s)
{
	transportType = _s;
}

void Ticket::setDeparturePoint(string _s)
{
	departurePoint = _s;
}

void Ticket::setArrivalPoint(string _s)
{
	arrivalPoint = _s;
}

void Ticket::setDepartureData(string _s)
{
	deprtureData = _s;
}

void Ticket::Edit() { }

Ticket& Ticket::operator=(const Ticket& obj)
{
	if (this != &obj) 
	{
		ticketCode = obj.ticketCode;
		userCode = obj.userCode;
		transportType = obj.transportType;
		departurePoint = obj.departurePoint;
		arrivalPoint = obj.arrivalPoint;
		deprtureData = obj.deprtureData;
	}
	return *this;
}


void Ticket::PutData()
{
	cout << " ___ ������� ������" << endl << endl;

	cout << "1___ ���������� ��� ��� ������: ";
	ticketCode = enterCharOnly();
	cout << "2___ ��� ����������: ";
	transportType = enterCharOnly();
	cout << "3___ ����� �����������: ";
	departurePoint = enterCharOnly();
	cout << "4___ ����� ��������: ";
	arrivalPoint = enterCharOnly();
	cout << "5___ ���� �����������: ";
	cin >> deprtureData;
}

void Ticket::Show()
{
	cout << setw(11) << ticketCode << setw(16) << transportType << setw(16) << departurePoint << setw(16) << arrivalPoint << setw(16) << deprtureData;
}

void Ticket::header()
{
	cout << "--- ---------- --------------- --------------- --------------- ---------------" << endl;
	cout << " �  ID ������     ��� ������.     ����� ����.     ����� ����.      ���� ����. " << endl;
	cout << "--- ---------- --------------- --------------- --------------- ---------------" << endl;
}

void Ticket::headerLine()
{
	cout << "--- ---------- --------------- --------------- --------------- ---------------" << endl;
}

string Ticket::getTicketCode()
{
	return ticketCode;
}

string Ticket::getUserCode()
{
	return userCode;
}

string Ticket::getTransportType()
{
	return transportType;
}

string Ticket::getDeparturePoint()
{
	return departurePoint;
}

string Ticket::getArrivalPoint()
{
	return arrivalPoint;
}


string Ticket::getDepartureData()
{
	return deprtureData;
}

// ������������� �������� ������ ��� ������ ������ � ����
fstream& operator<<(fstream& f, Ticket& obj)
{
	f << obj.arrivalPoint << " " << obj.departurePoint << " " << obj.deprtureData
		<< " " << obj.ticketCode << " " << obj.userCode << " " << obj.transportType << endl;
	return f;
}

// ������������� �������� ����� ��� ������ ������ � �����
fstream& operator>>(fstream& f, Ticket& obj)
{
	f >> obj.arrivalPoint >> obj.departurePoint >> obj.deprtureData >> obj.ticketCode >> obj.userCode>> obj.transportType;
	return f;
}

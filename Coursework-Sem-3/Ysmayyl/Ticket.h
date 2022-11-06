#pragma once
#include "Header.h"
#include "Information.h"

class Ticket : public Information
{
private:
	string ticketCode;
	string userCode;
	string transportType;
	string departurePoint;
	string arrivalPoint;
	string deprtureData;
	//string arrivalData; 
public:
	Ticket();
	~Ticket();
	Ticket(string _tCode, string _uCode, string _tType, string _dPoint, string _aPoint, string _dData);
	Ticket(const Ticket& obj);

	Ticket& operator=(const Ticket& obj);
	
	friend fstream& operator<<(fstream& f, Ticket& obj);
	friend fstream& operator>>(fstream& f, Ticket& obj);
	
	string getTicketCode();
	string getUserCode();
	string getTransportType();
	string getDeparturePoint();
	string getArrivalPoint();
	string getDepartureData();

	void setTicketCode(string _s);
	void setUserCode(string _s);
	void setTransportType(string _s);
	void setDeparturePoint(string _s);
	void setArrivalPoint(string _s);
	void setDepartureData(string _s);

	void Edit() override;
	void PutData() override;
	void Show() override;

	static void header();
	static void headerLine();
};


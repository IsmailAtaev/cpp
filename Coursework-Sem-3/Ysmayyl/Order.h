#pragma once
#include "Header.h"
#include "Information.h"
class Order : public Information
{
private:
	string clientCode;
	string tourCode;

public:
	Order();
	~Order();
	Order(const Order& obj);
	
	Order& operator=(const Order& obj);
	
	friend fstream& operator<<(fstream& f, Order& obj);
	friend fstream& operator>>(fstream& f, Order& obj);

	string getClientCode();
	void setClientCode(string clientCode);

	string getTourCode();
	void setTourCode(string _t);

	void Edit() override;
	void PutData() override;
	void Show() override;

	static void header();
	static void headerLine();
};


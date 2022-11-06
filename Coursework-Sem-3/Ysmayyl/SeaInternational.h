#pragma once
#include "InternationalTour.h"
class SeaInternational :
	public InternationalTour
{
private:

	string cargoName;
	string seaName;
public:
	SeaInternational();
	~SeaInternational();

	SeaInternational(const SeaInternational& obj);
	SeaInternational& operator=(const SeaInternational& obj);


	friend fstream& operator<< (fstream& f, SeaInternational& obj);
	friend fstream& operator>> (fstream& f, SeaInternational& obj);

	void setCargoName(string _c);
	void setSeaName(string _s);
	string getCargoName();
	string getSeaName();

	void Edit() override;
	void PutData() override;
	void Show() override;

	static void header();
	static void headerLine();
};


#pragma once
#include "InternationalTour.h"

class LandInternational:public InternationalTour
{
private:
	string carType;
public:
	LandInternational();
	~LandInternational();

	LandInternational(const LandInternational& obj);
	LandInternational& operator=(const LandInternational& obj);

	friend fstream& operator<< (fstream& f, LandInternational& obj);
	friend fstream& operator>> (fstream& f, LandInternational& obj);

	string getCarType();
	void setCarTpye(string _t);

	void Edit() override;
	void PutData() override;
	void Show() override;

	static void header();
	static void headerLine();
};


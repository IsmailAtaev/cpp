#pragma once
#include "Tour.h"

class InternationalTour :
	public Tour
{
protected:
	
	string country;
	string city;

public:

	InternationalTour() {};
	~InternationalTour() {};

	string getCountry();
	string getCity();

	void setCountry(string s);
	void setCity(string s);

};


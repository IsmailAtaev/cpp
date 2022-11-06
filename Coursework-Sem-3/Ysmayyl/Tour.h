#pragma once
#include "Header.h"
#include "Information.h"
class Tour : public Information
{
protected:
	string tourName;
	string tourCode;
	string tourType;
	string tourDate;
	int duration;
	float price;
public:
	Tour();
	~Tour();
	Tour(const Tour& obj);
	string getTourCode();
	string getTourName();
	string getTourType();
};


#include "Tour.h"

Tour::Tour(){ }

Tour::~Tour(){ }

Tour::Tour(const Tour& obj)
{
	tourName = obj.tourName;
	tourCode = obj.tourCode;
	tourType = obj.tourType;
	tourDate = obj.tourDate;
	duration = obj.duration;
	price = obj.price;
}

string Tour::getTourCode()
{
	return tourCode;
}

string Tour::getTourName()
{
	return tourName;
}

string Tour::getTourType()
{
	return tourType;
}

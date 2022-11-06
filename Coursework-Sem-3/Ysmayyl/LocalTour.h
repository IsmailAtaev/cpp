#pragma once
#include "Tour.h"
class LocalTour :
	public Tour
{
private:
	string city;
public:
	LocalTour();
	~LocalTour();
	LocalTour(const LocalTour& obj);

	LocalTour& operator=(const LocalTour& obj);

	friend fstream& operator>>(fstream& f, LocalTour& obj);
	friend fstream& operator<<(fstream& f, LocalTour& obj);

	void Edit() override;
	void PutData() override;
	void Show() override;

	static void header();
	static void headerLine();
};
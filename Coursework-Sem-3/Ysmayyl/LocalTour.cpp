#include "LocalTour.h"
#include "Functions.h"

LocalTour::LocalTour() { }

LocalTour::~LocalTour() { }

LocalTour::LocalTour(const LocalTour& obj)
{
	tourCode = obj.tourCode;
	tourType = obj.tourType;
	tourDate = obj.tourDate;
	duration = obj.duration;
	price = obj.price;
	city = obj.city;
	tourName = obj.tourName;
}

LocalTour& LocalTour::operator=(const LocalTour& obj)
{
	if (this != &obj) {
		tourCode = obj.tourCode;
		tourType = obj.tourType;
		tourDate = obj.tourDate;
		duration = obj.duration;
		price = obj.price;
		city = obj.city;
		tourName = obj.tourName;
	}
	return *this;
}

void LocalTour::Edit()
{
	cout << " ___ �������� ����� ���� ��������" << endl << endl;

	cout << "1___ ������� ����\n";
	cout << "2___ ��� ����\n";
	cout << "3___ ��� ����\n";
	cout << "4___ ����\n";
	cout << "5___ ������������\n";
	cout << "6___ ����\n";
	cout << "7___ �����\n";
	cout << "0___ �����\n";

	int choice;

	choice = enterInt(0, 7);

	switch (choice) {
		case 1: {
			cout << "1___ ������� ����: ";
			tourName = enterCharOnly();
			break;
		}
		case 2: {
			cout << "2___ ���������� ��� ��� ����: ";
			tourCode = enterCharOnly();
			break;
		}
		case 3: {
			cout << "3___ ��� ����: ";
			tourType = enterCharOnly();
			break;
		}
		case 4: {
			cout << "4___ ����: ";
			cin >> tourDate ;
			break;
		}
		case 5: {
			cout << "5___ ������������: ";
			duration = enterInt(1,30);
			break;
		}
		case 6: {
			cout << "6___ ����: ";
			price = enterInt(0, 999999);
			break;
		}
		case 7: {
			cout << "7___ �����: ";
			city = enterCharOnly();
			break;
		}
	}
}

void LocalTour::PutData()
{
	cout << " ___ ������� ������" << endl << endl;

	cout << "1___ ������� ����: ";
	tourName = enterCharOnly();
	cout << "2___ ���������� ��� ��� ����: ";
	tourCode = enterCharOnly();
	cout << "3___ ��� ����: ";
	tourType = enterCharOnly();
	cout << "4___ ����: ";
	cin >> tourDate;
	cout << "5___ ������������: ";
	cin >> duration;
	cout << "6___ ����: ";
	price = enterInt(0, 999999);
	cout << "7___ �����: ";
	city = enterCharOnly();
}

void LocalTour::Show()
{
	cout << setw(21) << tourName
		<< setw(16) << tourCode
		<< setw(16) << tourType
		<< setw(11) << tourDate
		<< setw(11) << duration
		<< setw(11) << price
		<< setw(16) << city;
}

void LocalTour::header()
{
	cout << "--- -------------------- --------------- --------------- ---------- ---------- ---------- ---------------" << endl;
	cout << " �        �������� ����         ID ����        ��� ����  ���� ����      ����.       ����           ����� " << endl;
	cout << "--- -------------------- --------------- --------------- ---------- ---------- ---------- ---------------" << endl;
}

void LocalTour::headerLine()
{
	cout << "--- -------------------- --------------- --------------- ---------- ---------- ---------- ---------------" << endl;
}

fstream& operator>>(fstream& f, LocalTour& obj)
{

	getline(f, obj.tourName, '*');
	f >> obj.tourCode >> obj.tourType >> obj.tourDate >> obj.duration >> obj.price;
	getline(f, obj.city, '\n');
	return f;
}

fstream& operator<<(fstream& f, LocalTour& obj)
{
	
	f << obj.tourName << "*" << obj.tourCode << " "		<< obj.tourType << " " << obj.tourDate << " "	<< obj.duration<< " " << obj.price << " "<< obj.city << endl;
	
	return f;
}

#include "SeaInternational.h"
#include "Functions.h"
SeaInternational::SeaInternational() { }

SeaInternational::~SeaInternational() { }

SeaInternational::SeaInternational(const SeaInternational& obj)
{
	tourCode = obj.tourCode;
	tourType = obj.tourType;
	tourDate = obj.tourDate;
	duration = obj.duration;
	price = obj.price;
	country = obj.country;
	city = obj.city;
	cargoName = obj.cargoName;
	seaName = obj.seaName;
	tourName = obj.tourName;
}

SeaInternational& SeaInternational::operator=(const SeaInternational& obj)
{
	if (this != &obj) {
		tourCode = obj.tourCode;
		tourType = obj.tourType;
		tourDate = obj.tourDate;
		duration = obj.duration;
		price = obj.price;
		country = obj.country;
		city = obj.city;
		cargoName = obj.cargoName;
		seaName = obj.seaName;
		tourName = obj.tourName;
	}
	return *this;
}

void SeaInternational::setCargoName(string _c)
{
	cargoName = _c;
}

void SeaInternational::setSeaName(string _s)
{
	seaName = _s;
}

string SeaInternational::getCargoName()
{
	return cargoName;
}

string SeaInternational::getSeaName()
{
	return seaName;
}

void SeaInternational::Edit()
{
	cout << " ___ �������� ����� ���� ��������" << endl << endl;

	cout << "1___ ������� ����\n";
	cout << "2___ ��� ����\n";
	cout << "3___ ��� ����\n";
	cout << "4___ ����\n";
	cout << "5___ ������������\n";
	cout << "6___ ����\n";
	cout << "7___ ������\n";
	cout << "8___ �����\n";
	cout << "9___ ��� ����������\n";
	cout << "10__ �������� ����\n";
	cout << "0___ �����\n";

	int choice;

	choice = enterInt(0, 10);

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
			cin >> tourDate;
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
			cout << "7___ ������: ";
			country = enterCharOnly();
			break;
		}
		case 8: {
			cout << "8___ �����: ";
			city = enterCharOnly();
			break;
		}
		case 9: {
			cout << "9___ �������� �������: ";
			cargoName = enterCharOnly();
			break;
		}
		case 10: {
			cout << "10__  �������� ����: ";
			seaName = enterCharOnly();
			break;
		}
	}

}

void SeaInternational::PutData()
{
	cout << " ___ ������� ������" << endl << endl;

	cout << "1___ ������� ����: ";
	cin >> tourName;
	cout << "2___ ���������� ��� ��� ����: ";
	cin >> tourCode;
	cout << "3___ ��� ����: ";
	cin >> tourType;
	cout << "4___ ����: ";
	cin >> tourDate;
	cout << "5___ ������������: ";
	cin >> duration;
	cout << "6___ ����: ";
	price = enterInt(0, 999999);
	cout << "7___ ������: ";
	cin >> country;
	cout << "8___ �����: ";
	cin >> city;
	cout << "9___ �������� �������: ";
	cin >> cargoName;
	cout << "10__ �������� ����: ";
	cin >> seaName;
}

void SeaInternational::Show()
{
	cout << setw(21) << tourName
		<< setw(16) << tourCode
		<< setw(16) << tourType
		<< setw(11) << tourDate
		<< setw(11) << duration
		<< setw(11) << price
		<< setw(16) << country
		<< setw(16) << city
		<< setw(16) << cargoName
		<< setw(16) << seaName;
}

void SeaInternational::header()
{
	cout << "--- -------------------- --------------- --------------- ---------- ---------- ---------- --------------- --------------- --------------- ---------------" << endl;
	cout << " �        �������� ����         ID ����        ��� ����  ���� ����      ����.       ����          ������           �����         �������            ���� " << endl;
	cout << "--- -------------------- --------------- --------------- ---------- ---------- ---------- --------------- --------------- --------------- ---------------" << endl;
}

void SeaInternational::headerLine()
{

	cout << "--- -------------------- --------------- --------------- ---------- ---------- ---------- --------------- --------------- --------------- ---------------" << endl;
}

fstream& operator<<(fstream& f, SeaInternational& obj)
{
	f << obj.tourName <<"*" << obj.tourCode << " "
		<< obj.tourType << " " << obj.tourDate << " "
		<< obj.duration << " " << obj.price << " "
		<< obj.country << " " << obj.city << " " << obj.cargoName << " " << obj.seaName << endl;
	return f;
}

fstream& operator>>(fstream& f, SeaInternational& obj)
{
	getline(f, obj.tourName, '*');
	f >> obj.tourCode >> obj.tourType >> obj.tourDate
		>> obj.duration >> obj.price >> obj.country >> obj.city >> obj.cargoName;
	getline(f, obj.seaName, '\n');
	return f;
}

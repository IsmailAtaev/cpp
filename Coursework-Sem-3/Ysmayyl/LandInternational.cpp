#include "LandInternational.h"
#include "Functions.h"

LandInternational::LandInternational() { }

LandInternational::~LandInternational() { }

LandInternational::LandInternational(const LandInternational& obj)
{
	tourCode = obj.tourCode;
	tourType = obj.tourType;
	tourDate = obj.tourDate;
	duration = obj.duration;
	tourName = obj.tourName;
	price = obj.price;
	country = obj.country;
	city = obj.city;
	carType = obj.carType;
}

LandInternational& LandInternational::operator=(const LandInternational& obj)
{
	if (this != &obj) 
	{
		tourCode = obj.tourCode;
		tourType = obj.tourType;
		tourDate = obj.tourDate;
		duration = obj.duration;
		price = obj.price;
		country = obj.country;
		city = obj.city;
		tourName = obj.tourName;
		carType = obj.carType;
	}
	return *this;
}

string LandInternational::getCarType()
{
	return carType;
}

void LandInternational::setCarTpye(string _t)
{
	carType = _t;
}

void LandInternational::Edit()
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
	cout << "0___ �����\n";

	int choice;

	choice = enterInt(0, 9);

	switch (choice) 
	{
		case 1:
		{
			cout << "1___ ������� ����: ";
			tourName = enterCharOnly();
			break;
		}
		case 2:
		{
			cout << "2___ ���������� ��� ��� ����: ";
			tourCode = enterCharOnly();
			break;
		}
		case 3:
		{
			cout << "3___ ��� ����: ";
			tourType  = enterCharOnly();
			break;
		}
		case 4:
		{
			cout << "4___ ����: ";
			cin >> tourDate;
			break;
		}
		case 5:
		{
			cout << "5___ ������������: ";
			duration = enterInt(1,30);
			break;
		}
		case 6:
		{
			cout << "6___ ����: ";
			price = enterInt(0, 999999);
			break;
		}
		case 7: 
		{
			cout << "7___ ������: ";
			country = enterCharOnly();
			break;
		}
		case 8: 
		{
			cout << "8___ �����: ";
			city = enterCharOnly();
			break;
		}
		case 9:
		{
			cout << "9___ ��� ����������: ";
			carType = enterCharOnly();
			break;
		}
	}
	
}

void LandInternational::PutData()
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
	duration = enterInt(1,30);
	cout << "6___ ����: ";
	price = enterInt(0, 999999);
	cout << "7___ ������: ";
	country = enterCharOnly();
	cout << "8___ �����: ";
	city = enterCharOnly();
	cout << "9___ ��� ����������: ";
	carType = enterCharOnly();
}

void LandInternational::Show()
{
	cout << setw(20) << tourName
		<< setw(16) << tourCode
		<< setw(16) << tourType
		<< setw(11) << tourDate
		<< setw(11) << duration
		<< setw(11) << price
		<< setw(16) << country
		<< setw(16) << city
		<< setw(16) << carType;
}

void LandInternational::header()
{
	cout << "--- -------------------- --------------- --------------- ---------- ---------- ---------- --------------- --------------- ---------------" << endl;
	cout << " �        �������� ����         ID ����        ��� ����  ���� ����      ����.       ����          ������           �����       ��������� " << endl;
	cout << "--- -------------------- --------------- --------------- ---------- ---------- ---------- --------------- --------------- ---------------" << endl;
}

void LandInternational::headerLine()
{
	cout << "--- -------------------- --------------- --------------- ---------- ---------- ---------- --------------- --------------- ---------------" << endl;
}

fstream& operator<<(fstream& f, LandInternational& obj)
{
	f << obj.tourName << "*" << obj.tourCode << " "
		<< obj.tourType << " " << obj.tourDate << " "
		<< obj.duration << " " << obj.price << " "
		<< obj.country << " " << obj.city << " " << obj.carType << endl;
	return f;
}

fstream& operator>>(fstream& f, LandInternational& obj)
{
	getline(f, obj.tourName, '*');
	f >> obj.tourCode >> obj.tourType >> obj.tourDate
		>> obj.duration >> obj.price >> obj.country >> obj.city;
	getline(f, obj.carType, '\n');
	return f;
}

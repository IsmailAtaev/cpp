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
	cout << " ___ Выберите какое поле изменить" << endl << endl;

	cout << "1___ Назвния тура\n";
	cout << "2___ Код тура\n";
	cout << "3___ Вид тура\n";
	cout << "4___ Дата\n";
	cout << "5___ Длительность\n";
	cout << "6___ Цена\n";
	cout << "7___ Страна\n";
	cout << "8___ Город\n";
	cout << "9___ Вид транспорта\n";
	cout << "0___ Назад\n";

	int choice;

	choice = enterInt(0, 9);

	switch (choice) 
	{
		case 1:
		{
			cout << "1___ Назвния тура: ";
			tourName = enterCharOnly();
			break;
		}
		case 2:
		{
			cout << "2___ Придумайте код для тура: ";
			tourCode = enterCharOnly();
			break;
		}
		case 3:
		{
			cout << "3___ Вид тура: ";
			tourType  = enterCharOnly();
			break;
		}
		case 4:
		{
			cout << "4___ Дата: ";
			cin >> tourDate;
			break;
		}
		case 5:
		{
			cout << "5___ Длительность: ";
			duration = enterInt(1,30);
			break;
		}
		case 6:
		{
			cout << "6___ Цена: ";
			price = enterInt(0, 999999);
			break;
		}
		case 7: 
		{
			cout << "7___ Страна: ";
			country = enterCharOnly();
			break;
		}
		case 8: 
		{
			cout << "8___ Город: ";
			city = enterCharOnly();
			break;
		}
		case 9:
		{
			cout << "9___ Вид транспорта: ";
			carType = enterCharOnly();
			break;
		}
	}
	
}

void LandInternational::PutData()
{
	cout << " ___ Введите данные" << endl << endl;

	cout << "1___ Назвния тура: ";
	tourName = enterCharOnly();
	cout << "2___ Придумайте код для тура: ";
	tourCode = enterCharOnly();
	cout << "3___ Вид тура: ";
	tourType = enterCharOnly();
	cout << "4___ Дата: ";
	cin >> tourDate;
	cout << "5___ Длительность: ";
	duration = enterInt(1,30);
	cout << "6___ Цена: ";
	price = enterInt(0, 999999);
	cout << "7___ Страна: ";
	country = enterCharOnly();
	cout << "8___ Город: ";
	city = enterCharOnly();
	cout << "9___ Вид транспорта: ";
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
	cout << " №        Названия тура         ID тура        Вид тура  Дата тура      Длит.       Цена          Страна           Город       Транспорт " << endl;
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

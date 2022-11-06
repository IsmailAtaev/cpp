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
	cout << "10__ Названия море\n";
	cout << "0___ Назад\n";

	int choice;

	choice = enterInt(0, 10);

	switch (choice) {
		case 1: {
			cout << "1___ Назвния тура: ";
			tourName = enterCharOnly();
			break;
		}
		case 2: {
			cout << "2___ Придумайте код для тура: ";
			tourCode = enterCharOnly();
			break;
		}
		case 3: {
			cout << "3___ Вид тура: ";
			tourType = enterCharOnly();
			break;
		}
		case 4: {
			cout << "4___ Дата: ";
			cin >> tourDate;
			break;
		}
		case 5: {
			cout << "5___ Длительность: ";
			duration = enterInt(1,30);
			break;
		}
		case 6: {
			cout << "6___ Цена: ";
			price = enterInt(0, 999999);
			break;
		}
		case 7: {
			cout << "7___ Страна: ";
			country = enterCharOnly();
			break;
		}
		case 8: {
			cout << "8___ Город: ";
			city = enterCharOnly();
			break;
		}
		case 9: {
			cout << "9___ Названия корабля: ";
			cargoName = enterCharOnly();
			break;
		}
		case 10: {
			cout << "10__  Названия море: ";
			seaName = enterCharOnly();
			break;
		}
	}

}

void SeaInternational::PutData()
{
	cout << " ___ Введите данные" << endl << endl;

	cout << "1___ Назвния тура: ";
	cin >> tourName;
	cout << "2___ Придумайте код для тура: ";
	cin >> tourCode;
	cout << "3___ Вид тура: ";
	cin >> tourType;
	cout << "4___ Дата: ";
	cin >> tourDate;
	cout << "5___ Длительность: ";
	cin >> duration;
	cout << "6___ Цена: ";
	price = enterInt(0, 999999);
	cout << "7___ Страна: ";
	cin >> country;
	cout << "8___ Город: ";
	cin >> city;
	cout << "9___ Названия корабля: ";
	cin >> cargoName;
	cout << "10__ Названия море: ";
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
	cout << " №        Названия тура         ID тура        Вид тура  Дата тура      Длит.       Цена          Страна           Город         Корабль            Море " << endl;
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

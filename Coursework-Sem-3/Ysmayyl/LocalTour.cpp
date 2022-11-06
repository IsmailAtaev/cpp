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
	cout << " ___ Выберите какое поле изменить" << endl << endl;

	cout << "1___ Назвния тура\n";
	cout << "2___ Код тура\n";
	cout << "3___ Вид тура\n";
	cout << "4___ Дата\n";
	cout << "5___ Длительность\n";
	cout << "6___ Цена\n";
	cout << "7___ Город\n";
	cout << "0___ Назад\n";

	int choice;

	choice = enterInt(0, 7);

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
			cin >> tourDate ;
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
			cout << "7___ Город: ";
			city = enterCharOnly();
			break;
		}
	}
}

void LocalTour::PutData()
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
	cin >> duration;
	cout << "6___ Цена: ";
	price = enterInt(0, 999999);
	cout << "7___ Город: ";
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
	cout << " №        Названия тура         ID тура        Вид тура  Дата тура      Длит.       Цена           Город " << endl;
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

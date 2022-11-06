#pragma once
#include "Person.h"

Person::Person(std::string Fname, std::string Lname, int Year)
{
	this->Firstname = Fname;
	this->Lastname = Lname;
	this->Year = Year;
}

Person::Person(const Person& objHuman)
{
	this->Firstname = objHuman.Firstname;
	this->Lastname = objHuman.Lastname;
	this->Year = objHuman.Year;
}

void Person::setFirstname(std::string strFirstname)
{
	this->Firstname = strFirstname;
}

void Person::setLastname(std::string  strLastname)
{
	this->Lastname = strLastname;
}

void Person::setYear(const int year)
{
	this->Year = year;
}

std::string Person::getFirstname() const
{
	return this->Firstname;
}

std::string Person::getLastname() const
{
	return this->Lastname;
}

int Person::getYear() const
{
	return this->Year;
}

std::istream& operator>>(std::istream& in, Person& objp)
{

	std::cout << " ������� �������: ";
	objp.setFirstname(input_Str(in));
	std::cout << " �������  ���: ";
	objp.setLastname(input_Str(in));
	std::cout << " ������� ��� ��������: ";
	objp.setYear(input_INT(in, 1910, 2022));

	return in;
}

std::ostream& operator<<(std::ostream& out, Person& objp)
{
	out << std::setw(15) << std::right << objp.Firstname
		<< std::setw(13) << std::right << objp.Lastname
		<< std::setw(14) << std::right << objp.Year;
	return out;
}

std::fstream& operator>>(std::fstream& f, Person& objP)
{
	char buf[size]{};

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	std::string ss = std::string(buf);
	objP.Firstname = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	objP.Lastname = ss;

	f.read(reinterpret_cast<char*>(&objP.Year), sizeof(objP.Year));
	return f;
}

std::fstream& operator<<(std::fstream& f, Person& objP)
{
	char buf[size];

	strcpy_s(buf, objP.Firstname.length() + 1, objP.Firstname.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, objP.Lastname.length() + 1, objP.Lastname.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	f.write(reinterpret_cast<char*>(&objP.Year), sizeof(objP.Year));

	return f;
}

std::ifstream& operator>>(std::ifstream& f, Person& objP)
{
	f >> objP.Firstname >> objP.Lastname >> objP.Year;
	return f;
}

std::ofstream& operator<<(std::ofstream& f, Person& objP)
{
	f << objP.Firstname << " " << objP.Lastname << " " << objP.Year << " ";
	return f;
}

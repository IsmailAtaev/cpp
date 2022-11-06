#pragma once
#include "Teacher.h"
#include "Header.h"

Teacher::Teacher(std::string Fname, std::string Lname, int YearOfBirth, std::string position, std::string speciality, int listpapers)
	:Person(Fname, Lname, YearOfBirth)
{
	this->Position = position;
	this->Speciality = speciality;
	this->Listpapers = listpapers;
}

Teacher::Teacher(const Teacher& objTeacher) :Person(objTeacher)
{
	this->Position = objTeacher.Position;
	this->Speciality = objTeacher.Speciality;
	this->Listpapers = objTeacher.Listpapers;
}

void Teacher::setPosition(const std::string tempPosition)
{
	this->Position = tempPosition;
}

void Teacher::setSpeciality(const std::string tempSpeciality)
{
	this->Speciality = tempSpeciality;
}

void Teacher::setListpapers(const int tempListpapers)
{
	this->Listpapers = tempListpapers;
}

std::string Teacher::getPosition() const
{
	return this->Position;
}

std::string Teacher::getSpeciality() const
{
	return this->Speciality;
}

int Teacher::getListpapers() const
{
	return this->Listpapers;
}

void Teacher::title()
{
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+" << std::endl;
	std::cout << "| № |   Фамилия     |   Имя     | Год Рождения  |   Должность   |  Специальность  |   Список.науч.труд. |" << std::endl;
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+" << std::endl;
}

void Teacher::Edit()
{
	system("cls");
	rewind stdin;
	std::cout << " Изменить" << std::endl;
	std::cout << "_____________________________" << std::endl;
	std::cout << " 1 Фамилию: " << std::endl;
	std::cout << " 2 Имя: " << std::endl;
	std::cout << " 3 Год рождения: " << std::endl;
	std::cout << " 4 Должность: " << std::endl;
	std::cout << " 5 Специальность: " << std::endl;
	std::cout << " 6 Количество научных трудов:" << std::endl;
	switch (input_INT(std::cin, 1, 6))
	{
	case 1: {
		std::cout << " Введите фамилию: ";
		this->setFirstname(input_Str(std::cin));
		break;
	}
	case 2: {
		std::cout << " Введите имя: ";
		this->setLastname(input_Str(std::cin));
		break;
	}
	case 3: {
		std::cout << " Введите год рождения: ";
		this->setYear(input_INT(std::cin, 1910, 2022));
		break;
	}
	case 4: {
		std::cout << " Введите Должность: ";
		this->setPosition(input_Str(std::cin));
		break;
	}
	case 5: {
		std::cout << " Введите специальность: ";
		this->setSpeciality(input_Str(std::cin));
		break;
	}
	case 6: {
		std::cout << " Введите количество научных трудов: ";
		this->setListpapers(input_INT(std::cin, 0, 500));
		break;
	}
	default: {
		std::cout << " Некоректный ввод\tВведите соотвестующие цифры" << std::endl;
		std::cin.clear(0);
		rewind(stdin);
		break;
	}
	}
}

void Teacher::edit()
{
	system("cls");
	rewind stdin;
	std::cout << " Изменить" << std::endl;
	std::cout << "____________________________________" << std::endl;
	std::cout << " 1 Фамилию: " << std::endl;
	std::cout << " 2 Имя: " << std::endl;
	std::cout << " 3 Год рождения: " << std::endl;
	std::cout << " 4 Должность: " << std::endl;
	std::cout << " 5 Специальность: " << std::endl;
	std::cout << " 6 Количество научных трудов:" << std::endl;
	char ss = 0;
	std::cin >> ss;
	system("cls");
	switch (ss)
	{
	case'1': {
		std::cout << " Введите фамилию: ";
		this->setFirstname(input_Str(std::cin));
		break;
	}
	case'2': {
		std::cout << " Введите имя: ";
		this->setLastname(input_Str(std::cin));
		break;
	}
	case'3': {
		int r;
		std::cout << " Введите год рождения: "; std::cin >> r;
		this->setYear(r);
		break;
	}
	case'4': {
		std::cout << " Введите Должность: ";
		this->setPosition(input_Str(std::cin));
		break;
	}
	case'5': {
		std::cout << " Введите специальность: ";
		this->setSpeciality(input_Str(std::cin));
		break;
	}
	case'6': {
		int m = 0;
		std::cout << " Введите количество научных трудов: "; std::cin >> m;
		this->setListpapers(m);
		break;
	}
	default: {
		std::cout << " Некоректный ввод\tВведите соотвестующие цифры" << std::endl;
		std::cin.clear(0);
		rewind(stdin);
		break;
	}
	}
}

void Teacher::vvodSearch()
{
	char gg = 0;
	std::cout << " Поиск по ?" << std::endl;
	std::cout << "1 Фамилию: " << std::endl;
	std::cout << "2 Имя: " << std::endl;
	std::cout << "3 Год рождения: " << std::endl;
	std::cout << "4 Должность: " << std::endl;
	std::cout << "5 Специальность: " << std::endl;
	std::cout << "6 Количество научных трудов: " << std::endl;
	std::cin >> gg;
	switch (gg)
	{
	case'1': {
		std::cout << " Введите фамилию: ";
		this->setFirstname(input_Str(std::cin));
		break;
	}
	case'2': {
		std::cout << " Введите  имя: ";
		this->setLastname(input_Str(std::cin));
		break;
	}
	case'3': {
		int u = 0;
		std::cout << " Введите год рождения: "; std::cin >> u;
		this->setYear(u);
		break;
	}
	case'4': {
		std::cout << " Введите Должность: ";
		this->setPosition(input_Str(std::cin));
		break;
	}
	case'5': {
		std::cout << " Введите специальность: ";
		this->setSpeciality(input_Str(std::cin));
		break;
	}
	case'6': {
		int i = 0;
		std::cout << " Введите количество научных трудов: "; std::cin >> i;
		this->setListpapers(i);
		break;
	}
	default:
		break;
	}
}

Teacher& Teacher::operator=(const Teacher& obj)
{
	if (this != &obj) {
		this->setFirstname(obj.getFirstname());
		this->setLastname(obj.getLastname());
		this->setYear(obj.getYear());
		this->Position = obj.Position;
		this->Speciality = obj.Speciality;
		this->Listpapers = obj.Listpapers;
	}
	return *this;
}

bool Teacher::operator==(Teacher& obj)
{
	if ((this->getFirstname() == obj.getFirstname() || obj.getFirstname() == "") &&
		(this->getLastname() == obj.getLastname() || obj.getLastname() == "") &&
		(this->getYear() == obj.getYear() || obj.getYear() == 0) &&
		(this->getPosition() == obj.getPosition() || obj.getPosition() == "") &&
		(this->getSpeciality() == obj.getSpeciality() || obj.getSpeciality() == "") &&
		(this->getListpapers() == obj.getListpapers() || obj.getListpapers() == 0)) {
		return true;
	}
	return false;
}

bool Teacher::operator!=(Teacher& ob2)
{
	if (this->getFirstname() != ob2.getFirstname() &&
		this->getLastname() != ob2.getLastname() &&
		this->getYear() != ob2.getYear() &&
		this->getPosition() != ob2.getPosition() &&
		this->getSpeciality() != ob2.getSpeciality() &&
		this->getListpapers() != ob2.getListpapers()) {
		return true;
	}
	else
		return false;
}

bool operator!=(Teacher& ob1, Teacher& ob2)
{
	if (ob1.getFirstname() != ob2.getFirstname() &&
		ob1.getLastname() != ob2.getLastname() &&
		ob1.getYear() != ob2.getYear() &&
		ob1.getPosition() != ob2.getPosition() &&
		ob1.getSpeciality() != ob2.getSpeciality() &&
		ob1.getListpapers() != ob2.getListpapers()) {
		return true;
	}
	else
		return false;
}



bool operator>(Teacher& obj1, Teacher& obj2)
{
	if (obj1.getFirstname() > obj2.getFirstname())
		return true;
	else
		return false;
}

std::istream& operator>>(std::istream& in, Teacher& obj)
{
	in >> dynamic_cast<Person&>(obj);
	std::cout << " Введите Должность: ";
	obj.setPosition(input_Str(in));
	std::cout << " Введите специальность: ";
	obj.setSpeciality(input_Str(in));
	std::cout << " Введите количество научных трудов: ";
	obj.setListpapers(input_INT(in, 0, 500));
	return in;
}

std::ostream& operator<<(std::ostream& out, Teacher& obj)
{
	out << dynamic_cast<Person&>(obj);
	out << std::setw(18) << std::right << obj.Position
		<< std::setw(18) << std::right << obj.Speciality
		<< std::setw(17) << std::right << obj.Listpapers;
	return out;
}

std::fstream& operator>>(std::fstream& f, Teacher& objT)
{
	f >> dynamic_cast<Person&>(objT);
	/*f.read(reinterpret_cast<char*>(&objT), sizeof(Teacher));
	std::cout << " objT " << objT << std::endl;
	system("pause");*/

	char buf[size]{};

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	std::string ss = std::string(buf);
	objT.Position = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	objT.Speciality = ss;

	f.read(reinterpret_cast<char*>(&objT.Listpapers), sizeof(objT.Listpapers));
	return f;
}

std::fstream& operator<<(std::fstream& f, Teacher& objT)
{
	f << dynamic_cast<Person&>(objT);
	char buf[size];

	strcpy_s(buf, objT.Position.length() + 1, objT.Position.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, objT.Speciality.length() + 1, objT.Speciality.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));


	f.write(reinterpret_cast<char*>(&objT.Listpapers), sizeof(objT.Listpapers));
	return f;

	/*
	f.write(objT.Position.c_str(), size);
	f.write(objT.Speciality.c_str(), size);
	f.write(reinterpret_cast<char*>(&objT.Listpapers), sizeof(objT.Listpapers));*/
	//f.write(reinterpret_cast<char*>(&objT), sizeof(Teacher));

}

std::ifstream& operator>>(std::ifstream& f, Teacher& objT)
{
	f >> dynamic_cast<Person&>(objT)
		>> objT.Position >> objT.Speciality >> objT.Listpapers;
	return f;
}

std::ofstream& operator<<(std::ofstream& f, Teacher& objT)
{
	f << dynamic_cast<Person&>(objT)
		<< objT.Position << " " << objT.Speciality << " " << objT.Listpapers << std::endl;
	return f;
}

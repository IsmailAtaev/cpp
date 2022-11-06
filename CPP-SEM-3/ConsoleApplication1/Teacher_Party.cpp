#include "Teacher_Party.h"
#include <iomanip>

Teacher_Party::Teacher_Party(std::string Fname, std::string Lname, int YearOfBirth, std::string position, std::string speciality, int listpapers, std::string NameParty, std::string Biogrophy, std::string Rol_In_Party)
	:Teacher(Fname, Lname, YearOfBirth, position, speciality, listpapers), Party(Fname, Lname, YearOfBirth, NameParty, Biogrophy)
{
	this->Rol_In_Party = Rol_In_Party;
}

void Teacher_Party::setRol_In_Party(const std::string obj) {
	this->Rol_In_Party = obj;
}

std::string Teacher_Party::getRol_In_Party()const {
	return this->Rol_In_Party;
}

void Teacher_Party::title()
{
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+---------------+---------------------------+---------------------+" << std::endl;
	std::cout << "| � |   �������     |   ���     | ��� ��������  |   ���������   |  �������������  |   ������.����.����. |    ������     |       �������������       |    ��� � ������     |" << std::endl;
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+---------------+---------------------------+---------------------+" << std::endl;
}

bool Teacher_Party::operator==(Teacher_Party& obj)
{
	if ((this->getFirstname() == obj.getFirstname() || obj.getFirstname() == "") &&
		(this->getLastname() == obj.getLastname() || obj.getLastname() == "") &&
		(this->getYear() == obj.getYear() || obj.getYear() == 0) &&
		(this->getPosition() == obj.getPosition() || obj.getPosition() == "") &&
		(this->getSpeciality() == obj.getSpeciality() || obj.getSpeciality() == "") &&
		(this->getListpapers() == obj.getListpapers() || obj.getListpapers() == 0) &&
		(this->getNameParty() == obj.getNameParty() || obj.getNameParty() == "") &&
		(this->getBiogrophy() == obj.getBiogrophy() || obj.getBiogrophy() == "") &&
		(this->getRol_In_Party() == obj.getRol_In_Party() || obj.getRol_In_Party() == "")) {
		return true;
	}
	return false;
}


Teacher_Party& Teacher_Party::operator=(const Teacher_Party& obj)
{
	if (this != &obj) {
		this->setFirstname(obj.getFirstname());
		this->setLastname(obj.getLastname());
		this->setYear(obj.getYear());
		this->setPosition(obj.getPosition());
		this->setSpeciality(obj.getSpeciality());
		this->setListpapers(obj.getListpapers());
		this->NameParty = obj.NameParty;
		this->Biogrophy = obj.Biogrophy;
		this->Rol_In_Party = obj.Rol_In_Party;
	}
	return *this;
}

void Teacher_Party::edit()
{
	char ss = 0;
	system("cls");
	rewind stdin;
	std::cout << " �������� " << std::endl;
	std::cout << "____________________________________" << std::endl;
	std::cout << " 1 �������: " << std::endl;
	std::cout << " 2 ���: " << std::endl;
	std::cout << " 3 ��� ��������: " << std::endl;
	std::cout << " 4 ���������: " << std::endl;
	std::cout << " 5 �������������: " << std::endl;
	std::cout << " 6 ���������� ������� ������:" << std::endl;
	std::cout << " 7 ������: " << std::endl;
	std::cout << " 8 �������������: " << std::endl;
	std::cin >> ss;
	system("cls");
	switch (ss)
	{
	case'1': {
		std::string fname;
		std::cout << " ������� �������: "; std::cin >> fname;
		this->setFirstname(fname);
		break;
	}
	case'2': {
		std::string lname;
		std::cout << " ������� ���: "; std::cin >> lname;
		this->setLastname(lname);
		break;
	}
	case'3': {
		int age = 0;
		std::cout << " ������� ��� ��������: "; std::cin >> age;
		this->setYear(age);
		break;
	}
	case'4': {
		std::string position;
		std::cout << " ������� ���������: "; std::cin >> position;
		this->setPosition(position);
		break;
	}
	case'5': {
		std::string speciati;
		std::cout << " ������� �������������: "; std::cin >> speciati;
		this->setSpeciality(speciati);
		break;
	}
	case'6': {
		int listpapers = 0;
		std::cout << " ������� ���������� �������-������: "; std::cin >> listpapers;
		this->setListpapers(listpapers);
		break;
	}
	case'7': {
		std::string nparty;
		std::cout << " ������� �������� ������: "; std::cin >> nparty;
		this->setNameParty(nparty);
		break;
	}
	case'8': {
		std::string bio;
		std::cout << " ������� ���������: "; std::cin >> bio;
		this->setBiogrophy(bio);
		break;
	}
	default:
		break;
	}
}

void Teacher_Party::Edit()
{
	system("cls");
	rewind stdin;
	std::cout << " ��������" << std::endl;
	std::cout << "_____________________________" << std::endl;
	std::cout << " 1 �������: " << std::endl;
	std::cout << " 2 ���: " << std::endl;
	std::cout << " 3 ��� ��������: " << std::endl;
	std::cout << " 4 ���������: " << std::endl;
	std::cout << " 5 �������������: " << std::endl;
	std::cout << " 6 ���������� ������� ������:" << std::endl;
	std::cout << " 7 �������� ������: " << std::endl;
	std::cout << " 8 �������������:" << std::endl;
	std::cout << " 9 ��� � ������:" << std::endl;
	switch (input_INT(std::cin, 1, 9))
	{
	case 1: {
		std::cout << " ������� �������: ";
		this->setFirstname(input_Str(std::cin));
		break;
	}
	case 2: {
		std::cout << " ������� ���: ";
		this->setLastname(input_Str(std::cin));
		break;
	}
	case 3: {
		std::cout << " ������� ��� ��������: ";
		this->setYear(input_INT(std::cin, 1910, 2022));
		break;
	}
	case 4: {
		std::cout << " ������� ���������: ";
		this->setPosition(input_Str(std::cin));
		break;
	}
	case 5: {
		std::cout << " ������� �������������: ";
		this->setSpeciality(input_Str(std::cin));
		break;
	}
	case 6: {
		std::cout << " ������� ���������� ������� ������: ";
		this->setListpapers(input_INT(std::cin, 0, 500));
		break;
	}
	case 7: {
		std::cout << " ������� �������� ������: ";
		this->setNameParty(input_Str(std::cin));
		break;
	}
	case 8: {
		std::cout << " ������� �������������: ";
		this->setBiogrophy(input_Str(std::cin));
		break;
	}
	case 9: {
		std::cout << " ������� ��� � ������: ";
		this->Rol_In_Party = input_Str(std::cin);
		break;
	}
	default: {
		std::cout << " ����������� ����\t������� ������������� �����" << std::endl;
		std::cin.clear(0);
		rewind(stdin);
		break;
	}
	}
}

void Teacher_Party::vvodSearch()
{
	char gg = 0;
	std::string elem;
	int count = 0;
	std::cout << " ����� �� ?" << std::endl;
	std::cout << "1 �������: " << std::endl;
	std::cout << "2 ���: " << std::endl;
	std::cout << "3 ��� ��������: " << std::endl;
	std::cout << "4 ���������: " << std::endl;
	std::cout << "5 �������������: " << std::endl;
	std::cout << "6 ���������� ������� ������: " << std::endl;
	std::cout << "7 �������� ������. " << std::endl;
	std::cout << "8 �������������. " << std::endl;
	std::cout << "9 ��� � ������. " << std::endl;
	std::cin >> gg;
	switch (gg)
	{
	case'1': {
		std::cout << " ������� �������: "; std::cin >> elem;
		this->setFirstname(elem);
		break;
	}
	case'2': {
		std::cout << " �������  ���: "; std::cin >> elem;
		this->setLastname(elem);
		break;
	}
	case'3': {
		std::cout << " ������� ��� ��������: "; std::cin >> count;
		this->setYear(count);
		break;
	}
	case'4': {
		std::cout << " ������� ���������: "; std::cin >> elem;
		this->setPosition(elem);
		break;
	}
	case'5': {
		std::cout << " ������� �������������: "; std::cin >> elem;
		this->setPosition(elem);
		break;
	}
	case'6': {
		std::cout << " ������� ���������� ������� ������: "; std::cin >> count;
		this->setListpapers(count);
		break;
	}
	case'7': std::cout << " ������� �������� ������. "; std::cin >> this->NameParty; break;
	case'8': std::cout << " ������� �������������. "; std::cin >> this->Biogrophy; break;
	case'9': std::cout << " ������� ��� � ������. "; std::cin >> this->Rol_In_Party; break;
	default:
		break;
	}
}

std::istream& operator>>(std::istream& in, Teacher_Party& RolParty)
{
	in >> dynamic_cast<Teacher&>(RolParty);
	std::cout << " ������� �������� ������. ";
	RolParty.setNameParty(input_Str(in));
	std::cout << " ������� �������������. ";
	RolParty.setBiogrophy(input_Str(in));
	std::cout << " ������� ��� � ������. ";
	RolParty.setRol_In_Party(input_Str(in));
	return in;
}

std::ostream& operator<<(std::ostream& out, Teacher_Party& objParty)
{
	out << dynamic_cast<Teacher&>(objParty)
		<< std::setw(20) << std::right << objParty.NameParty
		<< std::setw(25) << std::right << objParty.Biogrophy
		<< std::setw(23) << std::right << objParty.Rol_In_Party << std::endl;
	return out;
}

std::fstream& operator>>(std::fstream& f, Teacher_Party& objTP)
{
	f >> dynamic_cast<Teacher&>(objTP);
	char buf[size]{};


	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	std::string ss = std::string(buf);
	objTP.NameParty = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	objTP.Biogrophy = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	objTP.Rol_In_Party = ss;
	return f;
}

std::fstream& operator<<(std::fstream& f, Teacher_Party& objTP)
{
	f << dynamic_cast<Teacher&>(objTP);

	char buf[size];

	strcpy_s(buf, objTP.NameParty.length() + 1, objTP.NameParty.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, objTP.Biogrophy.length() + 1, objTP.Biogrophy.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, objTP.Rol_In_Party.length() + 1, objTP.Rol_In_Party.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	return f;
	//f.write(objTP.NameParty.c_str(), size);
	//f.write(objTP.Biogrophy.c_str(), size);
	//f.write(objTP.Rol_In_Party.c_str(), size);
	/*return f;*/
}

std::ifstream& operator>>(std::ifstream& f, Teacher_Party& objTP)
{
	f >> dynamic_cast<Teacher&>(objTP)
		>> objTP.NameParty >> objTP.Biogrophy >> objTP.Rol_In_Party;
	return f;
}

std::ofstream& operator<<(std::ofstream& f, Teacher_Party& objTP)
{
	f << dynamic_cast<Person&>(objTP)
		<< objTP.getPosition() << " "
		<< objTP.getSpeciality() << " "
		<< objTP.getListpapers() << " "
		<< objTP.NameParty << " "
		<< objTP.Biogrophy << " "
		<< objTP.Rol_In_Party << std::endl;
	return f;
}

bool operator>(Teacher_Party& obj1, Teacher_Party& obj2)
{
	if (obj1.getFirstname() > obj2.getFirstname())
		return true;
	else
		return false;
}

bool Teacher_Party::operator!=(Teacher_Party& obj)
{
	if (this->getFirstname() != obj.getFirstname() &&
		this->getLastname() != obj.getLastname() &&
		this->getYear() != obj.getYear() &&
		this->getPosition() != obj.getPosition() &&
		this->getSpeciality() != obj.getSpeciality() &&
		this->getListpapers() != obj.getListpapers() &&
		this->NameParty != obj.NameParty &&
		this->Biogrophy != obj.Biogrophy &&
		this->Rol_In_Party != obj.Rol_In_Party)
		return true;
	else
		return false;
}

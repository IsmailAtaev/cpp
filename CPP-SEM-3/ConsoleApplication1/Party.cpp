#include "Party.h"

Party::Party(std::string Fname, std::string Lname, int YearOfBirth, std::string NameParty, std::string Biogrophy)
	:Person(Fname, Lname, YearOfBirth)
{
	this->NameParty = NameParty;
	this->Biogrophy = Biogrophy;
}

Party::Party(const Party& obj) :Person(obj)
{
	this->NameParty = obj.NameParty;
	this->Biogrophy = obj.Biogrophy;
}

void Party::setNameParty(const std::string objNameParty) {
	this->NameParty = objNameParty;
}

void Party::setBiogrophy(const std::string objBiogrophy) {
	this->Biogrophy = objBiogrophy;
}

std::string Party::getNameParty()const {
	return this->NameParty;
}

std::string Party::getBiogrophy()const {
	return this->Biogrophy;
}

void Party::title()
{
	std::cout << "+---+---------------+-----------+---------------+---------------+----------------------------+" << std::endl;
	std::cout << "| № |   Фамилия     |   Имя     | Год Рождения  |  партии       |       автобиография        |" << std::endl;
	std::cout << "+---+---------------+-----------+---------------+---------------+----------------------------+" << std::endl;
}

void Party::vvodSearch()
{
	char gg = 0;
	std::string elem;
	int count = 0;
	std::cout << " Поиск по ?" << std::endl;
	std::cout << "1 Фамилию: " << std::endl;
	std::cout << "2 Имя: " << std::endl;
	std::cout << "3 Год рождения: " << std::endl;
	std::cout << "4 Название партии. " << std::endl;
	std::cout << "5 Автобиография. " << std::endl;
	std::cin >> gg;
	switch (gg)
	{
	case'1': {
		std::cout << " Введите фамилию: "; std::cin >> elem;
		this->setFirstname(elem);
		break;
	}
	case'2': {
		std::cout << " Введите  имя: "; std::cin >> elem;
		this->setLastname(elem);
		break;
	}
	case'3': {
		std::cout << " Введите год рождения: "; std::cin >> count;
		this->setYear(count);
		break;
	}
	case'4': std::cout << " Введите название партии. "; std::cin >> this->NameParty; break;
	case'5': std::cout << " Введите автобиография. "; std::cin >> this->Biogrophy; break;
	default:
		break;
	}

}

void Party::edit()
{
	char ss = 0;
	system("cls");
	rewind stdin;
	std::cout << "\tИзменить" << std::endl;
	std::cout << "____________________________________" << std::endl;
	std::cout << " 1 Фамилию: " << std::endl;
	std::cout << " 2 Имя: " << std::endl;
	std::cout << " 3 Год рождения: " << std::endl;
	std::cout << " 4 Партия: " << std::endl;
	std::cout << " 5 Автобиография: " << std::endl;
	std::cin >> ss;
	system("cls");
	switch (ss)
	{
	case'1': {
		std::string fname;
		std::cout << " Введите фамилию: "; std::cin >> fname;
		this->setFirstname(fname);
		break;
	}
	case'2': {
		std::string lname;
		std::cout << " Введите имя: "; std::cin >> lname;
		this->setLastname(lname);
		break;
	}
	case'3': {
		int age = 0;
		std::cout << " Введите год рождения: "; std::cin >> age;
		this->setYear(age);
		break;
	}
	case'4': {
		std::string nparty;
		std::cout << " Введите название партии: "; std::cin >> nparty;
		this->setNameParty(nparty);
		break;
	}
	case'5': {
		std::string bio;
		std::cout << " Введите биография: "; std::cin >> bio;
		this->setBiogrophy(bio);
		break;
	}
	default:
		break;
	}

}

void Party::Edit()
{
	system("cls");
	rewind stdin;
	std::cout << " Изменить" << std::endl;
	std::cout << "_____________________________" << std::endl;
	std::cout << " 1 Фамилию: " << std::endl;
	std::cout << " 2 Имя: " << std::endl;
	std::cout << " 3 Год рождения: " << std::endl;
	std::cout << " 4 Должность: " << std::endl;
	std::cout << " 5 Название Партии: " << std::endl;
	std::cout << " 6 Автобиография:" << std::endl;
	switch (input_INT(std::cin, 1, 5))
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
		std::cout << " Введите название партии.: ";
		this->NameParty = input_Str(std::cin);
		break;
	}
	case 5: {
		std::cout << " Введите автобиография: ";
		this->Biogrophy = input_Str(std::cin);
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

bool Party::operator==(Party& obje)
{
	if ((this->getFirstname() == obje.getFirstname() || obje.getFirstname() == "") &&
		(this->getLastname() == obje.getLastname() || obje.getLastname() == "") &&
		(this->getYear() == obje.getYear() || obje.getYear() == 0) &&
		(this->NameParty == obje.NameParty || obje.NameParty == "") &&
		(this->Biogrophy == obje.Biogrophy || obje.Biogrophy == "")) {
		return true;
	}
	return false;
}

Party& Party::operator=(const Party& obj)
{
	if (this != &obj) {
		this->setFirstname(obj.getFirstname());
		this->setLastname(obj.getLastname());
		this->setYear(obj.getYear());
		this->NameParty = obj.NameParty;
		this->Biogrophy = obj.Biogrophy;
	}
	return *this;
}

bool operator>(Party& obj1, Party& obj2)
{
	if (obj1.getFirstname() > obj2.getFirstname())
		return true;
	else
		return false;
}

bool Party::operator!=(Party& obj)
{
	if (this->getFirstname() != obj.getFirstname() &&
		this->getLastname() != obj.getLastname() &&
		this->getYear() != obj.getYear() &&
		this->NameParty != obj.NameParty &&
		this->Biogrophy != obj.Biogrophy)
		return true;
	else
		return false;
}

std::istream& operator>>(std::istream& in, Party& objParty)
{
	in >> dynamic_cast<Person&>(objParty);
	std::cout << " Название партии. ";
	objParty.setNameParty(input_Str(in));
	std::cout << " Введите автобиография. ";
	objParty.setBiogrophy(input_Str(in));
	return in;
}

std::ostream& operator<<(std::ostream& out, Party& objParty)
{
	out << dynamic_cast<Person&>(objParty);
	out << std::setw(17) << std::right << objParty.NameParty
		<< std::setw(25) << std::right << objParty.Biogrophy;
	return out;
}

std::fstream& operator>>(std::fstream& f, Party& objT)
{
	f >> dynamic_cast<Person&>(objT);
	char buf[size]{};

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	std::string ss = std::string(buf);
	objT.NameParty = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	objT.Biogrophy = ss;
	return f;
}

std::fstream& operator<<(std::fstream& f, Party& objT)
{
	f << dynamic_cast<Person&> (objT);
	char buf[size];
	strcpy_s(buf, objT.NameParty.length() + 1, objT.NameParty.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, objT.Biogrophy.length() + 1, objT.Biogrophy.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	return f;
	/*f.write(objT.NameParty.c_str(), size);
	f.write(objT.Biogrophy.c_str(), size);
	return f;*/
}

std::ifstream& operator>>(std::ifstream& f, Party& objT)
{
	f >> dynamic_cast<Person&>(objT) >> objT.NameParty >> objT.Biogrophy;
	return f;
}

std::ofstream& operator<<(std::ofstream& f, Party& objT)
{
	f << dynamic_cast<Person&> (objT) << objT.NameParty << " " << objT.Biogrophy << std::endl;
	return f;
}

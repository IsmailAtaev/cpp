#pragma once
#include "Party.h"
#include "Teacher.h"

class Teacher_Party : public Teacher, public Party
{
private:
	std::string Rol_In_Party;
public:
	Teacher_Party(std::string Fname = "", std::string Lname = "", int YearOfBirth = 0,
		std::string position = "", std::string speciality = "", int listpapers = 0,
		std::string NameParty = "", std::string Biogrophy = "", std::string Rol_In_Party = "");
	void setRol_In_Party(const std::string);
	Teacher_Party& operator =(const Teacher_Party& obj);

	std::string getRol_In_Party()const;
	static void title();

	friend std::istream& operator>>(std::istream& in, Teacher_Party&);
	friend std::ostream& operator<<(std::ostream& out, Teacher_Party&);

	friend std::fstream& operator>> (std::fstream& f, Teacher_Party& objTP);
	friend std::fstream& operator<< (std::fstream& f, Teacher_Party& objTP);

	friend std::ifstream& operator>> (std::ifstream& f, Teacher_Party& objTP);
	friend std::ofstream& operator<< (std::ofstream& f, Teacher_Party& objTP);

	friend  bool  operator > (Teacher_Party& obj1, Teacher_Party& obj2);
	bool operator ==(Teacher_Party& obj);
	bool operator != (Teacher_Party& obj);

	void edit()override;
	void Edit();
	void vvodSearch()override;

	~Teacher_Party() { }
};
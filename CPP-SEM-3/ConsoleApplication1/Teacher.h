#pragma once
#include"Person.h"

class Teacher :virtual public Person
{
private:
	std::string Position; // ƒолжность
	std::string Speciality; // специальность
	int Listpapers; // список научных трудов
public:
	Teacher(std::string Fname = "", std::string Lname = "", int YearOfBirth = 0, std::string position = "", std::string speciality = "", int listpapers = 0);
	Teacher(const Teacher& objTeacher);
	Teacher& operator=(const Teacher& obj);

	void setPosition(const std::string);
	void setSpeciality(const std::string);
	void setListpapers(const int);

	std::string getPosition()const;
	std::string getSpeciality()const;
	int getListpapers()const;

	static void title();
	void Edit();
	void edit()override;
	void vvodSearch()override;

	bool operator ==(Teacher& obj);
	bool operator != (Teacher& obj);
	friend bool operator > (Teacher& obj1, Teacher& obj2);

	friend std::istream& operator>>(std::istream& in, Teacher&);
	friend std::ostream& operator<<(std::ostream& out, Teacher&);

	friend std::fstream& operator>> (std::fstream& f, Teacher& objT);
	friend std::fstream& operator<< (std::fstream& f, Teacher& objT);

	friend std::ifstream& operator>> (std::ifstream& f, Teacher& objT);
	friend std::ofstream& operator<< (std::ofstream& f, Teacher& objT);
	~Teacher() { }
};
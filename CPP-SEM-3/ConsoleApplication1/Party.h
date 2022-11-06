#pragma once
#include "Person.h"
#include <istream>
#include <ostream>

class Party : virtual public Person
{
protected:
	std::string NameParty;
	std::string Biogrophy;
public:
	Party(std::string Fname = "", std::string Lname = "", int YearOfBirth = 0, std::string NameParty = "", std::string Biogrophy = "");
	Party(const Party& obj);

	void setNameParty(const std::string objNameParty);
	void setBiogrophy(const std::string objBiogrophy);

	std::string getNameParty()const;
	std::string getBiogrophy()const;

	static void title();

	void vvodSearch()override;
	void edit()override;
	void Edit();
	bool operator==(Party& obj);

	friend bool operator > (Party& obj1, Party& obj2);

	bool operator != (Party& obj);

	Party& operator =(const Party& obj);
	friend std::istream& operator>>(std::istream& in, Party&);
	friend std::ostream& operator<<(std::ostream& out, Party&);

	friend std::fstream& operator>> (std::fstream& f, Party& objT);
	friend std::fstream& operator<< (std::fstream& f, Party& objT);

	friend std::ifstream& operator>> (std::ifstream& f, Party& objT);
	friend std::ofstream& operator<< (std::ofstream& f, Party& objT);

	~Party() { }
};
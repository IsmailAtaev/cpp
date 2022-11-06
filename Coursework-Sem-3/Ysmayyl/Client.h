#pragma once
#include "Header.h"
#include "Information.h"
class Client : public Information
{
private:
	string clientCode;
	string FIO;
	string passportId;
	string mail;
	string mobileNumber;
	string login;
	string password;

public:
	Client();
	Client(string _l, string _p);
	~Client();
	Client(string _cCode, string _fio, string _passId, string _mail, string _mNumber, string _login, string _pass);
	Client(const Client& obj);

	Client& operator=(const Client& obj);

	friend fstream& operator<<(fstream& f, Client& obj);
	friend fstream& operator>>(fstream& f, Client& obj);
	
	string getClientCode();
	string getFio();
	string getPassportId();
	string getMail();
	string getMobileNumber();

	void setClientCode(string s);
	void setFio(string s);
	void setPasswordId(string s);
	void setMail(string s);
	void setMobile(string s);

	string getLogin() { return login; }
	string getPassword() { return password; }


	void Edit() override;
	void PutData() override;
	void Show() override;
};


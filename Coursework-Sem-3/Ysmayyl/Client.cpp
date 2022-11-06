#include "Client.h"
#include "Functions.h"
Client::Client()
{
}

Client::Client(string _l, string _p)
{
	password = _p;
	login = _l;
}

Client::~Client()
{ }

Client::Client(string _cCode, string _fio, string _passId, string _mail, string _mNumber, string _login, string _pass)
{
	clientCode = _cCode;
	passportId = _passId;
	FIO = _fio;
	mail = _mail;
	mobileNumber = _mNumber;
	login = _login;
	password = _pass;
}

Client::Client(const Client& obj)
{
	clientCode = obj.clientCode;
	passportId = obj.passportId;
	FIO = obj.FIO;
	mail = obj.mail;
	mobileNumber = obj.mobileNumber;
	password = obj.password;
	login = obj.login;
}

Client& Client::operator=(const Client& obj)
{
	if (this != &obj)
	{
		clientCode = obj.clientCode;
		passportId = obj.passportId;
		FIO = obj.FIO;
		mail = obj.mail;
		mobileNumber = obj.mobileNumber;
		password = obj.password;
		login = obj.login;
	}
	return *this;
}

string Client::getClientCode()
{
	return clientCode;
}

string Client::getFio()
{
	return FIO;
}

string Client::getPassportId()
{
	return passportId;
}

string Client::getMail()
{
	return mail;
}

string Client::getMobileNumber()
{
	return mobileNumber;
}

void Client::setClientCode(string s)
{
	clientCode = s;
}

void Client::setFio(string s)
{
	FIO = s;
}

void Client::setPasswordId(string s)
{
	passportId = s;
}

void Client::setMail(string s)
{
	mail = s;
}

void Client::setMobile(string s)
{
	mobileNumber = s;
}

void Client::Edit()
{ }

void Client::PutData()
{
	cout << "__ ����� �����: ";
	cin >> login;
	cout << "__ ����� ������: ";
	cin >> password;
	cout << "__ ���������� ���� ID: ";
	cin >> clientCode;
	cout << "__ �.�.�: ";
	FIO = enterCharOnly();
	cout << "__ ����� ��������: ";
	cin >> passportId;
	cout << "__ �����: ";
	cin >> mail;
	cout << "__ ��������� �����: ";
	cin >> mobileNumber;
}

void Client::Show()
{
	cout << setw(15) << login
		<< setw(15) << password
		<< setw(8) << clientCode
		<< setw(20) << FIO
		<< setw(15) << passportId
		<< setw(30) << mail
		<< setw(15) << mobileNumber;
}

fstream& operator<<(fstream& f, Client& obj)
{
	f << obj.login << " " << obj.password << " " 
		<< obj.clientCode << " " << obj.FIO << "*" 
		<< obj.passportId << " " 
		<< obj.mail << " " << obj.mobileNumber << endl;
	return f;
}

fstream& operator>>(fstream& f, Client& obj)
{
	f >> obj.login >> obj.password;
	f >> obj.clientCode;
	getline(f, obj.FIO, '*');
	f >> obj.passportId >> obj.mail >> obj.mobileNumber;
	return f;
}

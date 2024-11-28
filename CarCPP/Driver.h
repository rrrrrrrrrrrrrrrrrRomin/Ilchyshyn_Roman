#pragma once
#include <iostream>
using namespace std;
class Driver
{
private:
	string surname;
	string name;
	string id;
	int salary;
public:
	Driver(){}
	Driver(string surname, string name, string id, int salary);
	Driver(const Driver& driver);
	Driver(Driver&& driver);//конструктор

	string GetSurname();
	void SetSurname(string surname);
	string GetName();
	void SetName(string name);
	string GetId();
	void SetId(string id);
	int GetSalary();
	void SetSalary(int salary);

	virtual string GetInfo();//віртуальні методи
	Driver& operator=(Driver& driver);
	friend ostream& operator<<(ostream& stream, Driver& driver);
	friend istream& operator>>(istream& stream, Driver& driver);
	virtual void SetInfo(istream& stream);
};


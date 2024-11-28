#include "Driver.h"

Driver::Driver(string surname, string name, string id, int salary)
{
	this->name = name;
	this->surname = surname;
	this->id = id;
	this->salary = salary;
}

Driver::Driver(const Driver& driver)
{
	name = driver.name;
	surname = driver.surname;
	id = driver.id;
	salary = driver.salary;
}

Driver::Driver(Driver&& driver)
{
	name = move(driver.name);
	surname = move(driver.surname);
	id = move(driver.id);
	salary = move(driver.salary);
}

string Driver::GetSurname()
{
	return surname;
}

void Driver::SetSurname(string surname)
{
	this->surname = surname;
}

string Driver::GetName()
{
	return name;
}

void Driver::SetName(string name)
{
	this->name = name;
}

string Driver::GetId()
{
	return id;
}

void Driver::SetId(string id)
{
	this->id = id;
}

int Driver::GetSalary()
{
	return salary;
}

void Driver::SetSalary(int salary)
{
	this->salary = salary;
}

string Driver::GetInfo()
{
	return "Name: " + name + ", surname: " + surname + ". ";
}

Driver& Driver::operator=(Driver& driver)
{
	name = driver.name;
	surname = driver.surname;
	id = driver.id;
	salary = driver.salary;
	return *this;
}

void Driver::SetInfo(istream& stream)
{
	cout << "Input driver`s data" << endl;
	cout << "Surname: ";
	stream >> surname;
	cout << "Name: ";
	stream >> name;
	cout << "Id: ";
	stream >> id;
	cout << "Salary: ";
	stream >> salary;

}

ostream& operator<<(ostream& stream, Driver& driver)
{
	stream << driver.GetInfo();
	return stream;
}

istream& operator>>(istream& stream, Driver& driver)
{
	driver.SetInfo(stream);
	return stream;
}

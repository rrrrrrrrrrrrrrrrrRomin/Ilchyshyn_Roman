#include "Trip.h"

string Trip::GetSaveData()
{
	return GetNumber() + " " + GetBrand() + " " + to_string(GetCargoWeight()) + " " + to_string(GetUsedFuel()) + " "
		+ GetSurname() + " " + GetName() + " " + GetId() + " " + to_string(GetSalary()) + " "
		+ GetEndpoint() + " " + to_string(GetDistance()) + " " + to_string(GetUsedFuel()) + " " + to_string(GetCargoMaxWeight()) + " "
		+ to_string(date.tm_mday) + " " + to_string(date.tm_mon + 1) + " " + to_string(date.tm_year + 1900);
}

string Trip::GetInfo()
{
	return "Car: " + Car::GetInfo() + "\nDriver: " + Driver::GetInfo()
		+ "\nTrip details:\n" + "Date " + GetDate() + "\nTrip distance: "+to_string(distance)
		+ "\nEndpoint: "+endpoint;
}

void Trip::SetInfo(istream& stream)
{
	Driver::SetInfo(stream);
	Car::SetInfo(stream);
	cout << "Input trip data" << endl;
	cout << "Date(dd mm yyyy): ";
	int day, month, year;
	cin >> day >> month >> year;
	SetDate(day, month, year);
	cout << "Endpint: ";
	cin >> endpoint;
	cout << "Distance: ";
	cin >> distance;
	cout << "Used fuel: ";
	cin >> usedFuel;
	cout << "Cargo weight: ";
	cin >> cargoWeight;
}

Trip& Trip::operator()(Car& car)
{
	SetBrand(car.GetBrand());
	SetNumber(car.GetNumber());
	SetCargoWeight(car.GetCargoWeight());
	SetFuelUsing(car.GetFuelUsing());
	return *this;
}

void Trip::SetDate(int day, int month, int year)
{
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
}

string Trip::GetDate()
{
	return to_string(date.tm_mday) + "." + to_string(date.tm_mon + 1) + "." + to_string(date.tm_year + 1900);
}

void Trip::SetEndpoint(string endpoint)
{
	this->endpoint = endpoint;
}

string Trip::GetEndpoint()
{
	return endpoint;
}

void Trip::SetDistance(float distance)
{
	this->distance = distance;
}

float Trip::GetDistance()
{
	return distance;
}

void Trip::SetUsedFuel(float usedFuel)
{
	this->usedFuel = usedFuel;
}

float Trip::GetUsedFuel()
{
	return usedFuel;
}

void Trip::SetCargoMaxWeight(float cargo)
{
	this->cargoWeight = cargo;
}

float Trip::GetCargoMaxWeight()
{
	return cargoWeight;
}

ostream& operator<<(ostream& stream, Trip& trip)
{
	stream << trip.GetInfo();
	return stream;
}

istream& operator>>(istream& stream, Trip& trip)
{
	trip.SetInfo(stream);
	return stream;
}

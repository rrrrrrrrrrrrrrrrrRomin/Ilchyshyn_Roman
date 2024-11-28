#include "Car.h"

Car::Car(string number, string brand, float cargoWeight, float fuelUsing)
{
	this->number = number;
	this->brand = brand;
	this->cargoWeight = cargoWeight;
	this->fuelUsing = fuelUsing;
}

Car::Car(const Car& car)
{
	number = car.number;
	brand = car.brand;
	cargoWeight = car.cargoWeight;
	fuelUsing = car.fuelUsing;
}

Car::Car(Car&& car)
{
	number = std::move(car.number);
	brand = std::move(car.brand);
	cargoWeight = std::move(car.cargoWeight);
	fuelUsing = std::move(car.fuelUsing);
}

string Car::GetNumber()
{
	return number;
}

void Car::SetNumber(string number)
{
	this->number = number;
}

string Car::GetBrand()
{
	return brand;
}

void Car::SetBrand(string brand)
{
	this->brand = brand;
}

float Car::GetCargoWeight()
{
	return cargoWeight;
}

void Car::SetCargoWeight(float cargoWeight)
{
	this->cargoWeight = cargoWeight;
}

float Car::GetFuelUsing()
{
	return fuelUsing;
}

void Car::SetFuelUsing(float fuelUsing)
{
	this->fuelUsing = fuelUsing;
}

Car& Car::operator()(string brand, string number)//перевантаженні оператори
{
	this->brand = brand;
	this->number = number;
	return *this;
}

Car& Car::operator=(Car& car)
{
	number = car.number;
	brand = car.brand;
	cargoWeight = car.cargoWeight;
	fuelUsing = car.fuelUsing;
	return *this;
}

Car& Car::operator=(Car&& car)
{
	number = std::move(car.number);
	brand = std::move(car.brand);
	cargoWeight = std::move(car.cargoWeight);
	fuelUsing = std::move(car.fuelUsing);
	return *this;
}

string Car::GetInfo()
{
	return "Brand: " + brand + ", number: " + number + ". ";
}

void Car::SetInfo(istream& stream)
{
	cout << "Input car`s data" << endl;
	cout << "Brand: ";
	stream >> brand;
	cout << "Number: ";
	stream >> number;
	cout << "Max cargo weight: ";
	stream >> cargoWeight;
	cout << "Fuel using: ";
	stream >> fuelUsing;
}

ostream& operator<<(ostream& stream, Car& car)
{
	stream << car.GetInfo();
	return stream;
}

istream& operator>>(istream& stream, Car& car)
{
	car.SetInfo(stream);
	return stream;
}

#pragma once
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;
class Car
{
private:
	string number;
	string brand;
	float cargoWeight = 0;
	float fuelUsing = 0;
public:
	Car(){}
	Car(string number, string brand, float cargoWeight, float fuelUsing);//конструктор ініціалізації
	Car(const Car& car);
	Car(Car&& car);

	string GetNumber();
	void SetNumber(string number);
	string GetBrand();
	void SetBrand(string brand);
	float GetCargoWeight();
	void SetCargoWeight(float cargoWeight);
	float GetFuelUsing();
	void SetFuelUsing(float fuelUsing);

	Car& operator()(string brand, string number);
	Car& operator=(Car& car);
	Car& operator=(Car&& car);
	friend ostream& operator<<(ostream& stream, Car& car);
	friend istream& operator>>(istream& stream, Car& car);
	virtual string GetInfo();
	virtual void SetInfo(istream& stream);
};


#pragma once
#include "Driver.h"
#include <ostream>;
#include <istream>;
#include <string>
#include "Car.h"

using namespace std;
class Trip : public Car, public Driver//множинне наслідування
{
private:
	tm date;
	string endpoint;
	float distance;
	float usedFuel;
	float cargoWeight;
public:
	Trip(){}

	void SetDate(int day, int month, int year);
	string GetDate();
	void SetEndpoint(string endpoint);
	string GetEndpoint();
	void SetDistance(float distance);
	float GetDistance();
	void SetUsedFuel(float usedFuel);
	float GetUsedFuel();
	void SetCargoMaxWeight(float cargo);
	float GetCargoMaxWeight();

	string GetSaveData();
	string GetInfo() override;//перевантаження 
	void SetInfo(istream& stream) override;
	Trip& operator()(Car& car);
	friend ostream& operator<<(ostream& stream, Trip& trip);
	friend istream& operator>>(istream& stream, Trip& trip);
};


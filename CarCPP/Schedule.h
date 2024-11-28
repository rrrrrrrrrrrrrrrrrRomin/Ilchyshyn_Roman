#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Iterator.h"
#include "Trip.h"

using namespace std;
class Schedule
{
private:
	vector<Trip*> trips{};
	Iterator<Trip*> start;
public:
	int GetTripsCount();
	void AddTrip(Trip* trip);
	void OutputData();
	float GetUsedFuel();
	void  WriteFile();
	void  ReadFile();
	float GetCargoVolume();
	~Schedule();
};


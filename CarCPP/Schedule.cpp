#include "Schedule.h"

int Schedule::GetTripsCount()
{
	return trips.size();
}

void Schedule::AddTrip(Trip* trip)
{
	trips.push_back(trip);
	start = trips.begin();
}

void Schedule::OutputData()
{
	for (auto ptr = start; ptr != trips.end(); ++ptr) {
		cout << **ptr << endl;
	}
}

float Schedule::GetUsedFuel()
{
	float usedFuel = 0;
	for (auto ptr = start; ptr != trips.end(); ++ptr) {
		usedFuel += (*ptr) -> GetUsedFuel();
	}
	return usedFuel;
}

void Schedule::WriteFile()
{
	std::ofstream file("../trips.txt");
	for (auto ptr = start; ptr != trips.end(); ++ptr) {
		file << (*ptr)->GetSaveData() << endl;
	}
	file.close();
}

void Schedule::ReadFile()
{
	std::ifstream file("../trips.txt");
	string line;
	int pos;
	while (getline(file, line)) {
		int index = 0;
		Trip* trip = new Trip();
		int day, month, year;
		while ((pos = line.find(' ')) != string::npos) {
			string token = line.substr(0, pos);
			switch (index)
			{
			case 0:
				trip->SetNumber(token);
				break;
			case 1:
				trip->SetBrand(token);
				break;
			case 2:
				trip->SetCargoWeight(stof(token));
				break;
			case 3:
				trip->SetFuelUsing(stof(token));
				break;
			case 4:
				trip->SetSurname(token);
				break;
			case 5:
				trip->SetName(token);
				break;
			case 6:
				trip->SetId(token);
				break;
			case 7:
				trip->SetSalary(stoi(token));
				break;
			case 8:
				trip->SetEndpoint(token);
				break;
			case 9:
				trip->SetDistance(stof(token));
				break;
			case 10:
				trip->SetUsedFuel(stof(token));
				break;
			case 11:
				trip->SetCargoMaxWeight(stof(token));
				break;
			case 12:
				day = stoi(token);
				break;
			case 13:
				month = stoi(token);
				break;
			}
			line.erase(0, pos + 1);
			index++;
		}
		year = stoi(line);
		trip->SetDate(day, month, year);
		AddTrip(trip);
		index = 0;
	}
	file.close();
}

float Schedule::GetCargoVolume()
{
	float cargo = 0;
	for (auto ptr = start; ptr != trips.end(); ++ptr) {
		cargo += (*ptr)->GetCargoWeight();
	}
	return cargo;
}

Schedule::~Schedule()//деструктор
{
	for (auto ptr = start; ptr != trips.end(); ++ptr) {
		if (*ptr != nullptr) {
			delete* ptr;
		}
	}
}

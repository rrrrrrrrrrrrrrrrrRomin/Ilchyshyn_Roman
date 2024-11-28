#include <iostream>
#include <vector>
#include <fstream>
#include "Car.h"
#include "Driver.h"
#include "Trip.h"
#include "Schedule.h"

using namespace std;

void ReadCars(vector<Car>& cars);
void GetAllCars(vector<Car>& cars);

int main()
{
	vector<Car> cars{};
	Schedule schedule{};
	Driver* driver = nullptr;
	ReadCars(cars);
	int option = 0;
	while (true)
	{
		cout << "Menu" << endl;
		cout << "1. Create driver" << endl;
		cout << "2. Create trip" << endl;
		cout << "3. Get all trips" << endl;
		cout << "4. Change last driver" << endl;
		cout << "5. Change car for trip" << endl;
		cout << "6. Read file" << endl;
		cout << "7. Write file" << endl;
		cout << "8. Get all cars" << endl;
		cout << "0. Exit" << endl;

		cout << "Select menu option: ";
		cin >> option;

		system("cls");
		if (driver != nullptr) {
			cout << "Last created driver" << endl;
			cout << *driver << endl << endl;
		}

		if (option == 0) {
			break;
		}

		switch (option)
		{
		case 1: {
			driver = new Driver();
			cin >> *driver;
			break;
		}
		case 2:
		{
			driver = new Trip();
			cin >> *driver;
			if (dynamic_cast<Trip*>(driver) != nullptr) {
				schedule.AddTrip(dynamic_cast<Trip*>(driver));
			}
			break;
		}
		case 3:
		{
			cout << "All trips: " << endl;
			schedule.OutputData();
			cout << endl << "Used fuel: " << schedule.GetUsedFuel() << endl << "Cargo volume : " << schedule.GetCargoVolume() << endl;
			break;
		}
		case 4:
		{
			if (driver != nullptr) {
				cin >> *driver;
			}
			break;
		}
		case 5:
		{
			if (dynamic_cast<Trip*>(driver) != nullptr) {
				GetAllCars(cars);
				int index = 0;
				cout << "Select new car: ";
				cin >> index;
				(*dynamic_cast<Trip*>(driver))(cars[index - 1]);
			}
			break;
		}
		case 6:
		{
			int startCount = schedule.GetTripsCount();
			schedule.ReadFile();
			cout << "Added " << schedule.GetTripsCount() - startCount << " trips" << endl;
			break;
		}
		case 7:
		{
			schedule.WriteFile();
			cout << schedule.GetTripsCount() << " files were recorded" << endl;
			break;
		}
		case 8:
			GetAllCars(cars);
			break;
		default:
			cout << "Wrong input. Choose another menu element" << endl;
			break;
		}
	}

}

void GetAllCars(vector<Car>& cars) {
	cout << "All cars: " << endl;
	for (int i = 0; i < cars.size(); i++) {
		cout << i + 1 << ". " << cars[i] << endl;
	}
}

void ReadCars(vector<Car>& cars) {
	std::ifstream file("../cars.txt");

	std::string line;
	int pos;
	while (std::getline(file, line)) {
		int index = 0;
		string number, brand;
		float fuelUsing, maxCargo;
		while ((pos = line.find(' ')) != string::npos) {
			string token = line.substr(0, pos);
			switch (index)
			{
			case 0:
				number = token;
				break;
			case 1:
				brand = token;
				break;
			case 2:
				fuelUsing = std::stof(token);
				break;
			}
			line.erase(0, pos + 1);
			index++;
		}
		maxCargo = stof(line);
		Car car{ number, brand, maxCargo, fuelUsing };
		cars.push_back(car);
		index = 0;
	}
	file.close();
}

/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.cpp
Version 1.0
Author	Woong O 124820192
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/23  writing
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Parking.h"

using namespace std;

namespace sdds {

	Parking::Parking() {
		dataFileName = nullptr;
	}
	Parking::Parking(const char* name) : parkingMenu("Parking Menu, select an action:"), VehicleSelectionMenu("Select type of the vehicle:", 1) {
		if (name != nullptr && name[0] != '\0')
		{
			dataFileName = new char[strlen(name) + 1];
			strcpy(dataFileName, name);
			if (loadDataFile())
			{

				parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
				VehicleSelectionMenu << "Car" << "Motorcycle" << "Cancel";
			}
			else
			{
				cout << "Error in data file" << endl;
				if (dataFileName != nullptr)
				{
					delete[] dataFileName;
				}
				dataFileName = nullptr;
			}

		}
		else
		{
			cout << "Error in data file" << endl;
			dataFileName = nullptr;
		}

	}
	Parking::~Parking() {
		if (dataFileName != nullptr)
		{
			delete[] dataFileName;
		}
	}
	bool Parking::isEmpty() {
		return dataFileName == nullptr;
	}
	void Parking::parkingStatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
	}
	void Parking::parkingVehicle() {
		int select = VehicleSelectionMenu.run();
		if (select == 1)
		{
			cout << "Parking Car" << endl;
		}
		else if (select == 2)
		{
			cout << "Parking Motorcycle" << endl;
		}
		else if (select == 3)
		{
			cout << "Cancelled parking" << endl;
		}
	}
	void Parking::returnVehicle() {
		cout << "Returning Vehicle" << endl;
	}
	void Parking::listParked() {
		cout << "Listing Parked Vehicles" << endl;
	}
	bool Parking::closeParking() {
		cout << "Closing Parking" << endl;
		return true;
	}
	bool Parking::ExitParkingApp() {
		char input[50];
		bool flag = false;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		do
		{
			cin >> input;
			if (strcmp(input, "y")==0 || strcmp(input, "Y")==0 || strcmp(input, "n")==0 || strcmp(input, "N")==0)
			{
				flag = true;
			}
			else
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
			cin.clear();
			cin.ignore(2000, '\n');
			
		} while (flag == false);
		if (strcmp(input, "y")==0 || strcmp(input, "Y")==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Parking::loadDataFile() {
		if (!isEmpty())
		{
			cout << "loading data from " << dataFileName << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	void Parking::saveDataFile() {
		if (!isEmpty())
		{
			cout << "Saving data into " << dataFileName << endl;
		}
	}

	int Parking::run() {
		bool flag = false;
		if (!isEmpty())
		{
			do
			{
				parkingStatus();
				int select = parkingMenu.run();
				switch (select)
				{
				case 1:
					parkingVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					listParked();
					break;
				case 4:
					flag = closeParking();
					break;
				case 5:
					if (ExitParkingApp())
					{
						cout << "Exiting program!" << endl;
						saveDataFile();
						flag = true;
					}
					break;

				default:
					cout << "Invalid option!" << endl;
					break;
				}
			} while (flag == false);
			return 0;
		}
		else
		{
			return 1;
		}

	}
}
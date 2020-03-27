/* Citation and Sources...
Final Project Milestone 4
Module: ReadWritable
Filename: Vehicle.cpp
Version 1.0
Author	Woong O 124820192
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/25  writing
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "ReadWritable.h"

using namespace std;

namespace sdds {
	Vehicle::Vehicle() {
		parkingSN = 0;
		vModel = nullptr;
		licensePlate[0] = '\0';
	}
	Vehicle::Vehicle(const char* plate, const char* model, int sn) {
		if (plate == nullptr || model == nullptr || plate[0] == '\0' || model[0] == '\0' || strlen(plate) > 8 || strlen(model) < 2 || strlen(model) > 60 || sn < 0)
		{
			parkingSN = 0;
			vModel = nullptr;
			licensePlate[0] = '\0';
		}
		else
		{
			parkingSN = sn;
			strcpy(licensePlate, plate);
			vModel = new char[strlen(model) + 1];
			strcpy(vModel, model);

		}

	}
	Vehicle::~Vehicle() {
		if (isModelEmpty())
		{
			delete[] vModel;
			vModel = nullptr;
		}
	}
	bool Vehicle::isModelEmpty() const {
		bool valid = true;
		if (vModel == nullptr)
		{
			valid = false;
		}

		return valid;
	}
	void Vehicle::setEmpty() {
		licensePlate[0] = '\0';
		if (isModelEmpty())
		{
			delete[] vModel;
		}
		vModel = nullptr;
		parkingSN = 0;
	}
	bool Vehicle::isEmpty() const {
		bool valid = false;
		if (licensePlate[0] == '\0' && vModel == nullptr && parkingSN == 0)
		{
			valid = true;
		}

		return valid;
	}
	char Vehicle::getLicensePlate() const {
		return *licensePlate;
	}
	char Vehicle::getMakeModel() const {
		return *vModel;
	}
	void Vehicle::setLicensePlate(const char* LP) {
		if (LP == nullptr || LP[0] == '\0' || strlen(LP) > 8)
		{
			setEmpty();
		}
		else
		{
			char tempLP[8 + 1];
			strcpy(tempLP, LP);
			int size = strlen(tempLP) + 1;
			for (int i = 0; i < size; i++)
			{
				licensePlate[i] = toupper(tempLP[i]);
			}
		}

	}
	void Vehicle::setMakeModel(const char* model) {
		if (model == nullptr || model[0] == '\0' || strlen(model) < 2 || strlen(model) > 60)
		{
			setEmpty();
		}
		else
		{
			if (isModelEmpty())
			{
				delete[] vModel;
				vModel = nullptr;
			}

			vModel = new char[strlen(model) + 1];
			strcpy(vModel, model);

		}
	}
	int Vehicle::getParkingSpot() const {
		return parkingSN;
	}
	void Vehicle::setParkingSpot(int sn) {
		if (sn < 0)
		{
			setEmpty();
		}
		else
		{
			parkingSN = sn;
		}
	}
	bool Vehicle::operator==(const char* LP2) const {
		bool valid = true;
		char tempLP[8 + 1];
		char tempLP2[8 + 1];
		strcpy(tempLP, this->licensePlate);
		strcpy(tempLP2, LP2);
		if (strlen(tempLP) == strlen(tempLP2))
		{
			int size = strlen(tempLP) + 1;
			for (int i = 0; i < size; i++)
			{
				if (tolower(tempLP[i]) != tolower(tempLP2[i]))
				{
					valid = false;
				}
			}
		}
		else
		{
			valid = false;
		}
		return valid;
	}
	bool Vehicle::operator==(const Vehicle& cmp2) const {
		return *this == cmp2.licensePlate;
	}
	std::istream& Vehicle::read(std::istream& istr)
	{
		int tempPLnum = 0;
		char tempLP[100];
		char tempModel[100];
		if (isCsv())
		{
			istr >> tempPLnum;
			istr.ignore();
			istr.get(tempLP, 9, ',');
			istr.ignore(1000, ',');
			istr.get(tempModel, 61, ',');
			istr.ignore(1000, ',');
		}
		else
		{

			cout << "Enter Licence Plate Number: ";
			istr >> tempLP;
			while (strlen(tempLP) > 8)
			{
				if (tempLP[0] != '\0')
				{
					istr.ignore(2000, '\n');
				}
				cout << "Invalid Licence Plate, try again: ";
				istr >> tempLP;
			}
			cout << "Enter Make and Model: ";
			istr >> tempModel;
			while (strlen(tempModel) < 2 || strlen(tempModel) > 60)
			{
				if (tempModel[0] != '\0') {
					istr.ignore(2000, '\n');
				}
				cout << "Invalid Make and model, try again: ";
				istr >> tempModel;
			}
		}
		if (istr.fail())
		{
			cin.clear();
			setEmpty();
		}
		else {

			setParkingSpot(tempPLnum);
			setLicensePlate(tempLP);
			setMakeModel(tempModel);
		}
		return istr;
	}
	std::ostream& Vehicle::write(std::ostream& ostr) const
	{
		if (isEmpty())
		{
			ostr << "Invalid Vehicle Object" << endl;
		}
		else
		{

			if (isCsv())
			{
				ostr << parkingSN << "," << licensePlate << "," << vModel << ",";
			}
			else {
				ostr << "Parking Spot Number: ";
				if (parkingSN == 0)
				{
					ostr << "N/A" << endl;
				}
				else
				{
					ostr << parkingSN << endl;
				}
				ostr << "Licence Plate: " << licensePlate << endl;
				ostr << "Make and Model: " << vModel << endl;
			}
		}
		return ostr;

	}

}

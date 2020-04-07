/* Citation and Sources...
Final Project Milestone 5
Module: Car and Motorcycle
Filename: Car.cpp
Version 1.0
Author	Woong O 124820192
Revision History
-----------------------------------------------------------
Date      Reason
2020/4/3   writing
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Car.h"

using namespace std;
namespace sdds {
	Car::Car() {
		carwash = false;
	}
	Car::Car(const char* plate, const char* model) : Vehicle(plate, model) {
		if (plate == nullptr || model == nullptr || plate[0] == '\0' || model[0] == '\0' || strlen(plate) > 8 || strlen(model) < 2 || strlen(model) > 60)
		{
			carwash = false;
		}
		else
		{
			carwash = false;
		}
	}
	std::istream& Car::read(std::istream& istr) {
		if (!isCsv())
		{
			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			char input[50];
			bool flag = false;
			do
			{
				istr >> input;
				if (strcmp(input, "y") == 0 || strcmp(input, "Y") == 0)
				{
					carwash = true;
					flag = true;
				}
				else if (strcmp(input, "n") == 0 || strcmp(input, "N") == 0)
				{
					carwash = false;
					flag = true;
				}
				else
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
				cin.clear();
				cin.ignore(2000, '\n');
			} while (flag == false);
		}
		else
		{

			Vehicle::read(istr);
			istr >> carwash;
			istr.ignore(1000, '\n');
			if (istr.fail())
			{
				carwash = false;
			}

		}
		return istr;
	}
	std::ostream& Car::write(std::ostream& ostr) const {
		if (isEmpty() && carwash == false)
		{
			ostr << "Invalid Car Object" << endl;
		}
		else
		{
			if (isCsv())
			{
				ostr << "C,";
				Vehicle::write(ostr);
				ostr << carwash << endl;
			}
			else
			{
				ostr << "Vehicle type: Car"<<endl;
				Vehicle::write(ostr);
				if (carwash==true)
				{
					ostr<<"With Carwash"<<endl;
				}
				else
				{
					ostr << "Without Carwash" << endl;
				}
			}

		}
		return ostr;
	}
}
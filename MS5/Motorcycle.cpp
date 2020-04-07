/* Citation and Sources...
Final Project Milestone 5
Module: Car and Motorcycle
Filename: Motorcycle.cpp
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
#include "Motorcycle.h"

using namespace std;

namespace sdds {

	Motorcycle::Motorcycle() {
		sidecar = false;
	}
	Motorcycle::Motorcycle(const char* plate, const char* model):Vehicle(plate, model) {
		if (plate == nullptr || model == nullptr || plate[0] == '\0' || model[0] == '\0' || strlen(plate) > 8 || strlen(model) < 2 || strlen(model) > 60)
		{
			sidecar = false;
		}
		else
		{
			sidecar = false;
		}
	}
	std::istream& Motorcycle::read(std::istream& istr) {
		if (!isCsv())
		{
			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			char input[50];
			bool flag = false;
			do
			{
				istr >> input;
				if (strcmp(input, "y") == 0 || strcmp(input, "Y") == 0)
				{
					sidecar = true;
					flag = true;
				}
				else if (strcmp(input, "n") == 0 || strcmp(input, "N") == 0)
				{
					sidecar = false;
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
			istr >> sidecar;
			istr.ignore(1000, '\n');
			if (istr.fail())
			{
				sidecar = false;
			}

		}
		return istr;
	}
	std::ostream& Motorcycle::write(std::ostream& ostr)const {
		if (isEmpty() && sidecar == false)
		{
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else
		{
			if (isCsv())
			{
				ostr << "M,";
				Vehicle::write(ostr);
				ostr << sidecar << endl;
			}
			else
			{
				ostr << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(ostr);
				if (sidecar == true)
				{
					ostr << "With Sidecar" << endl;
				}
			}

		}
		return ostr;
	}
}
//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           10 Mar
//==============================================
// Worshop : 7
// 
//=============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {
	Car::Car() {
		m_carType[0] = '\0';
		m_regYear = 0;
		Vehicle();
	}
	Car::Car(const char* type, int year, int spd, int sov) :Vehicle(spd, sov) {
		if (type == nullptr || isValid(type, year) == false || spd < MIN_SPEED || sov < 1)
		{
			*this = Car();
		}
		/*if (strlen(type) == 0 || year < MIN_YEAR || spd < MIN_SPEED || sov < 1)
		{
			*this = Car();
		}
		else
		{
			strncpy(m_carType, type, MAX_CHAR);
			m_regYear = year;
		}*/

	}
	void Car::finetune() {
		if (m_regYear >= MIN_YEAR)
		{
			if (Vehicle::finetune()) {
				cout << "This car is finely tuned to default speed" << endl;
			}

		}
		else
		{
			cout << "Car cannot be tuned and has to be scraped" << endl;
		}
	}
	ostream& Car::display(ostream& os) const {
		if (m_carType[0] == '\0' && m_regYear == 0) {
			os << "Car is not initiated yet" << endl;
		}
		else
		{
			os.width(20);

			os.setf(ios::left);
			os << m_carType;
			os.unsetf(ios::left);

			os << m_regYear;
			Vehicle::display(os);
		}
		return os;
	}
	istream& Car::input(istream& in) {
		char tempType[MAX_CHAR + 1];
		int tempRegYear;
		cout << "Enter the car type: ";
		in.getline(tempType, MAX_CHAR + 1);
		cout << "Enter the car registration year: ";
		in >> tempRegYear;
		Vehicle::input(in);
		/*if (strlen(tempType) == 0 || tempRegYear < MIN_YEAR)
		{
			*this = Car();
		}
		else {

			strcpy(m_carType, tempType);
			m_regYear = tempRegYear;
		}*/
		isValid(tempType, tempRegYear);

		return in;
	}
	ostream& operator<<(ostream& os, const Car& c) {
		c.display(os);
		return os;
	}
	istream& operator>>(istream& in, Car& C) {
		C.input(in);
		return in;
	}

	bool Car::isValid(const char* type, int year)
	{
		bool valid = false;
		if (strlen(type) == 0 || year < MIN_YEAR)
		{
			*this = Car();

		}
		else {

			strcpy(m_carType, type);
			m_regYear = year;
			valid = true;
		}
		return valid;

	}
}
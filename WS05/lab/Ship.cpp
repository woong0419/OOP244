
//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           11 FEB
//==============================================
// Worshop : 5
// 
//=============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Ship.h"

using namespace std;

namespace sdds {
	Ship::Ship() {
		ship_type[0] = '\0';
		number_engines = 0;

	}
	Ship::Ship(const char* sType, Engine arreng[], int Nengine) {
		if (sType != nullptr&& sType[0]!='\0' && strlen(sType) <= 6 && Nengine > 0)
		{
			this->number_engines = Nengine;
			strcpy(this->ship_type, sType);
			for (int i = 0; i < Nengine; i++)
			{
				this->eng[i] = arreng[i];
			}
		}
		else
		{
			*this = Ship();
		}
	}
	
	bool Ship::empty() const {
		return number_engines == 0 || ship_type[0] == '\0';
	}
	float Ship::calculaterPower() const {
		float sumenginesize = 0;
		for (int i = 0; i < number_engines; i++)
		{
			sumenginesize += (float)eng[i].get();
		}
		return sumenginesize * 5;

	}
	void Ship::display() const {
		if (!empty())
		{
			cout.setf(ios::fixed);
			cout.precision(2);


			cout << ship_type << "-";

			cout.width(6);
			cout << calculaterPower() << endl;
			for (int i = 0; i < number_engines; i++)
			{
				eng[i].display();
			}
		}
		else
		{
			cout << "No available data" << endl;
		}

	}
	Ship& Ship::operator +=(Engine e) {
		if (number_engines < 10 && !empty())
		{
			eng[number_engines] = e;
			number_engines++;
		}
		else
		{
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		}
		return *this;
	}
	//class
	bool operator==(const Ship& ship1, const Ship& ship2) {
		return ship1.calculaterPower() == ship2.calculaterPower();

	}
	bool operator<(const Ship& left, double power) {

		return left.calculaterPower() < power;

	}
}
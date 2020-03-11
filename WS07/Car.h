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
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include <iostream>
#include "Vehicle.h"

namespace sdds {

	const int MAX_CHAR = 20;
	const int MIN_YEAR = 2000;

	class Car : public Vehicle {
		char m_carType[MAX_CHAR+1];
		int m_regYear;
	public:
		Car();
		Car(const char* type, int year, int spd, int sov);
		void finetune();
		bool isValid(const char* type, int year);
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Car& c);
	std::istream& operator>>(std::istream& in, Car& C);
}



#endif // !SDDS_CAR_H

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
#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include <iostream>

namespace sdds {
	const int MIN_SPEED = 100;
	const int MAX_SPEED = 140;
	class Vehicle {
		int m_speed;
		int m_noOfSeats;
	public:
		Vehicle();
		Vehicle(int spd, int nos);
		bool finetune();
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& in);

	};
	std::ostream& operator<<(std::ostream& os, const Vehicle& v);
	std::istream& operator>>(std::istream& in, Vehicle V);
}


#endif // !SDDS_VEHICLE_H

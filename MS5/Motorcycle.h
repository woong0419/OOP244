/* Citation and Sources...
Final Project Milestone 5
Module: Car and Motorcycle
Filename: Motorcycle.h
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
#ifndef SDDS_MOTORCYCLE_H_
#define SDDS_MOTORCYCLE_H_

#include "Vehicle.h"

namespace sdds {
	class Motorcycle :public Vehicle {
		bool sidecar;
	public:
		Motorcycle();
		Motorcycle(const char* plate, const char* model);
		Motorcycle(const Motorcycle& src) = delete;
		Motorcycle& operator=(const Motorcycle& src) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;
	};
}

#endif // !SDDS_MORTORCYCLE_H_

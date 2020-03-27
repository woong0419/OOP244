/* Citation and Sources...
Final Project Milestone 4
Module: ReadWritable
Filename: Vehicle.h
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
#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include "ReadWritable.h"

namespace sdds {

	class Vehicle :public ReadWritable {
		char licensePlate[8 + 1];
		char* vModel = nullptr;
		int parkingSN;
	public:
		Vehicle();
		Vehicle(const char* plate, const char* model, int sn = 0);
		~Vehicle();
		Vehicle(const Vehicle& src) = delete;
		Vehicle& operator=(const Vehicle& sec) = delete;
		int getParkingSpot() const;
		void setParkingSpot(int sn);
		bool operator==(const char* LP2) const;
		bool operator==(const Vehicle& cmp2) const;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;

		bool isModelEmpty() const;
	protected:
		void setEmpty();
		bool isEmpty() const;
		char getLicensePlate() const;
		void setLicensePlate(const char* LP);
		char getMakeModel() const;
		void setMakeModel(const char* model);
	};
}

#endif // !SDDS_VEHICLE_H_

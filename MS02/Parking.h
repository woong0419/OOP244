/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.h
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
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include "Menu.h"

namespace sdds {
	class Parking {
		char* dataFileName;
		Menu parkingMenu;
		Menu VehicleSelectionMenu;

		Parking& operator=(const Parking& src) = delete;
		bool isEmpty();
		void parkingStatus();
		void parkingVehicle();
		void returnVehicle();
		void listParked();
		bool closeParking();
		bool ExitParkingApp();
		bool loadDataFile();
		void saveDataFile();
		
	public:
		Parking();
		Parking(const char* name);
		~Parking();
		int run();
	};
}


#endif // !SDDS_PARKING_H

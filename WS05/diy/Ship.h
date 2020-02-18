#ifndef SDDS_SHIP_H_
#define SDDS_SHIP_H_
#include "Engine.h"

namespace sdds {

	class Ship {

		Engine* eng;
		char* ship_type;
		int number_engines;
		

	public:
		~Ship();
		Ship();
		Ship(const char* sType, Engine arreng[], int Nengine);//If the object receives a non-null string for the ship type of 6 characters or less, and an array of minimum length one for the engines, the object accepts the string as the ship’s type, and sets up the array.  
		
		bool empty() const;
		float calculaterPower() const;
		void display() const;
		Ship& operator +=(Engine e);
	};
	bool operator==(const Ship&, const Ship&);
	bool operator<(const Ship&, double);

}
#endif // !SDDS_SHIP_H_


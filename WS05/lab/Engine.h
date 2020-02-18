
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
#ifndef SDDS_ENGINE_H_
#define SDDS_ENGINE_H_

namespace sdds {

	const int MAX_TYPE = 30;
	
	class Engine {
		char engine_type[MAX_TYPE + 1];
		double engine_size;

	public:

		Engine();
		Engine(const char* type, double engSize);
		
		double get() const;
		void display() const;

	};
}
#endif // !SDDS_ENGINE_H_
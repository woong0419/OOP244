
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
#include "Engine.h"

using namespace std;

namespace sdds {

	Engine::Engine() {
		engine_type[0] = '\0';
		engine_size = 0;
	}
	Engine::Engine(const char* type, double engSize) {
		if (type!=nullptr && type[0]!='\0' && engSize > 0 && strlen(type) <= MAX_TYPE)
		{
			strcpy(engine_type, type);
			engine_size = engSize;
		}
		else
		{
			Engine();
		}

	}
	
	double Engine::get() const {

		return engine_size;
	}
	void Engine::display() const {

		

			cout << get() << " liters - " << engine_type << endl;
		
	}
}
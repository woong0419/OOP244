
//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           28 JAN
//==============================================
// Worshop : 3
// 
//==============================================
//Train.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Train.h"

using namespace std;

namespace sdds {

	void Train::setTrain(const char* n, int number) {
		bool valid = true;
		if (number < 1 || n == nullptr || strlen(n) == 0)
		{
			valid = false;
			id = 0;
			name[0] = '\0';
		}
		if (valid) {
			strcpy(name, n);
			id = number;
		}
		cargo = nullptr;

	}
	bool Train::isEmpty() const {
		int valid = 0;
		if (name[0] == '\0' && id == 0)
		{
			valid = 1;
		}
		return valid;
	}
	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if (isEmpty())
		{
			cout << "This is an empty train." << endl;
		}
		else
		{
			cout << "Name: " << name << " ID: " << id << endl;
			if (cargo != nullptr)
			{
				cout << "Cargo: " << cargo->description << " Weight: " << cargo->weight << endl;
			}
			else
			{
				cout << "No cargo on this train." << endl;
			}
		}
	}
	void Train::loadCargo(Cargo c) {
		cargo = new Cargo;
		*cargo = c;

	}
	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}


}
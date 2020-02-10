//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           01 FEB
//==============================================
// Worshop : 3
// 
//=============================================
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
				cout << fixed;
				cout.precision(2);
				cout << "Cargo: " << cargo->cargoDescription() << " Weight: " << cargo->cargoWeight() << endl;
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
	void Cargo::init(const char* cn, double w) {
		if (strlen(cn) != 0 && cn != nullptr)
		{
			strcpy(description, cn);
		}
		else
		{
			description[0] = '\0';
		}
		if (w >= MAX_WEIGHT || w <= MIN_WEIGHT)
		{
			weight = MIN_WEIGHT;
		}
		else
		{
			weight = w;
		}
	}
	const char* Cargo::cargoDescription() const {
		return description;
	}
	double Cargo::cargoWeight() const {
		return weight;
	}
	bool Cargo::cargoWeightIn(double w) {
		int valid = 1;
		if (weight == MAX_WEIGHT)
		{
			valid = 0;
		}
		else
		{
			weight = weight + w;
			if (weight >= MAX_WEIGHT)
			{
				weight = MAX_WEIGHT;
			}
		}
		return valid;
	}
	bool Cargo::cargoWeightde(double w) {
		int valid = 1;
		if (weight == MIN_WEIGHT)
		{
			valid = 0;
		}
		else
		{
			weight = weight - w;
			if (weight <= MIN_WEIGHT)
			{
				weight = MIN_WEIGHT;
			}
		}
		return valid;
	}
	bool Train::swapCargo(Train& t) {
		int valid = 1;
		if (cargo != nullptr && t.cargo != nullptr)
		{
			Cargo* temp = cargo;
			cargo = t.cargo;
			t.cargo = temp;
		}
		else
		{
			valid = 0;
		}
		return valid;
	}
	bool Train::increaseCargo(double w) {
		int valid = 1;
		if (cargo != nullptr)
		{
			if (cargo->cargoWeightIn(w) == 0) {
				valid = 0;
			}

		}
		else {
			valid = 0;
		}
		return valid;
	}
	bool Train::decreaseCargo(double w) {
		int valid = 1;
		if (cargo != nullptr)
		{
			if (cargo->cargoWeightde(w) == 0) {
				valid = 0;
			}
		}
		else
		{
			valid = 0;
		}
		return valid;
	}

}
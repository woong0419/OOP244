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
//Train.h
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
	const int MAX_NAME = 30;
	const int MAX_DESC = 20;
	const double MAX_WEIGHT = 700.555;
	const double MIN_WEIGHT = 40.444;

	class Cargo {
		char description[MAX_DESC + 1];
		double weight;
	public:
		void init(const char* cn, double w);
		void cargoDisplay() const;
		bool cargoWeightIn(double w);
		bool cargoWeightde(double w);
	};
	class Train
	{
		char name[MAX_NAME + 1];
		int id;
		struct Cargo* cargo;
	public:
		void setTrain(const char* n, int number);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo c);
		void unloadCargo();
		bool swapCargo(Train& t);
		bool increaseCargo(double w);
		bool decreaseCargo(double w);
	};
}
#endif
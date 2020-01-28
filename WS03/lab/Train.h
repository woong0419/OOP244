
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
// Train.h
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H
namespace sdds {

	const int MAX_NAME = 30;
	const int MAX_DESC = 20;

	struct Cargo {
		char description[MAX_DESC+1];
		double weight;
	};

	class Train
	{
		char name[MAX_NAME+1];
		int id;
		struct Cargo* cargo;
	public:
		void setTrain(const char* n, int number);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo c);
		void unloadCargo();
	};
}
#endif
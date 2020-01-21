// Gift.cpp
//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           21 JAN
//==============================================
// Worshop : 2
// 
//==============================================
#include <iostream>


#include "Gift.h"


using namespace std;

namespace sdds {


	//this fuction gets description from user input and save the input lengh as 15 which is programed inside of the cord
	void gifting(char* g_description) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> g_description;
	}
	// this fuction gets number of price from user input that the value between 0 and 999.99.
	void gifting(double& g_price) {
		cout << "Enter gift price: ";
		cin >> g_price;
		while (g_price > MAX_PRICE || g_price < 0)
		{
			cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			cout << "Enter gift price: ";
			cin >> g_price;
		}
	}
	// this fuction gets number of unit from user input higher than 1
	void gifting(int& g_units) {
		cout << "Enter gift units: ";
		cin >> g_units;
		while (g_units < 1)
		{
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> g_units;
		}
	}
	// display all the user input
	void display(const Gift& gift) {
		cout << "Gift Details:" << endl;
		cout << "Description: " << gift.g_description << endl;
		cout << "Price: " << gift.g_price << endl;
		cout << "Units: " << gift.g_units << endl;
	}

}



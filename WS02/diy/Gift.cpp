//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           25 JAN
//==============================================
// Worshop : 2
// 
//==============================================
// Gift.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Gift.h"

using namespace std;

namespace sdds {

	void gifting(Gift&g) {
		cout << "Preparing a gift..." << endl;
		gifting(g.g_description);
		cin.ignore(2000, '\n');
		gifting(g.g_price);
		cin.ignore(2000, '\n');
		gifting(g.g_units);
		cin.ignore(2000, '\n');
		wrap(g);
	}
	void gifting(char* g_description) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> g_description;
	}
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
	void display(const Gift& g) {
		cout << "Gift Details:" << endl;
		cout << "Description: " << g.g_description << endl;
		cout << "Price: " << g.g_price << endl;
		cout << "Units: " << g.g_units << endl;
		if (g.wrap_layers == 0)
		{
			cout << "Unwrapped" << endl;
		}
		else
		{
			cout << "Wrap Layers: " << g.wrap_layers << endl;
			for (int i = 0; i < g.wrap_layers; i++)
			{
				cout << "Wrap #" << i + 1 << ": " << g.wrap[i].pattern << endl;
			}
		}
	}
	bool wrap(Gift& g) {
		if (g.wrap_layers > 0)
		{
			cout << "Gift is already wrapped!" << endl;;
			return false;
		}
		else
		{
			cout << "Wrapping gifts..." << endl;
			cout << "Enter the number of wrapping layers for the Gift: ";
			cin >> g.wrap_layers;
			while (g.wrap_layers < 1)
			{
				cout << "Layers at minimum must be 1, try again." << endl;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> g.wrap_layers;
			}

			g.wrap = new Wrapping[g.wrap_layers];

			char tempPattern[MAX_PATTERN + 1];

			for (int i = 0; i < g.wrap_layers; i++)
			{

				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin.width(MAX_PATTERN + 1);
				cin >> tempPattern;
				cin.ignore(2000, '\n');

				g.wrap[i].pattern = new char[strlen(tempPattern) + 1];
				strcpy(g.wrap[i].pattern, tempPattern);

			}

			return true;
		}

	}
	bool unwrap(Gift& g) {
		if (g.wrap_layers >= 1)
		{
			cout << "Gift being unwrapped." << endl;

			for (int i = 0; i < g.wrap_layers; i++)
			{
				delete[] g.wrap[i].pattern;
			}
			delete[] g.wrap;

			g.wrap = nullptr;
			g.wrap_layers = 0;
			return true;
		}
		else
		{
			cout << "Gift isn't wrapped! Can't unwrap." << endl;;
			return false;
		}
	}
}

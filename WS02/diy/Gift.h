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
// Gift.h
#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds
{
	const int MAX_DESC = 15;
	const int MAX_PATTERN = 20;
	const double MAX_PRICE = 999.99;

	struct Gift
	{
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
		int wrap_layers;
		struct Wrapping *wrap;
	};
	struct Wrapping
	{
		char *pattern;
	};
	void gifting(Gift&g);
	void gifting(char* g_description);
	void gifting(double& g_price);
	void gifting(int& g_units);
	void display(const Gift& g);
	bool wrap(Gift& g);
	bool unwrap(Gift& g);
}



#endif // SDDS_GIFT_H

//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           04 Mar
//==============================================
// Worshop : 6
// 
//=============================================
#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include<iostream>

namespace sdds {
	class Basket {
		char* m_fruitName;
		int m_qty;
		double m_price;
	public:
		Basket();
		Basket(const char* name, int qty, double price);
		Basket(const Basket&);
		~Basket();
		void setName(const char* name);
		void setQty(int qty);
		void setPrice(double price);
		bool isempty() const;
		bool addPrice(double aprice);
		std::ostream& display(std::ostream& os) const;
		Basket& operator=(const Basket& src);
		bool operator==(const Basket& src);
		bool operator!=(const Basket& src);
	};
	std::ostream& operator<<(std::ostream& os, const Basket& bsk);
}


#endif // !SDDS_BASKET_H_
//#pragma once

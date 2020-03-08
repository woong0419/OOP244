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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Basket.h"

using namespace std;

namespace sdds {

	Basket::Basket() {
		m_fruitName = nullptr;
		m_price = 0;
		m_qty = 0;
	}
	Basket::Basket(const char* name, int qty, double price) {
		if (name == nullptr || name[0] == '\0' || qty < 1 || price < 0)
		{
			m_fruitName = nullptr;
			m_price = 0;
			m_qty = 0;
		}
		else
		{
			m_fruitName = new char[strlen(name) + 1];
			setName(name);
			setPrice(price);
			setQty(qty);
			/*
			m_fruitName = nullptr;
			m_fruitName = new char[strlen(name) + 1];
			strcpy(m_fruitName, name);
			m_price = price;
			m_qty = qty;
			*/
		}
	}
	Basket::Basket(const Basket& src) {
		if (!(src.isempty()))
		{

			m_fruitName = new char[strlen(src.m_fruitName) + 1]; // allocate memory in b5 with size of strlen
			setName(src.m_fruitName);
			setPrice(src.m_price);
			setQty(src.m_qty);
		}
		else
		{
			m_fruitName = nullptr;
			m_price = 0;
			m_qty = 0;
		}
		/*
		this->m_fruitName = new char[strlen(src.m_fruitName) + 1];
		strcpy(this->m_fruitName, src.m_fruitName);
		this->m_price = src.m_price;
		this->m_qty = src.m_qty;
		*/

	}
	Basket::~Basket() {
		delete[] m_fruitName;
		m_fruitName = nullptr;
	}
	void Basket::setName(const char* name) {
		if (name == nullptr || name[0] == '\0')
		{
			m_fruitName = nullptr;
		}
		else
		{
			strcpy(m_fruitName, name);
		}
	}
	void Basket::setQty(int qty) {
		if (qty < 1)
		{
			m_qty = 0;
		}
		else
		{
			m_qty = qty;
		}
	}
	void Basket::setPrice(double price) {
		if (price < 0)
		{
			m_price = 0;
		}
		else
		{
			m_price = price;
		}
	}
	bool Basket::isempty() const {
		if (m_fruitName == nullptr && m_price == 0 && m_qty == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Basket::addPrice(double aprice) {
		if (m_price + aprice > 0)
		{
			m_price = m_price + aprice;
			return true;
		}
		else
		{
			return false;
		}
	}
	ostream& Basket::display(ostream& os) const {
		if (isempty())
		{
			os << "The Basket has not yet been filled" << endl;
		}
		else
		{
			os << "Basket Details" << endl;
			os << "Name: " << m_fruitName << endl;
			os << "Quantity: " << m_qty << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Price: " << m_price << endl;
		}
		return os;
	}
	Basket& Basket::operator=(const Basket& src) {
		if (!src.isempty())
		{
			if (this->m_fruitName != nullptr)
			{
				delete[] this->m_fruitName; // deallocate memory of b2 if the memory is allocated.
				this->m_fruitName = new char[strlen(src.m_fruitName) + 1]; // allocate memory with size of b4.m_fruits
			}
			this->setName(src.m_fruitName);
			this->setPrice(src.m_price);
			this->setQty(src.m_qty);
		}
		return *this;
	}
	bool Basket::operator==(const Basket& src) {
		if (strcmp(this->m_fruitName, src.m_fruitName) == 0 && this->m_price == src.m_price && this->m_qty == src.m_qty)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Basket::operator!=(const Basket& src) {
		return !(*this == src);
	}
	ostream& operator<<(ostream& os, const Basket& bsk) {
		bsk.display(os);
		return os;
	}
}
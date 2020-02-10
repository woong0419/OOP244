//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           4 FEB
//==============================================
// Worshop : 4
// 
//=============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Saiyan.h"


using namespace std;
namespace sdds {
	Saiyan::Saiyan() {
		setEmpty();
	}
	Saiyan::Saiyan(const char* name, int dob, int power, int level) {
		m_name = nullptr;
		set(name, dob, power, level);
		m_super = false;
	}
	Saiyan::~Saiyan() {
		delete[] m_name;
		setEmpty();
	}

	bool Saiyan::isSuper() const {
		return m_super;
	}
	bool Saiyan::isValid() const {
		int valid = 1;
		if (m_name == nullptr && m_dob == 0 && m_power == 0)
		{
			valid = 0;
		}
		return valid;
	}
	void Saiyan::power() {
		if (isSuper())
		{
			m_power = m_power * (m_level + 1);

		}
	}
	void Saiyan::setEmpty() {
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_level = 0;
		m_super = false;
	}
	void Saiyan::display() const {
		if (isValid())
		{
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			cout << "Super Saiyan Ability: " << (isSuper() ? "Super Saiyan." : "Not super Saiyan.\n") << endl;
			if (isSuper())
			{
				cout << "Super Saiyan level is: " << m_level << endl;
			}
			
		}
		else
		{
			cout << "Invalid Saiyan!" << endl;
		}

	}
	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {

		if (name == nullptr || strlen(name) == 0 || strlen(name) > MAX_NAME || dob > 2020 || power <= 0 || level < 0)
		{
			setEmpty();
		}
		else
		{
			if (m_name != nullptr)
			{
				delete[] m_name;

			}


			m_name = new char[strlen(name) + 1];




			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			if (super) {
				m_level = level;
			}
		}
	}
	bool Saiyan::hasLost(Saiyan& other)
	{
		int valid = 1;
		if (isValid() == 0 || other.isValid() == 0)
		{
			valid = 0;
		}
		else
		{

			power();
			other.power();
			if (m_power > other.m_power)
			{
				valid = 0;

			}

		}
		return valid;
	}
}
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
	Saiyan::Saiyan(const char* name, int dob, int power) {
		set(name, dob, power);
		m_super = false;
	}
	Saiyan::~Saiyan() {
		setEmpty();
	}

	bool Saiyan::isSuper() const {
		return m_super;
	}
	bool Saiyan::isValid() const {
		int valid = 1;
		if (strlen(m_name) == 0 && m_dob == 0 && m_power == 0)
		{
			valid = 0;
		}
		return valid;
	}
	void Saiyan::setEmpty() {
		m_name[0] = '\0';
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}
	void Saiyan::display() const {
		if (isValid())
		{
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			cout << "Super Saiyan Ability: " << (isSuper() ? "Super Saiyan." : "Not super Saiyan.") << endl;
			cout << endl;
		}
		else
		{
			cout << "Invalid Saiyan!" << endl;
		}

	}
	void Saiyan::set(const char* name, int dob, int power, bool super) {
		if (name == nullptr || strlen(name) == 0 || dob > 2020 || power <= 0)
		{
			setEmpty();
		}
		else
		{
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			if (super) {
				m_super = super;
			}
		}
	}
	bool Saiyan::hasLost(const Saiyan& other) const {
		int valid = 1;
		if (m_power > other.m_power)
		{
			valid = 0;
		}
		if (isValid() == 0 || other.isValid() == 0)
		{
			valid = 0;
		}
		return valid;
	}
}
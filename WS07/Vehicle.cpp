//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           10 Mar
//==============================================
// Worshop : 7
// 
//=============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Vehicle.h"

using namespace std;

namespace sdds {
	Vehicle::Vehicle() {
		m_speed = 0;
		m_noOfSeats = 0;
	}
	Vehicle::Vehicle(int spd, int nos) {
		if (spd < MIN_SPEED || nos < 1)
		{
			*this = Vehicle();
		}
		else
		{
			m_speed = spd;
			m_noOfSeats = nos;
		}
	}
	bool Vehicle::finetune() {
		if (m_speed > MAX_SPEED)
		{
			m_speed = MIN_SPEED;
			return true;
		}
		else
		{
			cout << "The car cannot be tuned" << endl;
			return false;
		}
	}
	ostream& Vehicle::display(ostream& os) const {
		if (m_speed == 0 && m_noOfSeats == 0)
		{
			os << "This Car is not initiated" << endl;
		}
		else
		{
			os << "|" << m_speed << "|" << m_noOfSeats << endl;
			if (m_speed > MAX_SPEED)
			{
				os << "Car has to be fine-tuned for speed limit" << endl;
			}
		}
		return os;
	}
	istream& Vehicle::input(istream& in) {
		int tempSpeed;
		int tempNOS;
		cout << "Enter the Vehicle`s speed: ";
		in >> tempSpeed;
		cout << "Enter no of seats: ";
		in >> tempNOS;
		*this=Vehicle(tempSpeed, tempNOS);
		/*
		if (tempSpeed < MIN_SPEED || tempNOS < 1) {
			*this = Vehicle();
		}
		else
		{
			m_speed = tempSpeed;
			m_noOfSeats = tempNOS;
		}
		*/
		return in;
	}
	ostream& operator<<(ostream& os, const Vehicle& v) {
		v.display(os);
		return os;
	}
	istream& operator>>(istream& in, Vehicle V) {
		V.input(in);
		return in;
	}
}
//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           25 Mar
//==============================================
// Worshop : 8
// 
//==============================================
#ifndef SDDS_DOCTOR_H_
#define SDDS_DOCTOR_H_
#include "Employee.h"

namespace sdds {
	const int MIN_W_HOURS = 6;
	const int MAX_CHAR = 20;
	class Doctor : public Employee {
		char m_type[MAX_CHAR+1];
		double m_salary; // special 2000> than general
		int m_whours;
		bool m_specialist;
	public:
		Doctor();
		Doctor(const char* type, double salary, int whour, bool specialist=false);
		void setSalary(double salary);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;
	};
}

#endif // !SDDS_DOCTOR_H_

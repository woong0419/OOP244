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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Doctor.h"

using namespace std;

namespace sdds {
	Doctor::Doctor() {
		m_type[0] = '\0';
		m_salary = 0; // special 2000> than general
		m_whours = 0;
		m_specialist = false;
	}
	Doctor::Doctor(const char* type, double salary, int whour, bool specialist) {
		if (type == nullptr || type[0] == '0' || salary <= 0 || whour <= 0)
		{
			*this = Doctor();
		}
		else
		{
			strcpy(m_type, type);
			m_whours = whour;
			m_specialist = specialist;
			setSalary(salary);
		}
	}
	void Doctor::setSalary(double salary) {
		if (m_specialist==true)
		{
			m_salary = salary + 2000;
		}
		else
		{
			m_salary = salary;
		}
	}
	bool Doctor::workHours() {
		return m_whours == MIN_W_HOURS;
	}
	void Doctor::bonus() {
		if (workHours())
		{
			m_salary = 1.05 * m_salary;
		}
		else
		{
			m_salary = 1.10 * m_salary;
		}
	}
	ostream& Doctor::display(ostream& os) const {
		if (m_type == nullptr || m_type[0] == '0' || m_salary <= 0 || m_whours <= 0)
		{
			os << "Doctor is not initiated yet" << endl;
		}
		else
		{
			os << "Doctor details" << endl;
			os << "Doctor Type: " << m_type << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_salary << endl;
			os.unsetf(ios::fixed);
			os << "Working Hours: " << m_whours << endl;
		}
		return os;
	}
}
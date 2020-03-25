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
#include "Engineer.h"

using namespace std;

namespace sdds {
	Engineer::Engineer() {
		m_esalary = 0;
		m_ewhours = 0;
		m_level = 0;
	}
	Engineer::Engineer(double salary, int whours, int level) {
		if (salary > 0 && whours > 0 && level > 0)
		{
			m_ewhours = whours;
			m_level = level;
			setSalary(salary);
		}
		else
		{
			*this = Engineer();
		}
	}
	void Engineer::setSalary(double salary) {
		if (m_level == MAX_LEVEL)
		{
			m_esalary = salary + 3000;
		}
		else
		{
			m_esalary = salary;
		}
	}
	bool Engineer::workHours() {
		return m_ewhours == MIN_HOURS;
	}
	void Engineer::bonus() {
		if (!workHours() && m_level == MAX_LEVEL)
		{
			m_esalary = 1.10 * m_esalary;
		}
		else
		{
			m_esalary = 1.05 * m_esalary;
		}
	}
	ostream& Engineer::display(ostream& os) const {
		if (m_esalary > 0 && m_ewhours > 0 && m_level > 0)
		{
			os << "Engineer details" << endl;
			os << "level: " << m_level << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_esalary << endl;
			os.unsetf(ios::fixed);
			os << "Working hours: " << m_ewhours << endl;
		}
		else
		{
			os << "Engineer is not initiated yet" << endl;
		}
		return os;
	}
}
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
#ifndef SDDS_ENGINEER_H_
#define SDDS_ENGINEER_H_
#include "Employee.h"

namespace sdds {
	const int MIN_HOURS = 5;
	const int MAX_LEVEL = 4;
	class Engineer : public Employee {
		double m_esalary; // lvl4 3000> than others
		int m_ewhours;
		int m_level;
	public:
		Engineer();
		Engineer(double salary, int whours, int level);
		void setSalary(double salary);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;

	};
}

#endif // !SDDS_ENGINEER_H_

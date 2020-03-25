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
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#include <iostream>

namespace sdds {
	class Employee {
	public:
		virtual ~Employee() {};
		virtual void setSalary(double salary) = 0;
		virtual void bonus() = 0;
		virtual bool workHours() = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;
	};
}
#endif // !SDDS_EMPLOYEE_H_

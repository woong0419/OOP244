/* Citation and Sources...
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author	Woong O 124820192
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/25  writing
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "ReadWritable.h"

using namespace std;
namespace sdds {
	ReadWritable::ReadWritable() {
		flag = false;
	}
	bool ReadWritable::isCsv() const {
		return flag;
	}
	void ReadWritable::setCsv(bool value) {
		flag = value;
	}
	ostream& operator<<(ostream& os, const ReadWritable& src) {
		return src.write(os);
	}
	istream& operator>>(istream& is, ReadWritable& src) {
		return src.read(is);
	}
}
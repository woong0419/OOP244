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

#ifndef SDDS_SAIYAN_H_
#define SDDS_SAIYAN_H_


namespace sdds {
	const int MAX_NAME = 30;
	class Saiyan {
		char* m_name;
		int m_dob;
		int m_power;
		int m_level;
		bool m_super;
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power, int level = 0);
		~Saiyan();

		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void power();
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool hasLost(Saiyan& other);
	};
}

#endif
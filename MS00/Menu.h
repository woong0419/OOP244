/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.h
Version 1.0
Author	Woong O 124820192
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/14  writing
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class Menuitem {
		char* name;
		Menuitem();
		Menuitem(const char* n);
		Menuitem(const Menuitem& src) = delete;
		~Menuitem();
		std::ostream& display(std::ostream& os = std::cout) const;
		Menuitem& operator=(const Menuitem& src) = delete;
		friend class Menu;
	};

	class Menu {
		char* title=nullptr;
		Menuitem* menuitem[MAX_NO_OF_ITEMS];
		int iNum = 0; // iNum is holding index number of menuitem
		int indentation=0;

	public:
		Menu();
		Menu(const char* t, int ind = 0);
		Menu(const Menu& src);
		~Menu();
		Menu& operator=(const Menu& src);
		Menu& operator=(const char* n_title);
		operator bool() const;
		operator int() const;
		bool isEmpty() const;
		void add(const char* n);
		//void display() const;
		void indent(int ind) const;
		int run(std::istream& is = std::cin) const;
		Menu& operator<<(const char* n);

		std::ostream& display(std::ostream& os = std::cout) const;
	};

	std::ostream& operator<<(std::ostream& os, const Menu& src);
}


#endif // !SDDS_MENU_H

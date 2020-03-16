/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Menu.h"

using namespace std;

namespace sdds {
	Menuitem::Menuitem() {
		name = nullptr;
	}
	Menuitem::Menuitem(const char* n) {
		if (n != nullptr && n[0] != '\0')
		{
			name = nullptr;
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}
		else
		{
			name = nullptr;
		}
	}
	Menuitem::~Menuitem() {
		delete[] name;
		name = nullptr;
	}
	ostream& Menuitem::display(std::ostream& os) const {
		os << name << endl;
		return os;
	}
	//Menu
	Menu::Menu() {
		title = nullptr;
		*menuitem = nullptr;
		iNum = 0;
		indentation = -1;
	}
	Menu::Menu(const char* t, int ind) {
		if (t == nullptr || t[0] == '\0' || ind < 0)
		{
			*this = Menu();
		}
		else
		{
			indentation = ind;
			iNum = 0;
			*menuitem = nullptr;
			title = nullptr;
			title = new char[strlen(t) + 1];
			strcpy(title, t);

		}
	}
	Menu::Menu(const Menu& src) {
		*this = src;
	}
	Menu::~Menu() {
		delete[] title;
		title = nullptr;
		if (iNum != 0)
		{
			for (int i = 0; i < iNum; i++) {
				delete menuitem[i];
			}
		}
	}
	Menu& Menu::operator=(const Menu& src) {
		if (this != &src)
		{
			if (title != nullptr) {
				delete[] title;
				title = nullptr;
			}
			if (src.title != nullptr)
			{
				title = new char[strlen(src.title) + 1];
				strcpy(title, src.title);
			}
			indentation = src.indentation;
			if (iNum > 0)
			{
				for (int i = 0; i < iNum; i++)
				{
					delete menuitem[i];
					menuitem[i] = nullptr;
				}
			}
			if (src.menuitem[0] != nullptr)
			{
				for (int i = 0; i < src.iNum; i++)
				{
					menuitem[i] = new Menuitem(src.menuitem[i]->name);
				}
			}
			else
			{
				menuitem[0] = nullptr;
			}

			this->iNum = src.iNum;

		}

		return *this;
	}
	Menu& Menu::operator=(const char* n_title) {
		if (title != nullptr)
		{
			delete[] title;
			title = nullptr;
		}
		if (n_title == nullptr || n_title[0] == '\0')
		{
			*this = Menu();
		}
		else
		{
			title = new char[strlen(n_title) + 1];
			strcpy(title, n_title);
		}
		return *this;
	}
	Menu::operator bool() const {
		return !isEmpty();
	}
	bool Menu::isEmpty() const {
		if (title == nullptr && *menuitem == nullptr && iNum == 0 && indentation == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Menu::add(const char* n) {
		if (n != nullptr && n[0] != '\0' && iNum < MAX_NO_OF_ITEMS)
		{
			menuitem[iNum] = new Menuitem(n);
			iNum++;
		}
		else
		{
			*this = Menu();
		}

	}
	//indent function is for indentation.
	void Menu::indent(int ind) const {
		for (int i = 0; i < ind * 4; i++)
		{
			cout << " ";
		}
	}
	Menu::operator int() const {
		return run();
	}
	int Menu::run(std::istream& is) const {


		this->display();
		int select = 0;
		if (title != nullptr && menuitem[0] != nullptr && iNum > 0) {
			do
			{
				is >> select;
				if (is.fail())
				{
					cout << "Invalid Integer, try again: ";
				}
				else if (select > iNum || select <= 0)
				{
					cout << "Invalid selection, try again: ";
				}
				is.clear();
				is.ignore(2000, '\n');

			} while (is.fail() || select > iNum || select <= 0);
			
		}
		return select;
	}

	Menu& Menu::operator<<(const char* n) {
		add(n);
		return *this;
	}

	std::ostream& Menu::display(std::ostream& os) const {
		if (isEmpty() || title == nullptr)
		{
			os << "Invalid Menu!" << endl;
		}
		else
		{
			indent(indentation); os << title << endl;
			if (menuitem[0] == NULL)
			{
				os << "No Items to display!" << endl;

			}
			else {
				for (int i = 0; i < iNum; i++)
				{
					indent(indentation); os << i + 1 << "- " << this->menuitem[i]->name << endl;
				}
				indent(indentation); os << "> ";
			}
		}
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Menu& src) {
		src.display(os);
		return os;
	}
}

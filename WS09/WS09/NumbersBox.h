//==============================================
// Name:           Woong O
// Student Number: 124820192
// Email:          wo@myseneca.ca
// Section:        NGG
// Date:           1 Apr
//==============================================
// Worshop : 9
// 
//==============================================
#ifndef SDDS_NUMBERSBOX_H_
#define SDDS_NUMBERSBOX_H_
#include<iostream>
#include<cstring>

namespace sdds {
	const int MAX_LEN = 15;
	template <class T>
	class NumbersBox {
		char name[MAX_LEN + 1];
		int size;
		T* item;
	public:
		~NumbersBox() {
			delete[] item;
		}
		NumbersBox() {
			name[0] = '\0';
			size = 0;
			item = nullptr;

		}
		NumbersBox(int s, const char* n) {
			if (s < 1 || n == nullptr || n[0] == '\0' || strlen(n)>15)
			{
				*this = NumbersBox();
			}
			else
			{
				size = s;
				strcpy(name, n);
				item = new T[size];
			}
		}
		T& operator[](int i) {

			return item[i];
		}
		NumbersBox<T>& operator*=(const NumbersBox<T>& other) {
			if (size == other.size)
			{
				for (int i = 0; i < size; i++)
				{
					item[i] = item[i] * other.item[i];
				}
			}
			return *this;
		}
		NumbersBox<T>& operator+=(T num) {
			if (size != 0 && name[0] != '\0')
			{
				int i;
				T* temp = new T[size + 1];
				for (i = 0; i < size; i++)
				{
					temp[i] = item[i];
				}
				temp[i] = num;
				delete[] item;
				size = size + 1;
				item = new T[size];
				for (i = 0; i < size; i++)
				{
					item[i] = temp[i];
				}
				delete[] temp;
			}
			return *this;
		}
		std::ostream& display(std::ostream& os) const {
			if (size == 0 && name[0] == '\0')
			{
				os << "Empty Box" << std::endl;
			}
			else
			{
				os << "Box name: " << name << std::endl;
				for (int i = 0; i < size; i++)
				{
					if (i == 0) {
						os << item[i];
					}
					else
					{
						os << ", " << item[i];
					}
				}
				os << std::endl;
			}
			return os;
		}
		friend std::ostream& operator<<(std::ostream& os, NumbersBox<T>& box) {
			box.display(os);
			return os;
		}
	};

}

#endif // !SDDS_NUMBERSBOX_H_

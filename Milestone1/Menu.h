/******************************************************************************
					   Milestone 1
Full Name   :Dil Humyra Sultana Borna
Email       :dhsborna@myseneca.ca
Student ID# :139166227
Date        :7/7/2024

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <string>
#define MAX_MENU_ITEMS 20
using namespace std;
namespace seneca {

	class MenuItem {
		char* m_string;
		// Added friend Menu
		friend class Menu;
		//  Delete the copy assignment operator
		MenuItem(const MenuItem&) = delete;
		// Delete the copy assignment operator
		MenuItem& operator=(const MenuItem&) = delete;

		// Constructor
		MenuItem();
		MenuItem(const char* title);

		// Destructor
		~MenuItem();

		// operators
		operator bool()const;
		operator const char* () const;
		void display(ostream& os) const;

	};


	class Menu
	{
		// Attribute
		MenuItem* m_title;
		MenuItem* m_items[MAX_MENU_ITEMS];
		unsigned int m_numItems;

	public:
		//  Delete the copy assignment operator
		Menu(const Menu&) = delete;
		// Delete the copy assignment operator
		Menu& operator=(const Menu&) = delete;


		unsigned int operator~();
		//Destructor
		~Menu();
		// Constructor
		Menu();
		Menu(const char* title);

		// Display Function
		void displayTitle(ostream& os) const;
		void displayMenu(ostream& os);

		// operators
		unsigned int run();
		operator bool()const;
		operator int()const;
		operator unsigned int()const;
		// add item
		Menu& operator<<(const char* menuitemConent);
		const char* operator[](int index)const;

		// helper Function
		friend bool ValueInRange(int start, int end, int value);
	};
	ostream& operator<<(ostream& os, const Menu& menu);

}
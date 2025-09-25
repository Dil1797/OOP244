/******************************************************************************
                       Workshop - #3 (Part - 1)
Full Name   :Dil Humyra Sultana Borna
Email       :dhsborna@myseneca.ca
Student ID# :139166227
Date        :06.02.2024

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bill.h"
using namespace std;
namespace seneca {

    
    void Bill::setEmpty()
	{
		m_title[0] = '\0';//To set m_title to an empty C-string, you only need to set the first character to the null character '\0'
		m_items = nullptr;
        m_noOfItems = 0;
        m_itemsAdded = 0;
	}


    bool Bill::isValid() const {
        // Check if title is not empty and items pointer is not null
        if (m_title[0] == '\0' || m_items == nullptr) {
            return false;// we should use the || operator inside the if statement to return false if any of the initial checks fail
        }

        // Loop through all items in the m_items array
        for (int i = 0; i < m_noOfItems; ++i) {
            // Check if each item is valid
            if (!m_items[i].isValid()) {// dot operator (.) is used to access the isValid member function of the `Item
                return false; // If any item is invalid, return false
            }
        }

        // If all checks pass, return true
        return true;
    }

    


    double Bill::totalTax() const
    {
        double total = 0.0;// initializes a variable
        for (int i = 0; i < m_noOfItems; ++i) {
            total += m_items[i].tax(); // Add the tax of each item to the total
        }
        return total;
    }


    double Bill::totalPrice() const {
        double total = 0.0;
        for (int i = 0; i < m_noOfItems; ++i) {
            total += m_items[i].price(); // Add the price of each item to the total
        }
        return total;
    }




    void Bill::Title()const {
        cout << "+--------------------------------------+";
        if (isValid()) {
            cout << endl << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << m_title;
            cout << " |";
        }
        else {
            cout << endl << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << "Invalid Bill";
            cout << " |";
        }
        cout << endl << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;

    }

    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax();
            cout << " |" << endl;

            cout << "|              Total Price: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalPrice();
            cout << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax() + totalPrice();
            cout << " |" << endl;
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
        }
        else {
            cout << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << "Invalid Bill";
            cout << " |" << endl;
        }
        cout << "+--------------------------------------+" << endl;

    }

    void Bill::init(const char* title, int noOfItems) {
        if (title == nullptr || title[0] == '\0' || noOfItems <= 0) {
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strncpy(m_title, title, 36);
            m_title[36] = '\0';
            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; ++i) {
                m_items[i].setEmpty();
            }
        }
    }


    
    bool Bill::add(const char* item_name, double price, bool taxed) {
        // Check if there is space to add a new item
        if (m_itemsAdded < m_noOfItems) {
            // Set the next available item
            m_items[m_itemsAdded].set(item_name, price, taxed);
            // Increment the count of added items
            m_itemsAdded++;
            return true;
        }
        
        return false;
    }

    void Bill::display()const {

        Title();

        // Loop through and print each item
        for (int i = 0; i < m_noOfItems; ++i) {
            m_items[i].display();
        }

        // Print the footer
        footer();

    }

    void Bill::deallocate() {

        delete [ ] m_items;

        m_items = nullptr;

    }
    


}
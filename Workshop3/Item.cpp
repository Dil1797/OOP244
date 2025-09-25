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
#include "Item.h"
using namespace std;
namespace seneca {

    void Item::setName(const char* name) {
        if (name != nullptr && name[0] != '\0') {
            strncpy(m_itemName, name, 20);
            m_itemName[20] = '\0';
        }
        else {
            setEmpty();
        }
    }

    void Item::setEmpty() {//Purpose :set the Item object to a safe, recognizable empty state. useful for initialization or resetting an item when it is invalid or has no meaningful data

        m_price = 0.0; //setting the price to an impossible value like **0.0**
        m_itemName[0] = '\0'; //setting the **m_itemName** to a blank string (first character set to null). 
        m_taxed = false;

    }

    void Item::set(const char* name, double price, bool taxed) {
        if (name == nullptr || name[0] == '\0' || price < 0) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    double Item::price() const {
        return m_price;
    }

    double Item::tax() const
    {
       
        if (m_taxed) {
            return m_price * TAX_RATE;
        }
        else {
            return 0.0;
        }
      
    }

    bool Item::isValid() const {
        return m_price > 0.0 && m_itemName[0] != '\0';
    }

    void Item::display()const {
        if (isValid())
        {
            cout << flush;
            cout << "| ";
            cout.fill('.');
            cout.width(20);
            cout.setf(ios::left);
            cout.setf(ios::fixed);
            cout << m_itemName; //"milk" is printed here
            cout << " | ";

            cout.fill(' ');
            cout.width(7);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_price;
            cout.unsetf(ios::right);
            cout.setf(ios::fixed);

            cout << " | ";
            cout.fill(' ');
            cout.width(4);
            cout.setf(ios::left);
            cout.setf(ios::fixed);
            if (m_taxed)
                cout << "Yes";
            else
                cout << "No";
            cout << "|";
            cout << endl;
        }
        //| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx | //Newline
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |";
            cout << endl;
        }
    }
}
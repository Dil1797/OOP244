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
#include <iostream>
#include <cstring>
#include <limits> // Include this header for numeric_limits
#include "Menu.h"

using namespace std;

namespace seneca {

    // =============== MenuItem Function ====================================================
    // Constructors
    MenuItem::MenuItem() {
        m_string = nullptr;
    }

    MenuItem::MenuItem(const char* title) {
        if (title != nullptr) {
            m_string = new char[strlen(title) + 1];
            strcpy(m_string, title);
        }
        else {
            m_string = nullptr;
        }
    }

    // Destructor
    MenuItem::~MenuItem() {
        delete[] m_string;
    }

    // Returns false for empty state, else true
    MenuItem::operator bool() const {
        return m_string != nullptr;
    }

    MenuItem::operator const char* () const {
        return m_string;
    }

    void MenuItem::display(std::ostream& os) const {
        if (m_string != nullptr) {
            os << m_string;
        }
    }

    // =============== Menu Function ====================================================
    // Constructor
    Menu::Menu() {
        m_title = nullptr;
        m_numItems = 0;
        for (int i = 0; i < MAX_MENU_ITEMS; i++) {
            m_items[i] = nullptr;
        }
    }

    Menu::Menu(const char* title) : m_numItems(0) {
        m_title = new MenuItem(title);
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
            m_items[i] = nullptr;
        }
    }

    // Destructor
    Menu::~Menu() {
        delete m_title;
        for (unsigned int i = 0; i < m_numItems; i++) {
            delete m_items[i];
        }
    }

    // Functions
    void Menu::displayMenu(ostream& os) {
        displayTitle(os);
        if (m_title != nullptr) {
            os << ":" << endl;
        }
        for (unsigned int i = 0; i < m_numItems; i++) {
            os << " " << i + 1 << "- ";
            m_items[i]->display(os);
            os << endl;
        }
        cout << " 0- Exit" << endl;
        cout << "> ";
    }

    unsigned int Menu::operator~() {
        return run();
    }

    unsigned int Menu::run() {
        unsigned int selection = 0;
        bool selectValid = false;

        do {
            displayMenu(std::cout);

            do {
                cin >> selection;
                if (cin.fail() || selection < 0 || selection > m_numItems) {
                    cout << "Invalid Selection, try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    selectValid = true;
                }
            } while (!selectValid);
        } while (!selectValid);

        return selection;
    }

    void Menu::displayTitle(ostream& os) const {
        if (m_title != nullptr) {
            const char* titleContent = *m_title;
            os << titleContent;
        }
    }

    Menu& Menu::operator<<(const char* menuitemContent) {
        if (m_numItems < MAX_MENU_ITEMS) {
            m_items[m_numItems] = new MenuItem(menuitemContent);
            m_numItems++;
        }
        return *this;
    }

    Menu::operator int() const {
        return m_numItems;
    }

    Menu::operator unsigned int() const {
        return m_numItems;
    }

    Menu::operator bool() const {
        return m_numItems > 0;
    }

    ostream& operator<<(ostream& os, const Menu& menu) {
        menu.displayTitle(os);
        return os;
    }

    const char* Menu::operator[](int index) const {
        const char* menuItemContent = nullptr;
        if (m_numItems > 0) {
            int adIndex = index % m_numItems;
            menuItemContent = (const char*)(*m_items[adIndex]);
        }
        return menuItemContent;
    }

}
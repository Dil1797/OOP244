//
// Date: 2024-07-04.
// Name: Dil Humyra Sultana Borna
// Email: dhsborna@myseneca.ca
// Student ID: 139166227

#pragma once
#include <iostream>
#include <cstring>

namespace seneca {
    const unsigned int MAX_MENU_ITEMS = 20;

    class MenuItem {
        char* name{ nullptr };

        MenuItem();
        MenuItem(const char* str);
        ~MenuItem();

        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;

        operator bool() const;
        operator const char* () const;

        void display() const;

        friend class Menu;
    };

    class Menu {
        char* title;
        MenuItem* menuItems[MAX_MENU_ITEMS] = { nullptr, };
        unsigned int noOfItems;

        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

    public:
        Menu();
        Menu(const char* str);
        ~Menu();

        void display() const;
        unsigned int run();

        unsigned int operator~();
        Menu& operator<<(const char* menuItemContent);
        friend std::ostream& operator<<(std::ostream& os, const Menu& menu);

        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        const char* operator[](unsigned index) const;
    };
}
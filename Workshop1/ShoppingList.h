/******************************************************************************
                       Workshop - #2 (Part - 1)
Full Name   :Dil Humyra Sultana Borna
Email       :dhsborna@myseneca.ca
Student ID# :139166227
Date        :19.05.2024

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
******************************************************************************/

#pragma once
#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include "ShoppingRec.h"
#include "File.h"

namespace seneca {
    // All your C++ code for ShoppingList.h goes here

    const int MAX_NO_OF_RECS = 15;


    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();

}

#endif // SHOPPINGLIST_H



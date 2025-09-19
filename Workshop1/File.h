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
#ifndef FILE_H
#define FILE_H

#include "ShoppingRec.h"

namespace seneca {


    const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
    //sfptr. This is the name of the variable. It stands for "file pointer"


    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif // FILE_H

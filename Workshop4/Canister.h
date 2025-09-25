/******************************************************************************
                       Workshop - #4 (Part - 1)
Full Name   :Dil Humyra Sultana Borna
Email       :dhsborna@myseneca.ca
Student ID# :139166227
Date        :08.06.2024

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
******************************************************************************/

#pragma once
#ifndef SENECA_CANISTER_H
#define SENECA_CANISTER_H
#include <iostream>
namespace seneca {
    class Canister {
        char* m_contentName;
        double m_diameter; // in centimeters 
        double m_height;   // in centimeters
        double m_contentVolume;  // in CCs
        bool m_usable;
        void setToDefault();
        void setName(const char* Cstr);
        bool isEmpty()const;
        bool hasSameContent(const Canister& C)const;
    public:
        Canister();
        Canister(const char* contentName);
        Canister(double height, double diameter,
            const char* contentName = nullptr);
        ~Canister();
        Canister& setContent(const char* contentName);
        Canister& pour(double quantity);
        Canister& pour(Canister&);
        double volume()const;
        std::ostream& display()const;
        double capacity()const;
        void clear();
        void deallocate();
    };
}

#endif // !SENECA_BOX_H

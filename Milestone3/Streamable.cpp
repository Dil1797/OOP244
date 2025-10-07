//
// Created on 2024-07-03.
// Name: Dil Humyra Sultana Borna
// Email: dhsborna@myseneca.ca
// Student ID: 139166227

#define _CRT_SECURE_NO_WARNINGS
#include "Streamable.h"
#include <iostream>

namespace seneca {

    std::ostream& operator<<(std::ostream& os, const Streamable& s) {
        if (s) {
            s.write(os);
        }

        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& s) {
        s.read(is);
        return is;
    }
} // namespace seneca
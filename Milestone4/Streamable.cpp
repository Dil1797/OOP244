//
// Created on 2024-07-03.
// Name: Dil Humyra Sultana Borna
// Email: dhsborna@myseneca.ca
// Student ID: 139166227
#define _CRT_SECURE_NO_WARNINGS

#include "Streamable.h"

using namespace std;

namespace seneca {
    std::ostream &operator<<(std::ostream &os, const Streamable& streamable) {
        if (!streamable)
            return os;
        return streamable.write(os);
    }
    std::istream &operator>>(std::istream &is, Streamable& streamable) {
        return streamable.read(is);
    }
}

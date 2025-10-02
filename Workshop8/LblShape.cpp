//
// Created on 2024-07-19.
// Name: Dil Humyra Sultana Borna
// Email: dhsborna@myseneca.ca
// Student ID: 139166227

//

#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"

using namespace std;

namespace seneca {
    const char* LblShape::label() const {
        return m_label;
    }

    LblShape::LblShape() {
        m_label = nullptr;
    }

    LblShape::LblShape(const char* label) {
        if (label != nullptr && label[0] != '\0') {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }

    LblShape::~LblShape() {
        if (m_label != nullptr) {
            delete[] m_label;
            m_label = nullptr;
        }
    }

    void LblShape::getSpecs(istream& is) {
        char label[256] = { '\0', };
        is.getline(label, 256, ',');
        if (m_label != nullptr) {
            delete[] m_label;
            m_label = nullptr;
        }
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }
}

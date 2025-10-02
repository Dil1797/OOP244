//
// Created on 2024-07-19.
// Name: Dil Humyra Sultana Borna
// Email: dhsborna@myseneca.ca
// Student ID: 139166227

//

#define _CRT_SECURE_NO_WARNINGS
#include "Line.h"

using namespace std;

namespace seneca {
    Line::Line() : LblShape() {
        m_length = 0;
    }

    Line::Line(const char* label, int length) : LblShape(label) {
        m_length = length;
    }

    void Line::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }

    void Line::draw(ostream& os) const {
        if (m_length > 0 && LblShape::label() != nullptr) {
            os << LblShape::label() << endl;
            int i = 0;
            for (i = 0; i < m_length; i++) {
                os << '=';
            }
        }
    }
}














/*#define _CRT_SECURE_NO_WARNINGS
#include "Line.h"

using namespace std;

namespace seneca {
    Line::Line() : LblShape() {
        m_length = 0;
    }

    Line::Line(const char* label, int length) : LblShape(label) {
        m_length = length;
    }

    void Line::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }

    void Line::draw(ostream& os) const {
        if (m_length > 0 && LblShape::label() != nullptr) {
            os << LblShape::label() << endl;
            for (int i = 0; i < m_length; i++) {
                os << '=';
            }
            os << endl;
        }
    }
}*/
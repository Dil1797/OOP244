#pragma once
//
// Created on 2024-07-19.
// Name: Dil Humyra Sultana Borna
// Email: dhsborna@myseneca.ca
// Student ID: 139166227

//

#ifndef WS08_SHAPE_H
#define WS08_SHAPE_H

#include <iostream>

namespace seneca {
    class Shape {
    public:
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& is) = 0;
        virtual ~Shape() = default;
    };

    std::ostream& operator<<(std::ostream& os, Shape& shape);
    std::istream& operator>>(std::istream& is, Shape& shape);
}


#endif //WS08_SHAPE_H

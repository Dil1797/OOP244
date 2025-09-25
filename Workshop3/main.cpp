/******************************************************************************
                       Workshop - #3 (Part - 1)
Full Name   :Dil Humyra Sultana Borna
Email       :dhsborna@myseneca.ca
Student ID# :139166227
Date        :06.02.2024

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
******************************************************************************/

// Workshop 3: 
// Version: 1.0
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
// Do not modify this code when submitting
/////////////////////////////////////////////
#include "Bill.h"
using namespace seneca;
int main() {
   Bill B;
   B.init("Quick Shopping", 5);
   B.add("Milk 2%", 4.99, false);
   B.display();
   B.add(nullptr, 15.50, true);
   B.add("Frying Pan", 24.99, true);
   B.add("Eggs", -2.99, false);
   B.display();
   B.deallocate();
   B.init("Quick Shopping", 5);
   B.add("Milk 2%", 4.99, false);
   B.add("Spatula", 15.50, true);
   B.add("Frying Pan", 24.99, true);
   B.add("Eggs", 5.99, false);
   B.add("Bug Spray", 9.99, true);
   B.display();
   B.deallocate();
   return 0;
}

/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Dil Humyra Sulyana Borna  Date 2/8/2024   Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Car.h"
using namespace std;
namespace seneca {
   Car::Car(const char* plate , const char* makeModel ) {
      set(plate, makeModel);
   }
   // Constructor that initializes a Car object with specified values by calling the set method.


   void Car::set(const char* plate, const char* makeModel) {
      strncpy(m_plate, plate, 8);
      m_plate[8] = 0;
      // Copy up to 8 characters of the license plate into m_plate and ensure null termination.

      strncpy(m_makeModel, makeModel, 40);
      m_makeModel[40] = 0;;
      // Copy up to 40 characters of the make and model into m_makeModel and ensure null termination.
   }


   std::ostream& Car::display(std::ostream& os)const {
      return os << m_plate << " " << m_makeModel;
   }
   // Override of the display method to output car details to the given output stream.
  // Returns the output stream to allow chaining.


   std::istream& Car::read(std::istream& is) {
      is >> m_plate;
      is.getline(m_makeModel, 40, '\n');
      // Read the car's make and model from the input stream until a newline character is encountered.
      return is;
   }



   bool Car::operator==(const char* mmSubstr)const {
      return strstr(m_makeModel, mmSubstr) != nullptr;
   }
   // Overloads the equality operator to check if the car's make/model contains the specified substring.
}

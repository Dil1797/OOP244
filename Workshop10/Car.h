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
#include <iostream>
#ifndef SENECA_CAR_H_
#define SENECA_CAR_H_
#include "ReadWrite.h"
namespace seneca {
   class Car : public ReadWrite {
      char m_plate[9];
      char m_makeModel[41];
   public:
      Car(const char* plate = "", const char* makeModel = "");
      void set(const char* plate, const char* makeModel);

      std::ostream& display(std::ostream& os)const;
      // Override of the display function to output the car's data to the given output stream. Returns the same stream for chaining.

      std::istream& read(std::istream& is);
      // Override of the read function to input the car's data from the given input stream. Returns the same stream for chaining.

      bool operator==(const char* mmSubstr)const;
      // Overloads the equality operator to check if the car's make/model contains the specified substring.
   };


}
#endif // !SENECA_CAR_H_

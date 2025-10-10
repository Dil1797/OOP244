/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Dil Humyra Sulyana Borna  Date 2/8/2024    Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#ifndef SENECA_READWRITE_H_
#define SENECA_READWRITE_H_
namespace seneca {
   class ReadWrite {  // Declares an abstract base class ReadWrite, used to define a common interface for I/O operations.
   public:
      virtual std::ostream& display(std::ostream& os)const = 0;
      // Pure virtual function for displaying object data. Must be implemented by derived classes.
      // Takes an output stream and returns the same stream to allow chaining.

      virtual std::istream& read(std::istream& is) = 0;
      // Pure virtual function for reading object data. Must be implemented by derived classes.
      // Takes an input stream and returns the same stream to allow chaining.


      virtual ~ReadWrite() { // Virtual destructor
      }
   };


   std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
   // Overloads the << operator to output an object using its display method.
   // Takes an output stream and a ReadWrite reference, returns the same stream for chaining.

   std::istream& operator>>(std::istream& is, ReadWrite& c);
   // Overloads the >> operator to input an object using its read method.

}
#endif // !SENECA_READWRITE_H_


/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
/// Name Dil Humyra Sulyana Borna  Date 2/8/2024
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#ifndef SENECA_EMPLOYEE_H_
#define SENECA_EMPLOYEE_H_
#include "ReadWrite.h"
namespace seneca {
   class Employee : public ReadWrite {
      int m_empno;   // Integer to store the employee number.
      int m_office; // Integer to store the office number of the employee.
      char m_name[41];// Character array to store the employee's name, with a maximum of 40 characters plus the null terminator.
      double m_salary;// Double to store the employee's salary.
   public:
      Employee();// Default constructor to initialize an Employee object with default values.

      Employee(int stno, const char* name, double salary, int office);
      // Constructor to initialize an Employee object with specified employee number, name, salary, and office.

      void set(int stno, const char* name, double salary, int office);
      // Member function to set the employee's information.


      std::ostream& display(std::ostream& os)const;
      // Override of the display function to output the employee's data to the given output stream. Returns the same stream for chaining.

      std::istream& read(std::istream& is);
      // Override of the read function to input the employee's data from the given input stream. Returns the same stream for chaining.

      bool operator==(int office)const;
      // Overloads the equality operator to compare the employee's office number with a specified office number.

   };


}
#endif // !SENECA_EMPLOYEE_H_
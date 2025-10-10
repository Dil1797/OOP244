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
#include <iomanip>
#include <cstring>
using namespace std;
#include "Employee.h"
namespace seneca {
   Employee::Employee() {// Default constructor that initializes an Employee object with default values using the set method.
      set(0, "", 0.0, 0);
   }

   Employee::Employee(int stno, const char* name, double salary, int office) {
      set(stno, name, salary, office);
   }
   // Parameterized constructor that initializes an Employee object with specified values using the set method.



   void Employee::set(int stno, const char* name, double salary, int office) {
      m_empno = stno; // Set the employee number to the provided value.
      strcpy(m_name, name);   // Copy the provided name into the m_name member variable.
      m_salary = salary;
      m_office = office;
   }
   


   ostream& Employee::display(ostream& os)const {
      return os << m_empno << " " << m_name << " (Office# " << m_office << ") Salary: $" << setprecision(2) << fixed << m_salary;
   }
   // Override of the display method to output employee details to the given output stream.



   istream& Employee::read(istream& is) {
      is >> m_empno;
      is.getline(m_name, 40, ',');
      is >> m_salary;
      return is;
   }



   bool Employee::operator==(int office)const {
      return m_office == office;
   }
   // Overloads the equality operator to check if the employee's office number matches the specified office number.
   // Returns true if they match, false otherwise.
}

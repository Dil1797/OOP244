/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Dil Humyra Sulyana Borna  Date 2/8/2024  Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

using namespace std;
#include "Student.h"
namespace seneca {
   Student::Student() {
      set(0, "", 0.0);
   }
   Student::Student(int stno, const char* name, double gpa) {
      set(stno, name, gpa); //grade point average (GPA)
   }
   void Student::set(int stno, const char* name, double gpa) {
      m_stno = stno;
      strcpy(m_name, name);
      m_gpa = gpa;
   }
   ostream& Student::display(ostream& os)const {
      return os << m_stno << " " << m_name << " GPA: " << fixed << setprecision(1) << m_gpa;
   }
   // Override of the display method to output student details to the given output stream.



   istream& Student::read(istream& is) {
      is >> m_stno;
      // Input the student number from the input stream.
      is.getline(m_name, 40, '\n');
      // Read the student's name from the input stream until a newline character is encountered.
      return is;
      // Return the input stream to allow chaining.
   }




   bool Student::operator==(double gpa)const {
      return m_gpa > (gpa - 0.001) && m_gpa < (gpa + 0.001);
   }
   // Overloads the equality operator to check if the student's GPA is approximately equal to the specified GPA.
  // Returns true if they are approximately equal, false otherwise.

}
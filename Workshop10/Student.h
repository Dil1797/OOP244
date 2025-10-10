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
#ifndef SENECA_STUDENT_H_
#define SENECA_STUDENT_H_
#include "ReadWrite.h"
namespace seneca {
   class Student : public ReadWrite {
      int m_stno;
      char m_name[41];
      double m_gpa;// Double to store the student's grade point average (GPA).
   public:
      Student();
      Student(int stno, const char* name, double gpa);
      void set(int stno, const char* name, double gpa);
      std::ostream& display(std::ostream& os)const;
      // Override of the display function to output the student's data to the given output stream.

      std::istream& read(std::istream& is);
      // Override of the read function to input the student's data from the given input stream.

      bool operator==(double gpa)const;
      // Overloads the equality operator to compare the student's GPA with a specified GPA value.
   };
}
#endif // !SENECA_STUDENT_H_


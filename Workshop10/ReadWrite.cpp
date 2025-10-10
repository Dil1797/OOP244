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
#include "ReadWrite.h"
using namespace std;
namespace seneca {
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }

   istream& operator >> (istream& is, ReadWrite& c) {
      return c.read(is);
   }
}
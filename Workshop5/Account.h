/******************************************************************************
                       Workshop - #5 (Part - 1)
Full Name   :Dil Humyra Sultana Borna
Email       :dhsborna@myseneca.ca
Student ID# :139166227
Date        :16.06.2024

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
******************************************************************************/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number; //acount number 
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const; //conversion operators. **bool operator**
      operator int() const; //conversion operator. **int operation**
      operator double() const; //conversion operator. **double operation**
      bool operator ~() const; //Unary member operator
      Account& operator = (int number); //Binary member operators.  assignment operators
      Account& operator = (Account& _move);// Binary member operators.overload the **assignment operator** so a **NEW account** can be                                           set to another **Account** object.
      Account& operator += (double value); // Binary member operatore. the value of the double should be added to the balance.
      Account& operator -= (double value); // Binary member operatore.the value of the balance should be reduced by the double value
      Account& operator<<(Account& _move); // Binary member operatore. (left shift operator) to move funds from the right account to                                                      the left.
      Account& operator>>(Account& _move); //Binary member operatore.(right shift operator) to move funds from the left account to the                                                           right.
     friend double operator +(const Account& left, const Account& right); //Binary helper operators

     friend double operator +=(double& value, const Account& add); //Binary helper operators
   };
   
   double operator +(const Account& left, const Account& right);
   double operator +=(double& value, const Account& add);
}
#endif // SENECA_ACCOUNT_H_
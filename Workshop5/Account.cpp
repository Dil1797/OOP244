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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const
    {
        if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0) {
            return true;
        }
        else {
            return false;
        }
    }

    Account::operator int() const
    {
        return m_number;
    }

    Account::operator double() const
    {
        return m_balance;
    }

    bool Account::operator~() const
    {
        if (m_number == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    Account& Account::operator=(const int number)
    {
        if (m_number == 0) //check if Account is New

            //if (number >= 10000 && number <= 99999) // Validate the integer value

            // "this" account can be set to the number
            m_number = number;

        // If number is an invalid account number, "this" object set to an invalid empty state
        else if (number < 10000 || number > 99999)
            setEmpty();

        return *this;


    }

    Account& Account::operator=(Account& _move) {
        // Define the assignment operator that takes an Account object as an argument.
        // It returns a reference to the current object (this).

        if (this->m_number == 0 && _move.m_number > 0) {
            // Check if the current account is new (m_number == 0) and
            // the account being moved from (_move) is valid (m_number > 0).

            this->m_number = _move.m_number;
            // Set the account number of the current account to the account number of the _move account.

            this->m_balance = _move.m_balance;
            // Set the balance of the current account to the balance of the _move account.

            _move.m_number = 0;
            // Reset the account number of the _move account to 0, making it a new account.

            _move.m_balance = 0;
            // Reset the balance of the _move account to 0, effectively transferring the balance.
        }

        return *this;
        // Return a reference to the current object to allow for chained assignments.
    }

    Account& Account::operator+=(double value)
    {
        if (m_number > 0 &&  m_balance > 0.0 && value > 0.0) {

            m_balance += value;
        }

        return *this;
    }

    Account& Account::operator -= (double value) {

        if (m_number > 0 && m_balance > value && value >= 0.0) { //check if account is valid or new , and m-balance has enough mony and                                                                  value is valid

            m_balance -= value;

        }
        return *this;

    }

    Account& Account::operator<<(Account& _move)
    {

        if (this->m_number > 0 && _move.m_number > 0 && this->m_number != _move.m_number) { // this != &_move ensures that the left-hand side account (this) and the right-hand side account (_move) are not the same object

            this->m_balance += _move.m_balance;

            _move.m_balance = 0; //indicates that all funds have been moved.
        }

        return *this;
        
    }

    Account& Account::operator>>(Account& _move)
    {
        if (this->m_number > 0 && _move.m_number > 0 && this->m_number != _move.m_number) {

            _move.m_balance += this->m_balance;

            this->m_balance = 0; //indicates that all funds have been moved.
      }

        return *this;
    }





    double operator+(const Account& left, const Account& right)
    {
        double sum = 0.0;

        if (left.m_number > 0 && right.m_number > 0) {  //check if 2 account are valid

            sum = left.m_balance + right.m_balance;

            
        }
        return sum;
    }

    double operator+=(double& _value, const Account& _add)
    {
        if (_add.m_number > 0)
        {
            _value += _add.m_balance;

            
        }

        return _value;


       
    }




}







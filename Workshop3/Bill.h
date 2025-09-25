/******************************************************************************
                       Workshop - #3 (Part - 1)
Full Name   :Dil Humyra Sultana Borna
Email       :dhsborna@myseneca.ca
Student ID# :139166227
Date        :06.02.2024

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
******************************************************************************/

#ifndef SENECA_BILL_H_
#define SENECA_BILL_H_
#include "Item.h"
namespace seneca {
   class Bill {
      char m_title[37];
      Item* m_items; //pointer to the dynamically allocated array of Items
      int m_noOfItems; // size of the dynamically allocated array of Items
      int m_itemsAdded;
      double totalTax()const;
      double totalPrice()const;
      void Title()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;
   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };



}
#endif // !SENECA_TRANSCRIPT_H

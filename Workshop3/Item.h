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

#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_
namespace seneca {

    const double TAX_RATE = 0.13; // Define the tax rate constant

   class Item {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SENECA_SUBJECT_H

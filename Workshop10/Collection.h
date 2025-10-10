/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// Collection template
//
// Revision History
// -----------------------------------------------------------
/// Name Dil Humyra Sulyana Borna  Date 2/8/2024   Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_COLLECTION_H_
#define SENECA_COLLECTION_H_
namespace seneca {
   template <typename T> 
   class Collection {
      T* m_data = nullptr; //Pointer to a dynamic array of elements of type T
      int m_size = 0;
   public:
      Collection(int size = 0);   // Constructor to initialize a Collection with a specified size.
      Collection(const Collection<T>& CP);// Copy constructor to initialize a new Collection object as a copy of another Collection object CP.
      Collection<T>& operator=(const Collection<T>& RO);// Assignment operator to allow assigning one Collection object to another, copying all elements.
      int size()const; // Member function to return the current size
      void resize(int newsize);// Resizes the collection
      T& operator[](int index); // Overloads the subscript operator [] to provide access to elements by index. Automatically resizes the collection if the index is out of bounds.
      Collection<T>& add(const T& element); // Adds a new element to the collection, resizing if necessary. Returns a reference to the Collection object to allow method chaining.
      ~Collection(); // Destructor to clean up the dynamic memory allocated for the collection.
   };

   template <typename T>
   Collection<T>::Collection(int size) :m_size(size) {
      if (m_size <= 0) m_size = 0;
      // Ensures size is non-negative. If size is less than or equal to zero, set it to zero.
      if (m_size > 0) m_data = new T[m_size];
      // Allocate memory for m_size elements of type T if m_size is greater than zero.
   }
   template <typename T>
   Collection<T>::Collection(const Collection<T>& CP) {
      operator=(CP);// Copy constructor that utilizes the assignment operator to copy elements from the Collection CP.
   }
   template <typename T>
   Collection<T>& Collection<T>::operator=(const Collection<T>& RO) {
      if (this != &RO) {  // Check for self-assignment to prevent issues.
         delete[] m_data; // Delete existing memory to prevent memory leaks.
         m_data = new T[m_size = RO.m_size];// Allocate new memory and copy the size from RO.
         for (int i = 0; i < m_size; i++) m_data[i] = RO.m_data[i];// Copy each element from RO to the new memory.
      }
      return *this;  // Return the current object to allow method chaining.
   }

   template <typename T>
   int Collection<T>::size()const {
      return m_size;
      // Return the current size of the collection.
   }

   template <typename T>
   void Collection<T>::resize(int newsize) {
      int i;
      T* temp = nullptr;// Temporary pointer for new memory allocation.
      if (newsize < 0) newsize = 0;// Ensure the new size is non-negative. If negative, set to zero.
      if (newsize > 0) {// Allocate memory for the new size if greater than zero.
         temp = new T[newsize];
         for (i = 0; i < m_size && i < newsize; i++) {
            temp[i] = m_data[i]; // Copy elements from the old memory to the new memory.
         }
      }
      delete[] m_data; // Delete the old memory.
      m_data = temp;// Assign the new memory to m_data.
      m_size = newsize; // Update the size of the collection.
   }

   template <typename T>
   T& Collection<T>::operator[](int index) {
      if (index >= m_size) resize(index + 1);// If the index is out of bounds, resize the collection to accommodate the index
      return m_data[index];  // Return a reference to the element at the given index.
   }

   template <typename T>
   Collection<T>& Collection<T>::add(const T& element) {
      (*this)[size()] = element;// Add the element to the collection using the overloaded subscript operator.
      return *this; // Return the current object to allow method chaining.
   }
   template <typename T>
   Collection<T>::~Collection() {
      delete[] m_data;// Destructor to clean up the dynamic memory allocated for the collection.
   }
}

#endif // !SENECA_COLLECTION_H_




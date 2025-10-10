/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// Collection template
//
// Revision History
// -----------------------------------------------------------
// Name Dil Humyra Sulyana Borna  Date 2/8/2024   Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_SEARCHNLIST_H_
#define SENECA_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

namespace seneca {



	template <typename T>

	void listArrayElements(const char* _title, const T* _arr, int _num) {

		cout << _title << endl;

		for (int i = 0; i < _num; i++) {
			cout << (i + 1) << ": ";
			// Call "<<" operator from the ReadWrite class that is abstract base class
		   // and then compiler determines the actual object and Call the corresponding display()


			cout << _arr[i] << endl;
		}

	}




	 // Receive the same typename in Collection and array
     // because to add the searched array to Collection
     // and use another typename to receive different key value
	template <typename T1, typename T2>
	
	bool search(Collection<T1>& _obj, const T1* _arr, int _num, T2 _key) {
		bool result = false;

		for (int i = 0; i < _num; i++) {
			if (_arr[i] == _key) { // Call "==" operator corresponding to each type
				_obj.add(_arr[i]);   // Call the template function "add" in Collection template class
				result = true;
			}
		}
		return result;
	}


	



}

#endif // !SENECA_SEARCHNLIST_H_
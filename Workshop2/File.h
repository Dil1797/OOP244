/******************************************************************************
                       Workshop - #2 (Part - 1)
Full Name   :Dil Humyra Sultana Borna
Email       :dhsborna@myseneca.ca
Student ID# :139166227
Date        :25.05.2024

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
******************************************************************************/

#pragma once
#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_

namespace seneca {

	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare overloaded read function prototypes
	bool read(char* empName);
	bool read(int& empNumber);
	bool read(double& empSalary);
}
#endif
// !SENECA_FILE_H_ 

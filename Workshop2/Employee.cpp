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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;

namespace seneca {

    int noOfEmployees;
    Employee* employees;


    void sort() {//The sort function,  is responsible for sorting the array of employee records based on their employee numbers (m_empNo).
        int i, j;// These are loop control variables
        Employee temp;// Temporary Storage.  This is a temporary variable of type Employee used for swapping employee records during the sorting process.
        for (i = noOfEmployees - 1; i > 0; i--) 
        {
            for (j = 0; j < i; j++) 
            {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) 
                {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& emp) {
        bool ok = false;
        char name[128];


        /* if reading of employee number, salay and name are successful
                allocate memory to the size of the name + 1
                and keep its address in the name of the Employee Reference

                copy the name into the newly allocated memroy

                make sure the "ok" flag is set to true
           end if
        */
        if (read(emp.m_empNo) && read(emp.m_salary) && read(name))
        {
            emp.m_name = new char[strlen(name) + 1];//new is keyword used to allocate. allocate the same amount of characters in the name of the `Employee` parameter. pointer =  emp.m_name.  new or kewword = new.  Type = char.  size = [strlen(name) + 1]

            strcpy(emp.m_name, name);//char* strcpy(char* dest, char* stc) . Copy the content of stc on the dest. make sure dest is empty and after copy, dest only shows stc content.

            ok = true;
        }
        return ok;
    }


    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {//(DATAFILE) is equivalent to (employees.csv). If the file is successfully opened openFile returns true and the subsequent code to read and process the employee records is executed. If the file cannot be opened, openFile returns false and an error message is printed.

            /*
             Set the noOfEmployees to the number of recoreds in the file.
             dyanamically allocated an array of employees into the global
             Employee pointer; "employees" to the size of the noOfEmployees.

             In a loop load the employee records from the file into
             the dynamic array.

             If the number of the records does not match the number of reads
                print the message
               "Error: incorrect number of records read; the data is possibly corrupted"
             Otherwise
                set the ok flag to true
             End if

             close the file
             */

            noOfEmployees = noOfRecords();

            employees = new Employee[noOfEmployees];//employees is global variable.
            //Employee* employees;
      //pointer = new Type [size];

            for (int j = 0; j < noOfEmployees; j++)
            {
                i += load(employees[j]);
            }

            if (i != noOfEmployees)//if statement checks whether the number of successfully loaded records (i) matches the number of employees (noOfEmployees).If they don't match (i != noOfEmployees), it means there was an error in reading some records from the file
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true; //If they do match, it sets the ok flag to true, indicating that all            records were successfully loaded.
            }

            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;//This 'else' block corresponds to the if (openFile(DATAFILE)) statement at the beginning.
            //If the file could not be opened(openFile returned false), it prints an error
            //message indicating that the data file could not be opened.
        }
        return ok;
    }
    // TODO: Implementation for the display functions go here

    void display(const Employee& emp)
    {
        cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
    }

    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory()
    {
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }

        delete[] employees;
    }

}

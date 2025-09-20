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
#include <cstdio>
#include "File.h"

namespace seneca {
    FILE* fptr; //This pointer will be used to manage the data file operations.
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r"); //This line attempts to open the file specified by filename in read mode ("r"). The fopen function returns a file pointer, which is assigned to the global fptr variable.
        return fptr != NULL; //If fptr is not NULL, the file was opened successfully, and the function returns true; otherwise, it returns false
    }
    int noOfRecords() {//this function returns an integer representing the number of records in the file.
        int noOfRecs = 0; //declare and initializes a local variable
        char ch; //local variable. number of characters
        while (fscanf(fptr, "%c", &ch) == 1) {//loop continues as long as fscanf successfully reads a character (returns 1).
            noOfRecs += (ch == '\n');//counts the number of records in the file, assuming each record is on a new line.
        }
        rewind(fptr);//resets the file pointer to the beginning of the file
        return noOfRecs;// Returns the total number of records (lines) in the file.
    }
    void closeFile() {
        if (fptr) fclose(fptr);//This line checks if fptr is not NULL. If it isn't, it closes the file using the fclose function and sets fptr to NULL.
    }
    bool read(char* empName)
    {
        return fscanf(fptr, "%127[^\n]\n", empName) == 1;//This line reads a string from the file up to a newline character (\n) and stores it in empName. If fscanf successfully reads one string, it returns 1, and the function returns true; otherwise, it returns false.
    }

    bool read(int& empNumber) //indicating that it takes a reference to an integer. This function reads an integer followed by a comma from the file and stores it in the empNumber parameter
    {
        return fscanf(fptr, "%d,", &empNumber) == 1;//The fscanf function reads formatted input from a file. It needs to modify the variables passed to it based on the input from the file. To modify these variables, fscanf needs to know their addresses.So,The & operator is used to obtain the address of a variable. When you pass the address of the variable, fscanf can modify the value stored at that address.
    }

    bool read(double& empSalary)
    {
        return fscanf(fptr, "%lf,", &empSalary) == 1;
    }
}



//  while (fscanf(fptr, "%c", &ch) == 1) {
        // fscanf reads one character at a time from the file pointed to by fptr and stores it in ch.
        // It returns the number of items successfully read (which should be 1 for a single character read).
        // The loop continues as long as fscanf successfully reads one character (i.e., returns 1).

        // If the character read is a newline character ('\n'), increment the noOfRecs counter.
//noOfRecs += (ch == '\n');
  //  



//fscanf : fscanf reads data from the file according to the specified format.
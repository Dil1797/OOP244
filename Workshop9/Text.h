/*      Workshop - #9 (PART 1)
Full Name  :    Dil Humyra Sultana Borna
Date       :    07/26/2024
I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_TEXT_H
#define SENECA_TEXT_H

#include <iostream>

namespace seneca {
    class Text {
        char* m_filename; // Dynamically stores the name of the text file
        char* m_content;  // Dynamically stores the content of the text file
        int getFileLength() const; // Gets the length of the text file on disk
    protected:
        const char& operator[](int index) const; // Provides read-only access to the content
    public:
        Text(const char* filename = nullptr); // Constructor
        Text(const Text& other); // Copy constructor
        Text& operator=(const Text& other); // Copy assignment operator
        ~Text(); // Destructor

        void read(); // Reads the file content into memory
        virtual void write(std::ostream& os) const; // Writes the content to an output stream
    };

    // Overload the insertion operator to print the content of the Text object
    std::ostream& operator<<(std::ostream& os, const Text& text);
}

#endif // TSENECA_TEXT_H


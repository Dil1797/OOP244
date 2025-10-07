/*      Workshop - #9 (PART 1)
Full Name  :    Dil Humyra Sultana Borna
Date       :    07/26/2024
I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include "Text.h"
#include <fstream>
#include <cstring>

namespace seneca {
    // Provided function to get the length of the file from disk
    int Text::getFileLength() const {
        int len = 0;
        std::ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    // Constructor initializes filename and reads file content if filename is provided
    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr) {
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
    }

    // Copy constructor creates a deep copy of the given Text object
    Text::Text(const Text& other) : m_filename(nullptr), m_content(nullptr) {
        *this = other;
    }

    // Copy assignment operator performs a deep copy of the given Text object
    Text& Text::operator=(const Text& other) {
        if (this != &other) {
            delete[] m_filename;
            delete[] m_content;

            if (other.m_filename) {
                m_filename = new char[strlen(other.m_filename) + 1];
                strcpy(m_filename, other.m_filename);
            } else {
                m_filename = nullptr;
            }

            if (other.m_content) {
                m_content = new char[strlen(other.m_content) + 1];
                strcpy(m_content, other.m_content);
            } else {
                m_content = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }

    // Reads the content of the file into dynamically allocated memory
    void Text::read() {
        delete[] m_content;
        m_content = nullptr;

        int length = getFileLength();
        if (length > 0) {
            m_content = new char[length + 1];
            std::ifstream file(m_filename);
            file.read(m_content, length);
            m_content[length] = '\0';
        }
    }

    // Writes the content to an output stream if content is not null
    void Text::write(std::ostream& os) const {
        if (m_content) {
            os << m_content;
        }
    }

    // Provides read-only access to the content at the given index
    const char& Text::operator[](int index) const {
        return m_content[index];
    }

    // Overloads the insertion operator to print the content of the Text object
    std::ostream& operator<<(std::ostream& os, const Text& text) {
        text.write(os);
        return os;
    }
}

/*      Workshop - #9 (PART 1)
Full Name  :    Dil Humyra Sultana Borna
Date       :    07/26/2024
I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#include "HtmlText.h"
#include <cstring>

namespace seneca {
    // Constructor initializes filename and title, reads file content if filename is provided
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename), m_title(nullptr) {
        if (title) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    // Copy constructor creates a deep copy of the given HtmlText object
    HtmlText::HtmlText(const HtmlText& other) : Text(other), m_title(nullptr) {
        *this = other;
    }

    // Copy assignment operator performs a deep copy of the given HtmlText object
    HtmlText& HtmlText::operator=(const HtmlText& other) {
        if (this != &other) {
            Text::operator=(other);
            delete[] m_title;

            if (other.m_title) {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            } else {
                m_title = nullptr;
            }
        }
        return *this;
    }

    // Destructor cleans up dynamically allocated memory
    HtmlText::~HtmlText() {
        delete[] m_title;
    }

    // Writes the content to an output stream in HTML format
    void HtmlText::write(std::ostream& os) const {
        os << "<html><head><title>";
        if (m_title) {
            os << m_title;
        } else {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";

        if (m_title) {
            os << "<h1>" << m_title << "</h1>\n";
        }

        bool MS = false; // Multiple space flag
        for (int i = 0; (*this)[i] != '\0'; ++i) {
            switch ((*this)[i]) {
            case ' ':
                if (MS) {
                    os << "&nbsp;";
                } else {
                    MS = true;
                    os << ' ';
                }
                break;
            case '<':
                os << "&lt;";
                MS = false;
                break;
            case '>':
                os << "&gt;";
                MS = false;
                break;
            case '\n':
                os << "<br />\n";
                MS = false;
                break;
            default:
                MS = false;
                os << (*this)[i];
                break;
            }
        }

        os << "</body>\n</html>";
    }
}

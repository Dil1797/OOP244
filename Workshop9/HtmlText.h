/*      Workshop - #9 (PART 1)
Full Name  :    Dil Humyra Sultana Borna
Date       :    07/26/2024
I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/




#ifndef SENECA_HTMLTEXT_H
#define SENECA_HTMLTEXT_H

#include "Text.h"

namespace seneca {
    // HtmlText class handles HTML file conversion, inheriting from Text
    class HtmlText : public Text {
        char* m_title; // Dynamically stores the title of the HTML file
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr); // Constructor
        HtmlText(const HtmlText& other); // Copy constructor
        HtmlText& operator=(const HtmlText& other); // Copy assignment operator
        ~HtmlText(); // Destructor

        void write(std::ostream& os) const override; // Writes the content to an output stream in HTML format
    };
}

#endif // SENECA_HTMLTEXT_H

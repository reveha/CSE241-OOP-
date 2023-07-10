#ifndef _BOOK_H_
#define _BOOK_H_

#include "Catalog.h"
using namespace std;

namespace Cat{
    class Book : public Catalog {
    public:
        Book();
        ~Book();
        
        // Overridden function to print the book information
        void printInformation();
        
        // Overridden function to divide the line and extract specific fields
        void divideLine();
        
        // Getter functions for specific fields
        string getAuthors() const;
        string getTags() const;
        string getArtists() const;
        string getGenre() const;
        string getDirectors() const;
        string getStarrings() const;

    private:
        string authors;  // Authors of the book
        string tags;     // Tags associated with the book
    };

}

#endif
#ifndef _MOVIE_H_
#define _MOVIE_H_

#include "Catalog.h"
using namespace std;

namespace Cat{
    
    class Movie : public Catalog {
    public:
        Movie();
        ~Movie();
        
        // Overridden function to print the movie information
        void printInformation();
        
        // Overridden function to divide the line and extract specific fields
        void divideLine();
        
        // Getter functions for specific fields
        string getDirectors() const;
        string getGenre() const;
        string getStarrings() const;
        string getArtists() const;
        string getAuthors() const;
        string getTags() const;

    private:
        string directors;  // Directors of the movie
        string genre;      // Genre of the movie
        string starrings;  // Starring actors/actresses in the movie
    };

}

#endif
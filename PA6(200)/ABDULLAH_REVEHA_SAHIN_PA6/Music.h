#ifndef _MUSIC_H_
#define _MUSIC_H_
 
#include "Catalog.h"
using namespace std;

namespace Cat{
    
   class Music : public Catalog {
    public:
        Music();
        ~Music();
        
        // Overridden function to print the music information
        void printInformation();
        
        // Overridden function to divide the line and extract specific fields
        void divideLine();
        
        // Getter functions for specific fields
        string getArtists() const;
        string getGenre() const;
        string getAuthors() const;
        string getTags() const;
        string getDirectors() const;
        string getStarrings() const;

    private:
        string artists;  // Artists involved in the music
        string genre;    // Genre of the music
    };

}

#endif
#include "Music.h"
#include <iostream>
using namespace std;

namespace Cat{
    // Default constructor
    Music::Music() : Catalog(){

    }

    // Destructor
    Music::~Music(){

    }

    // Get the artists of the music
    string Music::getArtists() const{
        return this->artists;
    }

    // Get the genre of the music
    string Music::getGenre() const{
        return this->genre;
    }

    // Get the authors (not applicable for music)
    string Music::getAuthors() const{
        return "";
    }

    // Get the tags (not applicable for music)
    string Music::getTags() const{
        return "";
    }

    // Get the starrings (not applicable for music)
    string Music::getStarrings() const{
        return "";
    }

    // Get the directors (not applicable for music)
    string Music::getDirectors() const{
        return "";
    }

    // Print information about the music
    void Music::printInformation(){
        // Divide the line and extract the fields
        divideLine();

        // Print the music information
        cout<<"Title: "<<this->title<<endl;
        cout<<"Artists: "<<this->artists<<endl;
        cout<<"Year: " <<this->year<<endl;
        cout<<"Genre: " <<this->genre<<endl;
    }

    // Divide the line and extract title, artists, year, and genre
    void Music::divideLine(){
        // Check if missingFieldException is false, indicating that the line should not be divided
        if (!missingFieldException){
            return;
        }

        // Clear the existing values of title, artists, year, and genre
        this->title.clear();
        this->artists.clear();
        this->year.clear();
        this->genre.clear();

        // Variables to keep track of quotes, counter, and character index
        int quotes=0;
        int counter=0;
        int k=0;

        // Iterate through each character in the line
        for (auto i=0;i<line.length();i++){
            // Check if the character is a quote
            if(line[i]=='"'){
                quotes++;
                continue;
            }

            // Check if the current character is within quotes
            if(quotes%2!=0){
                // Determine the appropriate field based on the counter value
                if(counter==0){
                    // Append the character to the title string
                    this->title+=line[i];
                    // Check if the next character is also a quote, indicating the end of the title
                    if (line[i+1]=='"'){
                        // Add a null terminator to the title string
                        this->title[k+1]='\0';
                    }
                    k++;
                }
                else if(counter==1){
                    // Append the character to the artists string
                    this->artists+=line[i];
                    // Check if the next character is also a quote, indicating the end of the artists
                    if (line[i+1]=='"'){
                        // Add a null terminator to the artists string
                        this->artists[k+1]='\0';
                    }
                    k++;
                }
                else if(counter==2){
                    // Append the character to the year string
                    this->year+=line[i];
                    // Check if the next character is also a quote, indicating the end of the year
                    if (line[i+1]=='"'){
                        // Add a null terminator to the year string
                        this->year[k+1]='\0';
                    }
                    k++;
                }
                else if(counter==3){
                    // Append the character to the genre string
                    this->genre+=line[i];
                    // Check if the next character is also a quote, indicating the end of the genre
                    if (line[i+1]=='"'){
                        // Add a null terminator to the genre string
                        this->genre[k+1]='\0';
                    }
                    k++;
                }
            }
            else{
                // Increase the counter to move to the next field
                counter++;
                // Reset the character index to 0 for the next field
                k=0;
            }
        }
    }
}

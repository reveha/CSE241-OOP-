#include "Movie.h"
#include <iostream>
using namespace std;

namespace Cat{
    // Default constructor
    Movie::Movie() : Catalog(){

    }

    // Destructor
    Movie::~Movie(){

    }

    // Print information about the movie
    void Movie::printInformation(){
        // Divide the line and extract the fields
        divideLine();

        // Print the movie information
        cout<<"Title: "<<this->title<<endl;
        cout<<"Directors: "<<this->directors<<endl;
        cout<<"Year: "<<this->year<<endl;
        cout<<"Genre: "<<this->genre<<endl;
        cout<<"Starrings: "<<this->starrings<<endl;
    }

    // Get the directors of the movie
    string Movie::getDirectors() const{
        return this->directors;
    }

    // Get the genre of the movie
    string Movie::getGenre() const{
        return this->genre;
    }

    // Get the starrings of the movie
    string Movie::getStarrings() const{
        return this->starrings;
    }

    // Get the artists (not applicable for movies)
    string Movie::getArtists() const{
        return "";
    }

    // Get the authors (not applicable for movies)
    string Movie::getAuthors() const{
        return "";
    }

    // Get the tags (not applicable for movies)
    string Movie::getTags() const{
        return "";
    }

    // Divide the line and extract title, directors, year, genre, and starrings
    void Movie::divideLine(){
        // Check if missingFieldException is false, indicating that the line should not be divided
        if(!missingFieldException){
            return;
        }

        // Clear the existing values of title, directors, year, genre, and starrings
        this->title.clear();
        this->directors.clear();
        this->year.clear();
        this->genre.clear();
        this->starrings.clear();

        // Variables to keep track of quotes, counter, and character index
        int quotes=0;
        int counter=0;
        int k=0;

        // Iterate through each character in the line
        for (int i=0;i<line.length();i++){
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
                    if(line[i+1]=='"'){
                        // Add a null terminator to the title string
                        this->title[k+1]='\0';
                    }
                    k++;
                }
                else if(counter==1){
                    // Append the character to the directors string
                    this->directors+=line[i];
                    // Check if the next character is also a quote, indicating the end of the directors
                    if (line[i+1]=='"'){
                        // Add a null terminator to the directors string
                        this->directors[k+1]='\0';
                    }
                    k++;
                }
                else if(counter==2){
                    // Append the character to the year string
                    this->year+=line[i];
                    // Check if the next character is also a quote, indicating the end of the year
                    if (line[i+1] =='"'){
                        // Add a null terminator to the year string
                        this->year[k+1]='\0';
                    }
                    k++;
                }
                else if(counter==3){
                    // Append the character to the genre string
                    this->genre+=line[i];
                    // Check if the next character is also a quote, indicating the end of the genre
                    if(line[i+1]=='"'){
                        // Add a null terminator to the genre string
                        this->genre[k+1]='\0';
                    }
                    k++;
                }
                else if(counter==4){
                    // Append the character to the starrings string
                    this->starrings+=line[i];
                    // Check if the next character is also a quote, indicating the end of the starrings
                    if(line[i+1]=='"'){
                        // Add a null terminator to the starrings string
                        this->starrings[k+1] ='\0';
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

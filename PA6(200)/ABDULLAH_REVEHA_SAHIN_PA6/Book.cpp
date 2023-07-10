#include "Book.h"
#include <iostream>
using namespace std;

namespace Cat {
    // Constructor
    Book::Book() : Catalog() {

    }

    // Destructor
    Book::~Book() {

    }

    // Getter for authors
    string Book::getAuthors() const {
        return this->authors;
    }

    // Getter for tags
    string Book::getTags() const {
        return this->tags;
    }

    // Getter for starrings (not applicable for books)
    string Book::getStarrings() const {
        return "";
    }

    // Getter for directors (not applicable for books)
    string Book::getDirectors() const {
        return "";
    }

    // Getter for genre (not applicable for books)
    string Book::getGenre() const {
        return "";
    }

    // Getter for artists (not applicable for books)
    string Book::getArtists() const {
        return "";
    }

    // Print book information
    void Book::printInformation() {
        divideLine();
        cout<<"Title: "<<this->title<<endl;
        cout<<"Authors: "<<this->authors<<endl;
        cout<<"Year: "<<this->year<<endl;
        cout<<"Tags: "<<this->tags<<endl;
    }

    // Divide the line and extract title, authors, year, and tags
    void Book::divideLine() {
        // Check if missingFieldException is false, indicating that the line should not be divided
        if (!missingFieldException) {
            return;
        }

        // Clear the existing values of title, authors, year, and tags
        this->title.clear();
        this->authors.clear();
        this->year.clear();
        this->tags.clear();

        // Variables to keep track of quotes, counter, and character index
        int quotes=0;
        int counter=0;
        int k=0;

        // Iterate through each character in the line
        for(int i=0;i<line.length();i++){
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
                    // Append the character to the authors string
                    this->authors+=line[i];
                    // Check if the next character is also a quote, indicating the end of the authors
                    if (line[i+1]=='"') {
                        // Add a null terminator to the authors string
                        this->authors[k+1]='\0';
                    }
                    k++;
                }
                else if (counter == 2) {
                    // Append the character to the year string
                    this->year += line[i];
                    // Check if the next character is also a quote, indicating the end of the year
                    if (line[i+1]=='"'){
                        // Add a null terminator to the year string
                        this->year[k+1]='\0';
                    }
                    k++;
                }
                else if(counter==3){
                    // Append the character to the tags string
                    this->tags+=line[i];
                    // Check if the next character is also a quote, indicating the end of the tags
                    if (line[i+1]=='"'){
                        // Add a null terminator to the tags string
                        this->tags[k+1]='\0';
                    }
                    k++;
                }
            }
            else{
                // Increase the counter to move to the next field
                counter++;
                // Reset the character index to 0 for the next field
                k = 0;
            }
        }
    }

}

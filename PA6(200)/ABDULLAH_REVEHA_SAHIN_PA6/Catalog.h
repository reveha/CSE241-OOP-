#ifndef _CATALOG_H_
#define _CATALOG_H_

#include <vector>
#include <string>
using namespace std;

namespace Cat{
    class Catalog {
    public:
        Catalog();
        Catalog(string title, int year);
        virtual ~Catalog();
        
        // Pure virtual function to be overridden by derived classes
        virtual void printInformation() = 0;
        
        // Getter and setter for year
        string getYear() const;
        void setYear(const int year);
        
        // Getter and setter for title
        string getTitle() const;
        void setTitle(string title);
        
        // Getter and setter for the entire line of the catalog entry
        string getLine() const;
        void setLine(const string line);
        
        // Getter and setter for missingFieldException flag
        bool getMissingFieldException() const;
        void setMissingFieldException(bool valid);
        
        // Getter and setter for duplicateEntryException flag
        void setDuplicateEntryException(bool valid);
        bool getDuplicateEntryException() const;
        
        // Getter and setter for wrongCommandException flag
        void setWrongCommandException(bool valid);
        bool getWrongCommandException() const;
        
        // Check if the catalog entry is valid (no missing fields)
        bool isValid() const;
        
        // Setter for the number of quotes in the catalog entry
        void setNumberOfQuotes(const int numberOfQuotes);
        
        // Getter for the number of quotes in the catalog entry
        int getNumberOfQuotes() const;
        
        // Pure virtual function to be overridden by derived classes
        virtual void divideLine() = 0;
        
    protected:
        string line;                   // The entire line of the catalog entry
        string title;                  // Title of the catalog entry
        string year;                   // Year of the catalog entry
        int numberOfQuotes;            // Number of quotes in the catalog entry
        bool missingFieldException;    // Flag for missing field exception
        bool duplicateEntryException;  // Flag for duplicate entry exception
        bool wrongCommandException;    // Flag for wrong command exception
    };

} 

#endif
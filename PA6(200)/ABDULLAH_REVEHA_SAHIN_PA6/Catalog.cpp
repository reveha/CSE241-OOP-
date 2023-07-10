#include "Catalog.h"

using namespace std;

namespace Cat {
    // Constructor
    Catalog::Catalog() {
        // Set default exception flags to true
        this->missingFieldException=true;
        this->duplicateEntryException=true;
        this->wrongCommandException=true;
    }

    // Overloaded Constructor
    Catalog::Catalog(string title, int year) {
        // Set default exception flags to true
        this->missingFieldException=true;
        this->duplicateEntryException=true;
        this->wrongCommandException=true;
    }

    // Destructor
    Catalog::~Catalog() {
        // Destructor implementation
    }

    // Getter for line
    string Catalog::getLine() const {
        return this->line;
    }

    // Getter for missingFieldException
    bool Catalog::getMissingFieldException() const {
        return this->missingFieldException;
    }

    // Setter for duplicateEntryException
    void Catalog::setDuplicateEntryException(bool valid) {
        this->duplicateEntryException = valid;
    }

    // Setter for wrongCommandException
    void Catalog::setWrongCommandException(bool valid) {
        this->wrongCommandException = valid;
    }

    // Getter for duplicateEntryException
    bool Catalog::getDuplicateEntryException() const {
        return this->duplicateEntryException;
    }

    // Getter for wrongCommandException
    bool Catalog::getWrongCommandException() const {
        return this->wrongCommandException;
    }

    // Check if the catalog is valid (no exceptions)
    bool Catalog::isValid() const {
        return (this->wrongCommandException && this->duplicateEntryException && this->missingFieldException);
    }

    // Setter for line
    void Catalog::setLine(const string line) {
        this->line = line;
    }

    // Getter for year
    string Catalog::getYear() const {
        return this->year;
    }

    // Getter for title
    string Catalog::getTitle() const {
        return this->title;
    }

    // Setter for missingFieldException
    void Catalog::setMissingFieldException(bool valid) {
        this->missingFieldException = valid;
    }

    // Setter for numberOfQuotes
    void Catalog::setNumberOfQuotes(const int numberOfQuotes) {
        this->numberOfQuotes = numberOfQuotes;
    }

    // Getter for numberOfQuotes
    int Catalog::getNumberOfQuotes() const {
        return this->numberOfQuotes;
    }
} // namespace Cat

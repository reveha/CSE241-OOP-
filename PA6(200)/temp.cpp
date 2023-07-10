#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

// Exception classes
class MissingFieldException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Exception: missing field";
    }
};

class DuplicateEntryException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Exception: duplicate entry";
    }
};

class WrongCommandException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Exception: command is wrong";
    }
};

// Base class for catalog entries
class CatalogEntry {
protected:
    std::string title;
    std::string field1;
    std::string field2;
    std::string field3;

public:
    CatalogEntry(const std::string& title, const std::string& field1, const std::string& field2, const std::string& field3)
        : title(title), field1(field1), field2(field2), field3(field3) {}

    virtual ~CatalogEntry() {}

    virtual std::string getDetails() const {
        return title + " " + field1 + " " + field2 + " " + field3;
    }

    virtual std::string getField(const std::string& fieldName) const {
        if (fieldName == "title")
            return title;
        else if (fieldName == "field1")
            return field1;
        else if (fieldName == "field2")
            return field2;
        else if (fieldName == "field3")
            return field3;
        else
            throw WrongCommandException();
    }
};

// Derived classes for specific catalog types
class BookCatalogEntry : public CatalogEntry {
    std::string authors;
    std::string year;
    std::string tags;

public:
    BookCatalogEntry(const std::string& title, const std::string& authors, const std::string& year, const std::string& tags)
        : CatalogEntry(title, authors, year, tags), authors(authors), year(year), tags(tags) {}

    std::string getDetails() const override {
        return CatalogEntry::getDetails() + " \"" + authors + "\" \"" + year + "\" \"" + tags + "\"";
    }

    std::string getField(const std::string& fieldName) const override {
        if (fieldName == "authors")
            return authors;
        else
            return CatalogEntry::getField(fieldName);
    }
};

class MusicCatalogEntry : public CatalogEntry {
    std::string artists;
    std::string year;
    std::string genre;

public:
    MusicCatalogEntry(const std::string& title, const std::string& artists, const std::string& year, const std::string& genre)
        : CatalogEntry(title, artists, year, genre), artists(artists), year(year), genre(genre) {}

    std::string getDetails() const override {
        return CatalogEntry::getDetails() + " \"" + artists + "\" \"" + year + "\" \"" + genre + "\"";
    }

    std::string getField(const std::string& fieldName) const override {
        if (fieldName == "artists")
            return artists;
        else if (fieldName == "genre")
            return genre;
        else
            return CatalogEntry::getField(fieldName);
    }
};

class MovieCatalogEntry : public CatalogEntry {
    std::string director;
    std::string year;
    std::string genre;
    std::string starring;

public:
    MovieCatalogEntry(const std::string& title, const std::string& director, const std::string& year, const std::string& genre, const std::string& starring)
        : CatalogEntry(title, director, year, genre), director(director), year(year), genre(genre), starring(starring) {}

    std::string getDetails() const override {
        return CatalogEntry::getDetails() + " \"" + director + "\" \"" + year + "\" \"" + genre + "\" \"" + starring + "\"";
    }

    std::string getField(const std::string& fieldName) const override {
        if (fieldName == "director")
            return director;
        else if (fieldName == "genre")
            return genre;
        else if (fieldName == "starring")
            return starring;
        else
            return CatalogEntry::getField(fieldName);
    }
};

// Catalog class
template<typename T>
class Catalog {
    std::vector<T> entries;

public:
    Catalog() {}

    void addEntry(const T& entry) {
        entries.push_back(entry);
    }

    std::vector<T> search(const std::string& searchString, const std::string& field) const {
        std::vector<T> matchedEntries;
        for (const auto& entry : entries) {
            try {
                if (entry.getField(field).find(searchString) != std::string::npos)
                    matchedEntries.push_back(entry);
            }
            catch (const WrongCommandException&) {
                // Ignore entries without the specified field
            }
        }
        return matchedEntries;
    }

    std::vector<T> sort(const std::string& field) const {
        std::vector<T> sortedEntries = entries;
        std::sort(sortedEntries.begin(), sortedEntries.end(), [field](const T& entry1, const T& entry2) {
            try {
                return entry1.getField(field) < entry2.getField(field);
            }
            catch (const WrongCommandException&) {
                return false;  // Ignore entries without the specified field during sorting
            }
        });
        return sortedEntries;
    }

    int getUniqueEntryCount() const {
        std::set<std::string> uniqueEntries;
        for (const auto& entry : entries) {
            uniqueEntries.insert(entry.getDetails());
        }
        return static_cast<int>(uniqueEntries.size());
    }
};

// Log class for logging events
class Log {
    std::ofstream outputFile;

public:
    Log() {
        outputFile.open("output.txt", std::ios::out);
        if (!outputFile.is_open()) {
            throw std::runtime_error("Failed to open output file.");
        }
    }

    ~Log() {
        outputFile.close();
    }

    void logCatalogRead(const std::string& catalogType, int uniqueEntryCount) {
        outputFile << "Catalog Read: " << catalogType << " " << uniqueEntryCount << " unique entries" << std::endl;
    }

    void logCommand(const std::string& command, const std::vector<std::string>& output) {
        outputFile << command << std::endl;
        for (const auto& line : output) {
            outputFile << line << std::endl;
        }
    }

    void logException(const std::string& exception) {
        outputFile << "Exception: " << exception << std::endl;
    }
};

// Function to parse and execute commands
template<typename T>
void executeCommands(Catalog<T>& catalog, Log& log) {
    std::ifstream commandsFile("commands.txt");
    if (!commandsFile.is_open()) {
        throw std::runtime_error("Failed to open commands file.");
    }

    std::string line;
    while (std::getline(commandsFile, line)) {
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        try {
            if (command == "search") {
                std::string searchString;
                std::string inKeyword;
                std::string field;
                ss >> searchString >> inKeyword >> field;

                if (inKeyword != "in") {
                    throw WrongCommandException("command is wrong");
                }

                std::vector<T> matchedEntries = catalog.search(searchString, field);
                log.logCommand(line, getEntryDetails(matchedEntries));
            }
            else if (command == "sort") {
                std::string field;
                ss >> field;

                std::vector<T> sortedEntries = catalog.sort(field);
                log.logCommand(line, getEntryDetails(sortedEntries));
            }
            else {
                throw WrongCommandException("command is wrong");
            }
        }
        catch (const MissingFieldException&) {
            log.logException("missing field");
        }
        catch (const DuplicateEntryException&) {
            log.logException("duplicate entry");
        }
        catch (const WrongCommandException& e) {
            log.logException(e.what());
        }
    }
}

int main() {
    try {
        std::ifstream dataFile("data.txt");
        if (!dataFile.is_open()) {
            throw std::runtime_error("Failed to open data file.");
        }

        std::string catalogType;
        std::getline(dataFile, catalogType);

        Log log;
        if (catalogType == "book") {
            Catalog<BookCatalogEntry> bookCatalog;
            parseCatalogEntries<BookCatalogEntry>(dataFile, bookCatalog, log);
            log.logCatalogRead(catalogType, bookCatalog.getUniqueEntryCount());
            executeCommands(bookCatalog, log);
        }
        else if (catalogType == "music") {
            Catalog<MusicCatalogEntry> musicCatalog;
            parseCatalogEntries<MusicCatalogEntry>(dataFile, musicCatalog, log);
            log.logCatalogRead(catalogType, musicCatalog.getUniqueEntryCount());
            executeCommands(musicCatalog, log);
        }
        else if (catalogType == "movie") {
            Catalog<MovieCatalogEntry> movieCatalog;
            parseCatalogEntries<MovieCatalogEntry>(dataFile, movieCatalog, log);
            log.logCatalogRead(catalogType, movieCatalog.getUniqueEntryCount());
            executeCommands(movieCatalog, log);
        }
        else {
            throw WrongCommandException("Catalog type is not supported");
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

#ifndef _FILE_H_
#define _FILE_H_
#include "Catalog.h"
#include "WrongCommandException.h"
#include "MissingFieldException.h"
#include "DuplicateException.h"
#include <typeinfo>
#include <algorithm>
using namespace std;

namespace Cat{
    class Catalog;
    class WrongCommandException;
    class DuplicateException;
    class MissingFieldException;
    const int numberOfMusicAndBookQuotes=8;
    const int numberOfMovieQuotes=10;

    template<class T>
    class File{
    public:
        File(); // Default constructor
        File(vector<T> catalog, string catalogName); // Constructor with parameters
        ~File(); // Destructor

        void readData(); // Read data from file
        void readComment(); // Read comments from file
        void writeFile(); // Write data to file
        vector<T> getCatalog() const; // Get the catalog vector
        void setCatalog(vector<T> catalog); // Set the catalog vector
        void checkTheMissingFieldException(); // Check for missing field exceptions
        void checkTheDuplicateException(); // Check for duplicate exceptions
        int countnumberOfElements(); // Count the number of elements in the catalog
        void setQuotes(); // Set quotes
        void printCatalogInformations(); // Print catalog information

        // Search functions
        void searchTitle(const string& word);
        void searchAuthors(const string& word);
        void searchTags(const string& word);
        void searchDirectors(const string& word);
        void searchYear(const string& word);
        void searchStarrings(const string& word);
        void searchGenre(const string& word);
        void searchArtists(const string& word);

        // Sort functions
        void sortTitle(const string& word);
        void sortAuthors(const string& word);
        void sortDirectors(const string& word);
        void sortTags(const string& word);
        void sortYear(const string& word);
        void sortGenre(const string& word);
        void sortArtists(const string& word);
        void sortStarrings(const string& word);

        void checkCommands(); // Check commands in a file
        int validEntries(); // Count valid entries in the catalog

        // Print functions for exceptions
        void printDuplicates();
        void printMissings();
        void printWrongCommand();

    private:
        vector<T> catalog; // Catalog vector
        int numberOfElements; // Number of elements in the catalog
        string catalogName; // Catalog name
        int catalogType; // 1 means book, 2 means music, 3 means movie;
    };


    template<class T>
    File<T>::File(){
        numberOfElements=countnumberOfElements()-1;
        // Initialize catalog with a size of numberOfElements
        catalog.resize(numberOfElements);
        
    }

    template<class T>
    File<T>::File(vector<T> catalog, string catalogName){
        // Assign the provided catalog and catalogName to the class members
        this->catalog=catalog;
        this->catalogName=catalogName;
        numberOfElements=countnumberOfElements()-1;
        
    }

    template<class T>
    File<T>::~File(){
        // Destructor 
    }

    template<class T>
    void File<T>::printCatalogInformations(){
        for(auto i=0;i<numberOfElements;i++){
            // Check if the catalog element has a missing field exception
            if(catalog[i].getMissingFieldException())
                catalog[i].printInformation();
        }
       
    }


    template<class T>
    void File<T>::readData(){
        fstream file;
        file.open("data.txt",ios::in);
        getline(file,catalogName);
        // Determine the catalog type based on the catalogName
        if(catalogName[0]=='b'){
            catalogType=1;
        }
        else if(catalogName[1]=='u'){
            catalogType=2;
        }
        else{
            catalogType=3;
        }
        string temp;
        for(int i=0;i<numberOfElements;i++){
            getline(file,temp);
            // Set the line for the catalog element
            catalog[i].setLine(temp);
        }
        // Rest of the code...
    }

    template<class T>
    int File<T>::validEntries(){
        int counter=0;
        for(int i=0;i<numberOfElements;i++){
            // Check if the catalog element is valid
            if(catalog[i].isValid()){
                counter++;
            }
        }
        return counter;
        // Rest of the code...
    }

    template<class T>
    void File<T>::writeFile(){
        checkTheMissingFieldException();
        checkTheDuplicateException();
        fstream file;
        file.open("output.txt",ios::out);
        file<<"Catalog read: "<<catalogName<<endl;
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].getMissingFieldException()==false){
                // Checking the MissingFieldException
                try{
                    throw MissingFieldException();
                }
                catch(MissingFieldException& obj){
                    file<<"Exception: missing field"<<endl;
                    //obj.print();
                }
                file<<catalog[i].getLine()<<endl;
            }
            else if(catalog[i].getDuplicateEntryException()==false){
                // Checking the DuplicationException
                try{
                    throw DuplicateException();
                }
                catch(DuplicateException& obj){
                    file<<"Exception: duplicate entry"<<endl;
                    //obj.print();
                }
                file<<catalog[i].getLine()<<endl;
            }
        }
        file<<validEntries()<<" unique entries"<<endl;
        checkCommands();
        file.close();
        // Rest of the code...
    }

    template<class T>
    int File<T>::countnumberOfElements(){
        fstream file;
        file.open("data.txt",ios::in);
        string temp;
        file>>temp;
        int counter=0;
        // Count the number of elements in the file
        while(!file.eof()){
            getline(file,temp);
            counter++;
        }
        return counter;
        // Rest of the code...
    }

    

    template<class T>
    void File<T>::checkTheDuplicateException(){
        string str;
        for(int i=0;i<numberOfElements;i++){
            for(int j=1;catalog[i].getLine().length();j++){
                if(catalog[i].getLine()[j]=='"'){
                    break;
                }
                str+=catalog[i].getLine()[j];
            }
            if(i+1==numberOfElements){ // That means end of the element
                break;
            }
            for(int k=i+1;k<numberOfElements;k++){ // To compare other word
                string temp;
                for(int h=1;h<catalog[k].getLine().length();h++){
                    if(catalog[k].getLine()[h]=='"'){
                        break;
                    }
                    temp+=catalog[k].getLine()[h];
                }
                // Compare the extracted strings for duplicate entry
                if(temp==str){
                    catalog[k].setDuplicateEntryException(false);
                }
            }
            str.clear();
        }
        // Rest of the code...
    }

    template<class T>
    void File<T>::checkTheMissingFieldException(){ // To understand missing field exception
        // Check missing field exception based on catalog type
        if(catalogType==1 || catalogType==2){
            for(auto i=0;i<numberOfElements;i++){
                if(catalog[i].getNumberOfQuotes()<numberOfMusicAndBookQuotes){
                    catalog[i].setMissingFieldException(false);
                }
            }
            return;
        }

        for(auto i=0;i<numberOfElements;i++){ 
            if(catalog[i].getNumberOfQuotes()<numberOfMovieQuotes){
                catalog[i].setMissingFieldException(false);
            }
        }
        // Rest of the code...
    }

    template<class T>
    void File<T>::setQuotes(){
        for(int i=0;i<numberOfElements;i++){
            int counter=0;
            // Count the number of quotes in the line
            for(int j=0;j<catalog[i].getLine().length();j++){
                if(catalog[i].getLine()[j]=='"'){
                    counter++;
                }
            }
            catalog[i].setNumberOfQuotes(counter);
        }
        // Rest of the code...
    }

    


    template<class T>
    void File<T>::searchTitle(const string& word){
        fstream file;
        file.open("output.txt",ios::app);

        // Iterate through catalog entries
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){
                catalog[i].divideLine();
                // Search for the word in the title
                size_t found=catalog[i].getTitle().find(word);
                if(found!=string::npos){
                    // Write search result to file
                    file<<"search "<<"\""<<word<<"\""<<" in "<<"\""<<"title"<<"\""<<endl;
                    file<<catalog[i].getLine();
                }
            }
        }
        file.close();
    }

    // Explanation of the other search functions is similar.
    // Here are the remaining functions:

    template<class T>
    void File<T>::searchAuthors(const string& word){
        fstream file;
        file.open("output.txt",ios::app);

        // Iterate through catalog entries
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){
                catalog[i].divideLine();
                // Search for the word in the authors
                size_t found=catalog[i].getAuthors().find(word);
                if(found!=string::npos){
                    // Write search result to file
                    file<<"search "<<"\""<<word<<"\""<<" in "<<"\""<<"authors"<<"\""<<endl;
                    file<<catalog[i].getLine();
                }
            }
        }
        file.close();
    }

    template<class T>
    void File<T>::searchTags(const string& word){
        fstream file;
        file.open("output.txt",ios::app);

            for(int i=0;i<numberOfElements;i++){
                if(catalog[i].isValid()){
                    catalog[i].divideLine();
                    size_t found=catalog[i].getTags().find(word);
                    if(found!=string::npos){
                        file<<"search "<<"\""<<word<<"\""<<" in "<<"\""<<"tags"<<"\""<<endl;
                        file<<catalog[i].getLine();
                    }
                }
            }
            file.close();
    }

    template<class T>
    void File<T>::searchDirectors(const string& word){
        fstream file;
        file.open("output.txt",ios::app);
            for(int i=0;i<numberOfElements;i++){
                if(catalog[i].isValid()){
                    catalog[i].divideLine();
                    size_t found=catalog[i].getDirectors().find(word);
                    if(found!=string::npos){
                        file<<"search "<<"\""<<word<<"\""<<" in "<<"\""<<"directors"<<"\""<<endl;
                        file<<catalog[i].getLine();
                    }
                }
            }
            file.close();
    }

    template<class T>
    void File<T>::searchYear(const string& word){
        fstream file;
        file.open("output.txt",ios::app);
            for(int i=0;i<numberOfElements;i++){
                if(catalog[i].isValid()){
                    catalog[i].divideLine();
                    size_t found=catalog[i].getYear().find(word);
                    if(found!=string::npos){
                        file<<"search "<<"\""<<word<<"\""<<" in "<<"\""<<"year"<<"\""<<endl;
                        file<<catalog[i].getLine();
                    }
                }
            }
            file.close();
    }

    template<class T>
    void File<T>::searchStarrings(const string& word){
        fstream file;
        file.open("output.txt",ios::app);
            for(int i=0;i<numberOfElements;i++){
                if(catalog[i].isValid()){
                    catalog[i].divideLine();
                    size_t found=catalog[i].getStarrings().find(word);
                    if(found!=string::npos){
                        file<<"search "<<"\""<<word<<"\""<<" in "<<"\""<<"starrings"<<"\""<<endl;
                        file<<catalog[i].getLine();
                    }
                }
            }
            file.close();
    }

    template<class T>
    void File<T>::searchGenre(const string& word){
        fstream file;
        file.open("output.txt",ios::app);
            for(int i=0;i<numberOfElements;i++){
                if(catalog[i].isValid()){
                    catalog[i].divideLine();
                    size_t found=catalog[i].getGenre().find(word);
                    if(found!=string::npos){
                        file<<"search "<<"\""<<word<<"\""<<" in "<<"\""<<"genre"<<"\""<<endl;
                        file<<catalog[i].getLine();
                    }
                }
            }
            file.close();
    }

    // ...

    template<class T>
    void File<T>::searchArtists(const string& word){
        fstream file;
        file.open("output.txt",ios::app);

        // Iterate through catalog entries
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){
                catalog[i].divideLine();
                // Search for the word in the artists
                size_t found=catalog[i].getArtists().find(word);
                if(found!=string::npos){
                    // Write search result to file
                    file<<"search "<<"\""<<word<<"\""<<" in "<<"\""<<"artists"<<"\""<<endl;
                    file<<catalog[i].getLine();
                }
            }
        }
        file.close();
    }

    template<class T>
    void File<T>::sortTitle(const string& word){
        fstream file;
        file.open("output.txt",ios::app);

        // Divide lines in catalog entries
        for(int i=0;i<numberOfElements;i++){
            catalog[i].divideLine();
        }

        // Sort catalog based on title using lambda function
        std::sort(catalog.begin(), catalog.end(), 
        [] (const T& obj1, const T& obj2)
        {   
            //cout<<"merhaba"<<endl;
            return (obj1.getTitle() < obj2.getTitle());
        });

        bool check=false;
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){
                if(!check){
                    file<<"sort "<<"\""<<word<<"\""<<endl;
                    check=true;
                }
                file<<catalog[i].getLine()<<endl;
            }
        }
        file.close();
    }

    // Explanation of the other sort functions is similar.
    // Here are the comments for the remaining functions:

    template<class T>
    void File<T>::sortAuthors(const string& word){
        fstream file;
        file.open("output.txt",ios::app);

        // Divide lines in catalog entries
        for(int i=0;i<numberOfElements;i++){
            catalog[i].divideLine();
        }

        // Sort catalog based on authors using lambda function
        std::sort(catalog.begin(), catalog.end(), 
        [] (const T& obj1, const T& obj2)
        {
            return (obj1.getAuthors() < obj2.getAuthors());
        });

        bool check=false;
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){
                if(!check){
                    file<<"sort "<<"\""<<word<<"\""<<endl;
                    check=true;
                }
                file<<catalog[i].getLine()<<endl;
            }
        }
        file.close();
    }


    template<class T>
    void File<T>:: sortDirectors(const string& word){
        fstream file;
        file.open("output.txt",ios::app);
        for(int i=0;i<numberOfElements;i++){
            // Divide lines in catalog entries
            catalog[i].divideLine();
        }
        std::sort(catalog.begin(), catalog.end(), 
        [] (const T& obj1, const T& obj2)
        {
            return (obj1.getDirectors() < obj2.getDirectors());
        }
        );
        bool check=false;
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){
                if(!check){
                    file<<"sort "<<"\""<<word<<"\""<<endl;
                    check=true;
                }
                file<<catalog[i].getLine()<<endl;
            }
        }
        file.close();
    }

    template<class T>
    void File<T>:: sortGenre(const string& word){
        fstream file;
        file.open("output.txt",ios::app);
        for(int i=0;i<numberOfElements;i++){
            // Divide lines in catalog entries
            catalog[i].divideLine();
        }
        std::sort(catalog.begin(), catalog.end(), 
        [] (const T& obj1, const T& obj2)
        {
            return (obj1.getGenre() < obj2.getGenre());
        }
        );
        bool check=false;
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){
                if(!check){
                    file<<"sort "<<"\""<<word<<"\""<<endl;
                    check=true;
                }
                file<<catalog[i].getLine()<<endl;
            }
        }
        file.close();
    }

    template<class T>
    void File<T>:: sortTags(const string& word){
        fstream file;
        file.open("output.txt",ios::app);
        for(int i=0;i<numberOfElements;i++){
            // Divide lines in catalog entries
            catalog[i].divideLine();
        }
        std::sort(catalog.begin(), catalog.end(), 
        [] (const T& obj1, const T& obj2)
        {
            return (obj1.getTags() < obj2.getTags());
        }
        );
        bool check=false;
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){
                if(!check){
                    file<<"sort "<<"\""<<word<<"\""<<endl;
                    check=true;
                }
                file<<catalog[i].getLine()<<endl;
            }
        }
        file.close();
    }

    template<class T>
    void File<T>:: sortYear(const string& word){
        fstream file;
        file.open("output.txt",ios::app);
        
        for(int i=0;i<numberOfElements;i++){
            // Divide lines in catalog entries
            catalog[i].divideLine();
        }
        std::sort(catalog.begin(), catalog.end(), 
        [] (const T& obj1, const T& obj2)
        {
            return (obj1.getYear() < obj2.getYear());
        }
        );
        bool check=false;
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){
                if(!check){
                    file<<"sort "<<"\""<<word<<"\""<<endl;
                    check=true;
                }
                file<<catalog[i].getLine()<<endl;
            }
        }
        file.close();
    }

    // ...

    template<class T>
    void File<T>::sortArtists(const string& word){
        fstream file;
        file.open("output.txt",ios::app);

        // Divide lines in catalog entries
        for(int i=0;i<numberOfElements;i++){
            catalog[i].divideLine();
        }

        // Sort catalog based on artists using lambda function
        std::sort(catalog.begin(), catalog.end(), 
        [] (const T& obj1, const T& obj2)
        {
            return (obj1.getArtists() < obj2.getArtists());
        });

        bool check=false;
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){ // Check the valid or not 
                if(!check){
                    file<<"sort "<<"\""<<word<<"\""<<endl;
                    check=true;
                }
                file<<catalog[i].getLine()<<endl;
            }
        }
        file.close();
    }

    template<class T>
    void File<T>:: sortStarrings(const string& word){
        fstream file;
        file.open("output.txt",ios::app);
        for(int i=0;i<numberOfElements;i++){
            // Divide lines in catalog entries
            catalog[i].divideLine();
        }
        std::sort(catalog.begin(), catalog.end(), 
        [] (const T& obj1, const T& obj2)
        {
            return (obj1.getStarrings() < obj2.getStarrings());
        }
        );
        bool check=false;
        for(int i=0;i<numberOfElements;i++){
            if(catalog[i].isValid()){ // Checking the index of is valid entry or not
                if(!check){ // This print 1 time info
                    file<<"sort "<<"\""<<word<<"\""<<endl;
                    check=true;
                }
                file<<catalog[i].getLine()<<endl;
            }
        }
        file.close();
    }

    template<class T>
    void File<T>::checkCommands(){
        fstream file;
        file.open("commands.txt",ios::in);
        string str;
        fstream file2;
        file2.open("output.txt",ios::app);

        while(file>>str){
            if(str=="search"){
                file>>str;
                string word;
                string from;
                
                // Extract the search keyword from double quotes
                for(int i=1;i<str.length()-1;i++){
                    word+=str[i];
                }
                
                file>>str; // getting "in" word
                file>>str;
                
                // Extract the search category from double quotes
                for(int i=1;i<str.length()-1;i++){
                    from+=str[i];
                }
                    if(from=="title"){
                        searchTitle(word);
                    }
                    else if(from=="authors"){
                        searchAuthors(word);
                    }
                    else if(from=="director"){
                        searchDirectors(word);
                    }
                    else if(from=="genre"){
                        searchGenre(word);
                    }
                    else if(from=="tags"){
                        searchTags(word);
                    }
                    else if(from=="year"){
                        searchYear(word);   
                    }
                    else if(from=="artists"){
                        searchArtists(word);
                    }
                    else if(from=="starrings"){
                        searchStarrings(word);
                    }
                    else{
                        try{
                            throw WrongCommandException("search",word,from);
                        }
                        catch(WrongCommandException& obj){

                        }
                    }
            
            }
            else if(str=="sort"){
                file>>str;
                string word;
                
                // Extract the sort category from double quotes
                for(int i=1;i<str.length()-1;i++){
                    word+=str[i];
                }
                

                    if(word=="title"){
                        sortTitle(word);
                    }
                    else if(word=="authors"){
                        sortAuthors(word);
                    }
                    else if(word=="director"){
                        sortDirectors(word);
                    }
                    else if(word=="genre"){
                        sortGenre(word);
                    }
                    else if(word=="tags"){
                        sortTags(word);
                    }
                    else if(word=="year"){
                        sortYear(word);
                    }
                    else if(word=="artists"){
                        sortArtists(word);
                    }
                    else if(word=="starrings"){
                        sortStarrings(word);
                    }
                    else{
                        try{
                            throw WrongCommandException("sort",word,"");
                        }
                        catch(WrongCommandException& obj){

                        }
                    }
                
                
            }
        }
        file.close();
        file2.close();
    }

}

#endif
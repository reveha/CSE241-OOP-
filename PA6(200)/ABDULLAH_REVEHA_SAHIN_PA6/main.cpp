#include <iostream>
#include <fstream>
#include <vector>
#include "File.h"
#include "Catalog.h"
#include "Music.h"
#include "Movie.h"
#include "Book.h"


using namespace std;
using namespace Cat;

int getType(){
    fstream file;
    file.open("data.txt",ios::in);
    string str;
    file>>str;
    if(str[0]=='b'){
        return 1;
    }
    else if(str[1]=='u'){
        return 2;
    }
    else if(str[1]=='o'){
        return 3;
    }
    return 4;
}

int main(){

    if(getType()==1){
        File<Book> obj;
        obj.readData();
        obj.setQuotes();
        obj.writeFile();
    }
    else if(getType()==2){
        File<Music> obj;
        obj.readData();
        obj.setQuotes();
        obj.writeFile();
    }
    else if(getType()==3){
        File<Movie> obj;
        obj.readData();
        obj.setQuotes();
        obj.writeFile();
    }
    
    
    
    
    return 0;

}
#include "File.h"

template<class T>
File<T>:: File(){
    
}

template<class T>
File<T>:: File(T catalog, string catalogName){
    this->catalog=catalog;
    this->catalogName=catalogName;
}

template<class T>
File<T>:: ~File(){
    delete catalog;
}

template<class T>
void File<T>:: readData(){
    fstream file;
    file.open("data.txt",ios::in);
    file>>catalogName;
    string temp;
    while(!eof(file)){
        getline(file,temp);
        catalog->addLine(temp);
    }
}

template<class T>
void File<T>:: writeFile(){
    fstream file;
    file.open("output.txt",ios::out);
    file<<catalogName<<endl;
    for(auto i:catalog.getLine()){
        file<<i<<endl;
    }
}
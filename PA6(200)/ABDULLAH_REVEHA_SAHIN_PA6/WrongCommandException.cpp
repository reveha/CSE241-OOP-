#include "WrongCommandException.h"

using namespace std;

namespace Cat{
    WrongCommandException:: WrongCommandException(const string type, const string word, const string from){
        fstream file;
        file.open("output.txt",ios::app);
        file<<"Exception: command is wrong"<<endl;
        if(type=="search"){
            file<<"search "<<"\""<<word<<"\""<<" in "<<"\""<<from<<"\""<<endl;
        }
        else{
            file<<"sort "<<"\""<<word<<"\""<<endl;
        }
        file.close();
    }
}
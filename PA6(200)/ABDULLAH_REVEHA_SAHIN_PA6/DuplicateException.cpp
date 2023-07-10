#include "DuplicateException.h"

using namespace std;

namespace Cat{
    DuplicateException::DuplicateException(){
        
    }
    void DuplicateException:: print(){
        fstream file;
        file.open("output.txt",ios::app);
        file<<"Exception: duplicate entry"<<endl;
        file.close();
    }
}



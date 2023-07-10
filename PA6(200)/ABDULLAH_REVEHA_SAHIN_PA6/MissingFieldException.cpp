#include "MissingFieldException.h"


using namespace std;

namespace Cat{
    MissingFieldException::MissingFieldException(){
 
    }
    void MissingFieldException:: print(){
        fstream file;
        file.open("output.txt",ios::app);
        file<<"Exception: missing field"<<endl;
        file.close();
    }
}


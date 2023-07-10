#ifndef MISSINGFIELDEXCEPTION_H
#define MISSINGFIELDEXCEPTION_H

#include <exception>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


namespace Cat{
    class MissingFieldException : public std::exception {
    public:
        MissingFieldException();
        void print();
    };
}

#endif // MISSINGFIELDEXCEPTION_H

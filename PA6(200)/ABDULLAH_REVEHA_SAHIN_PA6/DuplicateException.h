#ifndef DUPLICATEEXCEPTION_H
#define DUPLICATEEXCEPTION_H

#include <exception>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

namespace Cat{
    class DuplicateException : public std::exception {
    public:
        DuplicateException();
        void print();
    };
}

#endif // DUPLICATEEXCEPTION_H

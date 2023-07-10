#ifndef WRONGCOMMANDEXCEPTION_H
#define WRONGCOMMANDEXCEPTION_H

#include <exception>
#include <fstream>
#include <iostream>
using namespace std;

namespace Cat{
    class WrongCommandException : public std::exception{
    public:
        WrongCommandException(const string type, const string word, const string from);
    };

}
#endif // WRONGCOMMANDEXCEPTION_H

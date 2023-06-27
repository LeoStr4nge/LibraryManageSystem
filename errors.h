#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>

using namespace std;

class fileError: public exception
{
public:
    fileError(string msg): errorMsg(msg){};
    virtual const char* what() const noexcept override {return errorMsg.c_str();}
private:
    string errorMsg;
};

#endif // ERRORS_H

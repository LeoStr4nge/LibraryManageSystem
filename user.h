#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;

class user
{
public:
    void addToFile();
    void searchInFile();
    user(string account,string password):account(account),password(password){}
private:
    string account;
    string password;
};

#endif // USER_H

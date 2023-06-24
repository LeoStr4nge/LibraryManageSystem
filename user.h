#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;

class User
{
private:
    string _phone;//电话
    string _password;//密码
public:
    User() {};
    void Registers(string setAccount, string setPassword);//注册
    void Login();//登录
    void save();//保存
    void read();//读取

};


#endif // USER_H

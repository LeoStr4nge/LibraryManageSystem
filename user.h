#ifndef USER_H
#define USER_H
#include<iostream>
#include<QString>
using namespace std;

class User
{
private:
    string _phone;//电话
    string _password;//密码
    string _studentID;//学号
    string _name;//姓名
    friend class borrow;

public:
    User() {};
    int Registers(string setAccount, string setPassword,string setStudentID,string setName);//注册
    int Login(string setAccount, string setPassword);//登录
    void save();//保存
    void read();//读取
    void edit(string name,string phone,string studentID,string password);//修改
    void logout();//注销
    QString qName();
    QString qPhone();
    QString qStudentID();
    string stdPassword();

};


#endif // USER_H

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
    string _xuehao;//学号
    string _xingming;//姓名

public:
    User() {};
    int Registers(string setAccount, string setPassword,string setXuehao,string setXingming);//注册
    int Login(string setAccount, string setPassword);//登录
    void save();//保存
    void read();//读取
    void edit(string name,string phone,string studentID,string password);//修改
    void zhuxiao();//注销
    QString qName();
    QString qPhone();
    QString qStudentID();
    string stdPassword();

};


#endif // USER_H

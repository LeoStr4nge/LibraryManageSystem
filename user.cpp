#include"iostream"
#include"fstream"
#include"string"
#include<conio.h>
#include"vector"
#include"user.h"
#include"QDebug"
using namespace std;
int userCount = 0;


vector<User>vecuser;
User CEO;


//保存
void User::save()
{
    ofstream ofile;
    ofile.open("user.txt", ios::out);

    for (int i = 0; i < vecuser.size(); i++)
    {
        ofile <<vecuser[i]._phone << endl;
        ofile <<vecuser[i]._password << endl;
    }
    ofile.close();
}



//读取
void User::read()
{
    vecuser.clear();
    ifstream ifile;
    ifile.open("user.txt", ios::in);
    User tempUser;
    userCount = 0;


    if (!ifile.is_open())
    {
        //cout << "文件打开失败！" << endl;
        return ;
    }

    for (int i = 0; ifile>>tempUser._phone; i++)
    {

        ifile >> tempUser._password;
        vecuser.push_back(tempUser);
        cout<<vecuser[i]._phone;
        userCount++;
    }
    userCount--;
    ifile.close();
}

//注册
void User::Registers(string setAccount, string setPassword)
{
    CEO.read();
    User tempUser;
    string pw1;
    string pw2;


    for (int i = 0; i <vecuser.size(); i++)
    {
        if (setAccount == vecuser[i]._phone)
        {
            qDebug("用户已注册");
        }
    }
    tempUser._phone = setAccount;
    tempUser._password = setPassword;
    vecuser.push_back(tempUser);
    cout<<vecuser[0]._phone;

}

//登录
int User::Login(string setAccount,string setPassword)
{
    CEO.read();
    User tempUser;
    tempUser._phone = setAccount;
    tempUser._password = setPassword;
    int flag=1;
    for (int i = 0; i < vecuser.size(); i++)
    {
        if (vecuser[i]._phone == tempUser._phone)
        {
            flag=0;
            if (vecuser[i]._password==tempUser._password)
            {
                //登陆成功
                qDebug("登陆成功");
                //返回1
                return 1;
            }
            else
            {
                //登录失败
                qDebug("密码错误");
                //返回0
                return 0;

            }

        }

    }
    if(flag)
    {
    //用户名未注册
    qDebug("用户未注册");
    //返回-1
    return -1;
    }
}

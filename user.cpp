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
        ofile <<vecuser[i]._xuehao<<endl;
        ofile <<vecuser[i]._xingming<<endl;
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
        ifile >> tempUser._xuehao;
        ifile >> tempUser._xingming;
        vecuser.push_back(tempUser);

        userCount++;
    }
    userCount--;
    ifile.close();
}

//注册
void User::Registers(string setAccount, string setPassword,string setXuehao,string setXingming)
{
    CEO.read();
    User tempUser;

    for (int i = 0; i <vecuser.size(); i++)
    {
        if (setAccount == vecuser[i]._phone)
        {
            qDebug("用户已注册");
        }
    }

    tempUser._phone = setAccount;
    tempUser._password = setPassword;
    tempUser._xuehao=setXuehao;
    tempUser._xingming=setXingming;

    vecuser.push_back(tempUser);


}

//登录
int User::Login(string setAccount, string setPassword)
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
                //获取信息
                tempUser._xuehao=vecuser[i]._xuehao;
                tempUser._xingming=vecuser[i]._xingming;
                CEO=tempUser;
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


//修改
void User::xiugai()
{
    CEO.read();
    User tempUser;
    tempUser=CEO;
    for (int i = 0; i < vecuser.size(); i++)
    {
        if (vecuser[i]._phone == tempUser._phone)
        {

            vecuser[i]=tempUser;
        }
    }

}

//注销
void User::zhuxiao()
{
    CEO.read();
    User tempUser;
    tempUser=CEO;
    for (int i = 0; i < vecuser.size(); i++)
    {
        if (vecuser[i]._phone == tempUser._phone)
        {
            //删除该元素


        }
    }

}

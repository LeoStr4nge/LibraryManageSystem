#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
#include "vector"
using namespace std;
int userCount = 0;

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

        }
    }
    tempUser._phone = setAccount;
    tempUser._password = setPassword;
    vecuser.push_back(tempUser);
    cout<<vecuser[0]._phone;

}


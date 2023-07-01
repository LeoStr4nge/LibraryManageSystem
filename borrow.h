#ifndef BORROW_H
#define BORROW_H
#include"iostream"
#include"user.h"
#include"book.h"
#include"fstream"
#include"date.h"
using namespace std;

extern vector<User>vecuser;
extern vector<book>vecbook;
extern book bookCEO;
extern User CEO;


struct jie
{
    int y;
    int m;
    int d;
    int jieyuetime;
};

class borrow
{
public:
    int jieshu(string setReader,string setISBN,Date d,int jieyueshijian);//借书
    int huanshu(string setReader,string setISBN,Date d);//还书
    void save();//保存
    void read();//读取 //读取以后存在vecbor里，管理员直接调取vecbor可以看全部的借书
    vector<string> gerenjieshuxinxi(string setReader);
    int xvjie(string setISBN,int xvjieshijian);
    Date huanshuriqi(Date jieshuday,int jieyueshijian);
    Date jieshuriqi(borrow x);
    vector<int> getBorrowID(string setReader);
    int getBorrowTime();

    vector<string> getReader();//获取全部读者
    vector<string> getBookname();//获取全部书名
    vector<string> getJieshuday();//获取全部借书日期
    vector<string> getHuanshuday();//获取全部还书日期

    int getJienum();//获取借阅数
    int getAllnum();//获取总图书数
    string haveISBN2jieshuday(string setISBN);//根据ISBN获取借书日期
    string haveISBN2huanshuday(string setISBN);//根据ISBN获取还书日期

private:
    string _reader;
    string _readerISBN;
    jie _shu;


};

#endif // BORROW_H

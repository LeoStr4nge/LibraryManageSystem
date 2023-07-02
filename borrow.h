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


struct structBorrow
{
    int y;
    int m;
    int d;
    int borrowTime;
};

class borrow
{
public:
    int borrowBook(string setReader,string setISBN,Date d,int jieyueshijian);//借书
    int returnBook(string setReader,string setISBN,Date d);//还书
    void save();//保存
    void read();//读取 //读取以后存在vecbor里，管理员直接调取vecbor可以看全部的借书
    vector<string> borrower2ISBN(string setReader);
    int renewBook(string setISBN,int xvjieshijian);
    Date returnBookDate(Date jieshuday,int jieyueshijian);
    Date borrowBookDate(borrow x);
    vector<int> getBorrowID(string setReader);
    int getBorrowTime();

    vector<string> getReaders();//获取全部读者
    vector<string> getBooknames();//获取全部书名
    vector<string> getBorrowBookDates();//获取全部借书日期
    vector<string> getReturnBookDates();//获取全部还书日期

    int getBorrowCount();//获取借阅数
    string ISBN2BorrowDate(string setISBN);//根据ISBN获取借书日期
    string ISBN2ReturnBookDates(string setISBN);//根据ISBN获取还书日期

private:
    string _reader;
    string _readerISBN;
    structBorrow _book;


};

#endif // BORROW_H

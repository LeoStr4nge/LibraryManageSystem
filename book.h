#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<QString>
using namespace std;

class book
{
public:


    void save();
    void read();
    int add(string setBookname,string setZuozhe,string setCubanshe,string setISBN,string setLeibei,int setGotime);
    void del(string setISBN);
    void xiugai(string setBookname, string setZuozhe, string setCubanshe, string setISBN, string setLeibei, int setGotime);
    string sousuo(string sousuoci);
    QString qBookname();
    QString qZuozhe();
    QString qChubanshe();
    QString qISBN();
    QString qLeibei();
    int qgotmie();



private:
    string _bookName;
    string _zuozhe;
    string _chubanshe;
    string _ISBN;
    string _leibei;
    int _gotmie;

};

#endif // BOOK_H

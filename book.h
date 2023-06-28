#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<QString>
#include<vector>
using namespace std;

class book
{
public:


    void save();
    void read();
    int add(string setBookname,string setZuozhe,string setCubanshe,string setISBN,string setLeibei,int setGotime);
    void del(string setISBN);
    void xiugai(string setBookname, string setZuozhe, string setCubanshe, string setISBN, string setLeibei, int setGotime);
    vector<int> sousuo(string sousuoci);
    QString qBookname();
    QString qAuthor();
    QString qPublisher();
    QString qISBN();
    QString qType();
    int qGotime();



private:
    string _bookName;
    string _zuozhe;
    string _chubanshe;
    string _ISBN;
    string _leibie;
    int _gotime;

};

#endif // BOOK_H

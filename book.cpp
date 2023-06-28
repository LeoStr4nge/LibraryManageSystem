#include "book.h"
#include"iostream"
#include"fstream"
#include"string"
#include<conio.h>
#include"vector"
#include"user.h"
#include"QDebug"
#include"errors.h"

vector<book>vecbook;
book bookCEO;

//保存
void book::save()
{
    ofstream ofile;
     ofile.open("book.txt", ios::out);

    for (int i = 0; i < vecbook.size(); i++)
    {
        ofile <<vecbook[i]._bookName<< endl;
        ofile <<vecbook[i]._zuozhe << endl;
        ofile <<vecbook[i]._chubanshe<<endl;
        ofile <<vecbook[i]._ISBN<<endl;
        ofile <<vecbook[i]._leibie << endl;
        ofile << vecbook[i]._gotime << endl;
    }
    ofile.close();
}

//读取
void book::read()
{
    vecbook.clear();
    ifstream ifile;
    ifile.open("book.txt", ios::in);
    book tempBook;



    for (int i = 0; ifile >> tempBook._bookName; i++)
    {

        ifile >> tempBook._zuozhe;
        ifile >> tempBook._chubanshe;
        ifile >> tempBook._ISBN;
        ifile >> tempBook._leibie;
        ifile >> tempBook._gotime;
        vecbook.push_back(tempBook);

    }

    ifile.close();
}

//添加
int book::add(string setBookname, string setZuozhe, string setCubanshe, string setISBN, string setLeibie, int setGotime)
{
    book tempBook;

    for (int i = 0; i < vecbook.size(); i++)
    {
        if (setBookname == vecbook[i]._bookName)
        {
            qDebug("该书籍已存在");
            return 0;
        }
    }

    tempBook._bookName = setBookname;
    tempBook._zuozhe = setZuozhe;
    tempBook._chubanshe = setCubanshe;
    tempBook._ISBN = setISBN;
    tempBook._leibie = setLeibie;
    tempBook._gotime = setGotime;

    vecbook.push_back(tempBook);
    bookCEO.save();
    qDebug("书籍添加成功");
    return 1;
}

//删除
void book::del(string setISBN)
{
    bookCEO.read();
    vector<book>::iterator it;


    for (it = vecbook.begin(); it != vecbook.end(); it++)
    {

        if ( it->_ISBN==setISBN  )
        {
            //删除该元素
            vecbook.erase(it);
            bookCEO.save();
        }
    }
}

//修改
void book::xiugai(string setBookname, string setZuozhe, string setCubanshe, string setISBN, string setLeibei, int setGotime)
{
    book tempUser;
    tempUser._bookName = setBookname;
    tempUser._zuozhe = setZuozhe;
    tempUser._chubanshe = setCubanshe;
    tempUser._ISBN = setISBN;
    tempUser._leibie = setLeibei;
    tempUser._gotime = setGotime;

    for (int i = 0; i < vecbook.size(); i++)
    {
        if (vecbook[i]._ISBN == tempUser._ISBN)
        {

            vecbook[i] = tempUser;
            bookCEO.save();
        }
    }

}


//搜索
string book::sousuo(string sousuoci)
{
    for (int i = 0; i < vecbook.size(); i++)
    {
        if (vecbook[i]._bookName==sousuoci)
        {
            return vecbook[i]._ISBN;
        }

    }

    for (int i = 0; i < vecbook.size(); i++)
    {
        if (vecbook[i]._chubanshe == sousuoci)
        {
            return vecbook[i]._ISBN;
        }

    }

    for (int i = 0; i < vecbook.size(); i++)
    {
        if (vecbook[i]._ISBN == sousuoci)
        {
            return vecbook[i]._ISBN;
        }

    }

    for (int i = 0; i < vecbook.size(); i++)
    {
        if (vecbook[i]._leibie == sousuoci)
        {
            return vecbook[i]._ISBN;
        }

    }

    for (int i = 0; i < vecbook.size(); i++)
    {
        if (vecbook[i]._zuozhe == sousuoci)
        {
            return vecbook[i]._ISBN;
        }

    }


}


//返回信息函数
QString book::qBookname(){return QString::fromStdString(_bookName);}
QString book::qZuozhe(){return QString::fromStdString(_zuozhe);};
QString book::qChubanshe(){return QString::fromStdString(_chubanshe);};
QString book::qISBN(){return QString::fromStdString(_ISBN);};
QString book::qLeibei(){return QString::fromStdString(_leibie);};
int book::qgotmie(){return _gotime;};


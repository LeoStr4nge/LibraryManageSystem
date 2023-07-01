#include "borrow.h"


vector<borrow>vecbor;
borrow borCEO;


void borrow::save()
{
    ofstream ofile;
    ofile.open("borrow.txt", ios::out);

    for (int i = 0; i < vecbor.size(); i++)
    {
        ofile <<vecbor[i]._reader << endl;
        ofile <<vecbor[i]._readerISBN<<endl;
        ofile <<vecbor[i]._shu.y<< endl;
        ofile <<vecbor[i]._shu.m<< endl;
        ofile <<vecbor[i]._shu.d<< endl;
        ofile <<vecbor[i]._shu.jieyuetime<< endl;

    }
    ofile.close();
}


void borrow::read()
{
    vecbor.clear();
    ifstream ifile;
    ifile.open("borrow.txt", ios::in);
    borrow tempBor;
    for (int i = 0; ifile >> tempBor._reader; i++)
    {

        ifile >> tempBor._readerISBN;
        ifile >> tempBor._shu.y;
        ifile >> tempBor._shu.m;
        ifile >> tempBor._shu.d;
        ifile >> tempBor._shu.jieyuetime;

        vecbor.push_back(tempBor);

    }

    ifile.close();
}

int borrow::jieshu(string setReader,string setISBN,Date d,int jieyueshijian)
{
    borCEO.read();
    borrow tempBor;
    for(int i=0;i<vecbook.size();i++)
    {
        if(setISBN==vecbook[i]._ISBN)
        {
            if(vecbook[i]._flagExist==1)
            {
                tempBor._reader=setReader;
                tempBor._readerISBN=setISBN;
                tempBor._shu.y=d.year;
                tempBor._shu.m=d.month;
                tempBor._shu.d=d.day;
                tempBor._shu.jieyuetime=jieyueshijian;
                vecbor.push_back(tempBor);
                vecbook[i]._flagExist=0;
                bookCEO.save();
                qDebug("借书成功");
                borCEO.save();
                return 1;
            }else
            {
                qDebug("该书已被借出，不在馆内");
                return 0;
            }
        }

    }



}

int borrow::huanshu(string setReader,string setISBN,Date d)
{
    borCEO.read();
    vector<borrow>::iterator it;
    for(it=vecbor.begin();it!=vecbor.end();it++)
    {
        if(it->_reader==setReader&&it->_readerISBN==setISBN)
        {
            for(int j=0;j<vecbook.size();j++)
            {
                if(vecbook[j]._ISBN==setISBN)
                {
                    vecbook[j]._flagExist=1;
                    qDebug("图书放入馆内");
                }
            }
            vecbor.erase(it);
            borCEO.save();
            bookCEO.save();
            qDebug("还书成功");
            return 1;
        }
    }
}

vector<string> borrow::gerenjieshuxinxi(string setReader)
{
    borCEO.read();
    vector<string> result;


    for (int i = 0; i < vecbor.size(); i++)
    {
        if (vecbor[i]._reader==setReader)
        {
            result.push_back(vecbor[i]._readerISBN);
        }

    }

    return result;
}

int borrow::xvjie(string setISBN,int xvjieshijian)
{
    borCEO.read();
    for(int i=0;i<vecbor.size();i++)
    {
        if(setISBN==vecbor[i]._readerISBN)
        {
            vecbor[i]._shu.jieyuetime+=xvjieshijian;
            borCEO.save();
            qDebug("续借成功");
            return 1;
        }

    }
    qDebug("续借失败，未找到图书");
    return 0;

}

vector<int> borrow::getBorrowID(string setReader)
{
    borCEO.read();
    vector<int> result;
    for (int i = 0; i < vecbor.size(); i++)
    {
        if (vecbor[i]._reader==setReader)
        {
            result.push_back(i);
        }

    }
    return result;
}


//计算还书日期
Date borrow::huanshuriqi(Date jieshuday,int jieyueshijian)
{
    Date huanshuday;
    huanshuday = jieshuday + jieyueshijian;
    return huanshuday;
}

//获取借书日期类
Date borrow::jieshuriqi(borrow x)
{
    Date jieshuday;
    jieshuday.year=x._shu.y;
    jieshuday.month=x._shu.m;
    jieshuday.day=x._shu.d;
    return jieshuday;

}

//获取借书时间
int borrow::getBorrowTime(){
    return this->_shu.jieyuetime;
}


//获取全借书人
vector<string> borrow::getReader()
{
    vector<string> readerName;
    for(int i=0;i<vecbor.size();i++)
    {
        readerName.push_back(vecbor[i]._reader);
    }
    return readerName;
}

//获取全书名
vector<string> borrow::getBookname()
{
    vector<string> temp;
    for(int i=0;i<vecbor.size();i++)
    {
        int j;
        j=bookCEO.exactSearch(vecbor[i]._readerISBN);
        temp.push_back(vecbook[j]._bookName);
    }
    return temp;
}


//获取全借书日期

vector<string> borrow::getJieshuday()
{
    vector<string> temp;
    string a;
    for(int i=0;i<vecbor.size();i++)
    {
        a=to_string(vecbor[i]._shu.y)+"年"+to_string(vecbor[i]._shu.m)+"月"+to_string(vecbor[i]._shu.d)+"日";
        temp.push_back(a);
    }
    return temp;
}

//获取全还书日期
vector<string> borrow::getHuanshuday()
{
    vector<string> temp;
    Date d1,d2;
    string a;
    for(int i=0;i<vecbor.size();i++)
    {
        d1.day=vecbor[i]._shu.d;
        d1.month=vecbor[i]._shu.m;
        d1.year=vecbor[i]._shu.y;
        d2=d1+vecbor[i]._shu.jieyuetime;
        a=to_string(d2.year)+"年"+to_string(d2.month)+"月"+to_string(d2.day)+"日";
        temp.push_back(a);
    }
    return temp;
}
//获取借阅数
int borrow::getJienum()
{
    return vecbor.size();
}
//获取总图书数
int getAllnum()
{
    return vecbook.size();
}

//根据ISBN获取借书日期
string borrow::haveISBN2jieshuday(string setISBN)
{
    borCEO.read();
    Date d1,d2;
    string a;
    for(int i=0;i<vecbor.size();i++)
    {
        if(setISBN==vecbor[i]._readerISBN)
        {
            d1.day=vecbor[i]._shu.d;
            d1.month=vecbor[i]._shu.m;
            d1.year=vecbor[i]._shu.y;
            a=to_string(d1.year)+"年"+to_string(d1.month)+"月"+to_string(d1.day)+"日";
            return a;
        }
    }
}

//根据ISBN获取还书日期
string borrow::haveISBN2huanshuday(string setISBN)
{
    borCEO.read();
    Date d1,d2;
    string a;
    for(int i=0;i<vecbor.size();i++)
    {
        if(setISBN==vecbor[i]._readerISBN)
        {
            d1.day=vecbor[i]._shu.d;
            d1.month=vecbor[i]._shu.m;
            d1.year=vecbor[i]._shu.y;
            d2=d1+vecbor[i]._shu.jieyuetime;
            a=to_string(d2.year)+"年"+to_string(d2.month)+"月"+to_string(d2.day)+"日";
            return a;
        }
    }
}

#include "borrow.h"


vector<borrow>vecbor;
borrow borCEO;

void borrow::save()
{
    ofstream ofile;
    ofile.open("borrow.txt", ios::out);

    for (int i = 0; i < vecbor.size(); i++)
    {
        ofile << vecbor[i]._reader << endl;
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
                tempBor._shu.y=d.day;
                tempBor._shu.m=d.month;
                tempBor._shu.d=d.day;
                tempBor._shu.jieyuetime=jieyueshijian;
                vecbor.push_back(tempBor);
                vecbook[i]._flagExist=0;

                qDebug("借书成功");
                borCEO.save();
                return 1;
            }else
            {
                qDebug("该书已被借出，不在馆内");
                return 0;
            }
        }else
        {
            qDebug("借书失败");
            return -1;
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

            qDebug("还书成功");
            return 1;
        }else
        {
            qDebug("还书失败");
            return 0;
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




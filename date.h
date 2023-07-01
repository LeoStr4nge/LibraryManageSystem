#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<ctime>
using namespace std;

extern int _nowYear;
extern int _nowMonth;
extern int _nowDay;

class Date
{
public:
    Date(int y=_nowYear, int m=_nowMonth, int d=_nowDay);
    friend int add(int day);
    int year;
    int month;
    int day;
    int leap(int);
    int md2d(int leap, int month, int day);


    //某日期加上天数
    Date operator+(int days);
private:
    int y2d(int year)
    {
        return 365 + leap(year);
    }

};

#endif // DATE_H

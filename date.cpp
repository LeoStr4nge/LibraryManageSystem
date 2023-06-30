#include "date.h"

const int day_tab[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31} };

int Date::leap(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int Date::md2d(int leap, int month, int day)
{
    for (int i = month - 2; i >= 0; i--)
    {
        day += day_tab[leap][i];
    }
    return day;
}

Date::Date(int y, int m, int d)
{
    year = y; month = m; day = d;
}


Date Date::operator+(int days)
{
    days += md2d(leap(year), month, day);
    //0<days<=365+leap
    int y = year;
    while (days > y2d(y))
    {
        days -= y2d(y);
        y++;
    }
    while (days <= 0)
    {
        y--;
        days += y2d(y);
    }
    //d2md
    int m = 1;
    int d1;
    while ((d1 = days - day_tab[leap(y)][m - 1]) > 0)
    {
        days = d1;
        m++;
    }
    Date dt(y, m, days);
    return dt;
}

void add(int day)
{

    Date d1(2003,3,23);
    cout << "加上天数";

    Date d2 = d1 + day;
    cout <<  d2.day<< endl;
}

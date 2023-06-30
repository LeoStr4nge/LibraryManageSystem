#ifndef DATE_H
#define DATE_H


class Date
{
public:
    Date(int y, int m, int d);
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

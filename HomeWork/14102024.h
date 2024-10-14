#ifndef DATETIME_H
#define DATETIME_H

#include <bits/stdc++.h>
using namespace std;
class Date {
    protected:
        int day, month, year;
    public:
        Date(int, int, int);
        ~Date();
        Date operator ++ ();
        Date operator -- ();
        friend ostream &operator << (ostream &out, const Date& d);
        friend istream &operator >> (istream &in, Date &d);
};
class Time {
    protected:
        int hour, minute, second;
    public:
        Time(int, int, int);
        ~Time();
        Time operator ++ ();
        Time operator -- ();
        friend ostream &operator << (ostream &out, const Time& t);
        friend istream &operator >> (istream &in, Time &t);
};
class DateTime : public Date, public Time {
    public:
        DateTime(int day = 0, int month = 0, int year = 0, int hour = 0, int minute = 0, int second = 0);
        ~DateTime();
        DateTime operator ++ ();
        DateTime operator -- ();
        friend ostream &operator << (ostream &out, const DateTime &dt);
        friend istream &operator >> (istream &in, DateTime &dt);
};
#endif
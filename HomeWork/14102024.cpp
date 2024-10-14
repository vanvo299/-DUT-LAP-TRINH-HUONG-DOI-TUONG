#include <D:\CODE\DUT\KÌ 1 2425 DUT\Lập trình hướng đối tượng (OOP)\HomeWork\14102024.h>

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date() {};

bool checkNam(int year) 
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        // Là năm nhuận
        return true;
    }  
    // Không phải là năm nhuận
    return false;
}

Date Date::operator ++ ()
{
    day++;
        // Kiem tra so ngay trong cac thang
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            // thang co 31 ngay
            if (day > 31) {
                day = 1;
                month++;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            // thang co 30 ngay
            if (day > 30) {
                day = 1;
                month++;
            }
        }
        else if (month == 2) {
            if (checkNam(year)) {
                // nam nhuan
                if (day > 29) {
                    day = 1;
                    month++;
                }
            } 
            else {
                // namm khong la nam nhuan
                if (day > 28) {
                    day = 1;
                    month++;
                }
            }
        }
    if (month > 12) {
        month = 1;
        year++;
    }
    return *this;
}

Date Date::operator --()
{
    day--;

    if (day < 1) {
        month--;
    }

    if (month < 1) {
        month = 12;
        year--;
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day < 1) {
            day = 31;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1) {
            day = 30;
        }
    }
    else if (month == 2) {
        if (checkNam(year)) {
            // nam nhuan
            if (day < 1) {
                day = 29;

            }
        }
        else {
            // nam khong nhuan
            if (day < 1) {
                day = 28;

            }
        }
    }
    return *this;
}

istream& operator >> (istream &in, Date &d)
{
    cout << "Enter the day: ";
    in >> d.day;
    cout << "Enter the month: ";
    in >> d.month;
    cout << "Enter the year: ";
    in >> d.year;
    if (d.day <= 0 || d.month <= 0 || d.month > 12 || d.year <= 0) {
            cout << "Invalid date!" << endl;
            exit(1);
    }
    if (d.month == 2) {
            if (checkNam(d.year)) {
                // la nam nhuan
                if (d.day > 29) {
                    cout << "Invalid d!" << endl;
                    exit(1);
                }
            }
            else {
                // khong phai nam nhuan
                if (d.day > 28) {
                    cout << "Invalid d!" << endl;
                    exit(1);
                }
            }
        }

        // kiem tra thang nhap vao
        if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) {
            // thang co 31 ngay
            if (d.day > 31) {
                cout << "Invalid d!" << endl;
                exit(1);
            }
        }
        else {
            // thang co 30 ngay
            if (d.day > 30) {
                cout << "Invalid d!" << endl;
                exit(1);
            }
        }
        return in;
    }

ostream &operator << (ostream &out, const Date &d)
{
    cout << "Date: ";
    if (d.day >= 1 && d.day <= 9) cout << "0" << d.day << "/";
        else cout << d.day << "/";
        if (d.month >= 1 && d.month <= 9) 
            cout << "0" << d.month << "/";
        else cout << d.month << "/";
        cout << d.year;
    return out;
} 


Time::Time(int hour, int minute, int second) 
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

Time::~Time() {};

Time Time::operator++ () 
{
    second++;
    if (second > 59) {
        second = 0;
        minute++;
    }
    if (minute > 59) {
        minute = 0;
        hour++;
    }
    if (hour >= 23) {
        hour = 0;
    }
    return *this;
}

Time Time::operator-- () 
{
    second--;
    if (second < 0) {
        second = 59;
        minute--;
    }
    if (minute < 0) {
        hour--;
        minute = 59;
    }
    if (hour < 0) {
        hour = 23;
    }
    return *this;
}

// Toán tử xuất
ostream &operator<<(ostream &out, const Time &t) {
    out << "Time: ";
    out << (t.hour < 10 ? "0" : "") << t.hour << ":"; 
    out << (t.minute < 10 ? "0" : "") << t.minute << ":"; 
    out << (t.second < 10 ? "0" : "") << t.second; 
    return out; 
}

istream &operator >> (istream &in, Time &t) 
{
    cout << "Enter the hour: ";
    in >> t.hour;
    cout << "Enter the minute: ";
    in >> t.minute;
    cout << "Enter the second: ";
    in >> t.second;
    if (t.hour < 0 || t.hour > 23 || t.minute < 0 || t.minute > 59 || t.second < 0 || t.second > 59) {
        cout << "Invalid time !\n";
        exit(1);
    }
    return in;
}

DateTime::DateTime(int day, int month, int year, int hour, int minute, int second) : Date(day, month, year), Time(hour, minute, second)
{

}

DateTime::~DateTime() {}

ostream &operator << (ostream &out, const DateTime &dt)
{
    out << static_cast<const Date&>(dt) << endl << static_cast<const Time&>(dt);
    return out;
}

istream &operator >> (istream &in, DateTime &dt)
{
    cout << "Enter the date\n ";
    in >> static_cast<Date&>(dt);
    cout << "Enter the time\n ";
    in >> static_cast<Time&>(dt);
    return in;
}

DateTime DateTime::operator++() {
    // Tăng giây trước
    Time::operator++(); // Tăng giây
    if (hour == 0 && minute == 0 && second == 0) { // Nếu giờ quay về 0 sau khi tăng
        Date::operator++(); // Tăng ngày
    }
    return *this;
}

DateTime DateTime::operator--() {
    // Giảm giây trước
    Time::operator--(); // Giảm giây
    if (hour == 23 && minute == 59 && second == 59) { // Nếu giờ là 23:59:59 sau khi giảm
        Date::operator--(); // Giảm ngày
    }
    return *this;
}

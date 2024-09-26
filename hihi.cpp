#include <iostream>
#include <cmath>
using namespace std;

struct Date {
    int day;
    int month;
    int year;

    bool checkNam(int year) 
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            // Là năm nhuận
            return true;
        }  
        // Không phải là năm nhuận
        return false;
    }

    Date operator ++ ()
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
    }

    Date operator --()
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
    }

    // Định nghĩa toán tử thành viên <<
    ostream& operator << (ostream &output) const {
        output << day << "/" << month << "/" << year;
        return output;
    }

    // Định nghĩa toán tử thành viên >>
    istream& operator >> (istream &input) {
        input >> day >> month >> year;
        return input;
    }
};


int main()
{
    Date *date = new Date;
    
    // cin >> *date;
    // cout << *date << endl;

    *date >> cin;
    
    // ++(*date);
    // cout << *date << endl;

    --(*date);
    *date << cout;

    delete date;
    return 0;
}
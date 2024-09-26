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

    friend istream& operator >> (istream &input, Date &date) {
        cout << "Enter the day: ";
        input >> date.day;
        cout << "Enter the month: ";
        input >> date.month;
        cout << "Enter the year: ";
        input >> date.year;
        if (date.day <= 0 || date.month <= 0 || date.month > 12 || date.year <= 0) {
            cout << "Invalid date!" << endl;
            exit(1);
        }

        if (date.month == 2) {
            if (date.checkNam(date.year)) {
                // la nam nhuan
                if (date.day > 29) {
                    cout << "Invalid date!" << endl;
                    exit(1);
                }
            }
            else {
                // khong phai nam nhuan
                if (date.day > 28) {
                    cout << "Invalid date!" << endl;
                    exit(1);
                }
            }
        }

        // kiem tra thang nhap vao
        if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) {
            // thang co 31 ngay
            if (date.day > 31) {
                cout << "Invalid date!" << endl;
                exit(1);
            }
        }
        else {
            // thang co 30 ngay
            if (date.day > 30) {
                cout << "Invalid date!" << endl;
                exit(1);
            }
        }
        return input;
    }

    friend ostream& operator << (ostream &output, Date &date)
    {
        cout << "Date: ";
        if (date.day >= 1 && date.day <= 9) cout << "0" << date.day << "/";
        else cout << date.day << "/";
        if (date.month >= 1 && date.month <= 9) 
            cout << "0" << date.month << "/";
        else cout << date.month << "/";
        cout << date.year;
        return output;
    }
};


int main()
{
    Date *date = new Date;
    
    cin >> *date;
    cout << *date << endl;
    
    // ++(*date);
    // cout << *date << endl;

    --(*date);
    cout << *date << endl;

    delete date;
    return 0;
}
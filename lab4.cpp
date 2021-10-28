#include <iostream>
#include <math.h>

using namespace std;

class Date {
    friend ostream& operator<<(ostream& out, Date& ob);
protected:
    int day, month, year, days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
public:
    Date() {
        day = 0;
        month = 0;
        year = 0;
    }
    Date(int Vday, int Vmonth, int Vyear) {
        day = Vday;
        month = Vmonth;
        year = Vyear;
    }

    Date operator + (Date& other) { // дата начала + период строительства = срок сдачи объекта
        Date temp;
        temp.year = year + other.year;
        if (month + other.month > 12) {
            temp.year++;
            temp.month = ((month + other.month) - 12) + 1;
        }
        temp.month = month + other.month;
        if (day + other.day > temp.days[temp.month]) {
            temp.day = ((day + other.day) - temp.days[temp.month]);
            if (temp.month + 1 > 12) {
                temp.month = 1;
            }
            temp.month++;
        }
        temp.day = day + other.day;
        return temp;
    }

    Date operator - (Date& other) { // дата начала = дата сдачи - период строительства
        Date temp;
        if (day - other.day < 0) {
            temp.month--;
            temp.day = temp.days[temp.month] - (abs(day - other.day));
        }
        temp.day = day - other.day;
        if (month - other.month < 0) {
            temp.year--;
            if (12 - abs((month - other.month)) == 0) {
                temp.month = 1;
            }
            temp.month = (12 - abs((month - other.month)));
        }else if(month - other.month == 0) {
            temp.month = 12;
            temp.year--;
        }
        temp.month = month - other.month;
        temp.year = year - other.year;
        return temp;
    }
    
    Date operator +(int nday) {
        Date temp;
        temp.month = month;
        temp.year = year;
        if (day + nday > temp.days[temp.month]) {
            temp.day = ((day + nday) - temp.days[temp.month]);
            if (temp.month + 1 > 12) {
                temp.month = 1;
                temp.year++;
            }
            temp.month++;
        }else temp.day = day + nday;
        return temp;
    }
    
    Date operator -(int nday) {
        Date temp;
        temp.month = month;
        temp.year = year;
        temp.day = day;
        if (day - nday < 0) {
            temp.month--;
            temp.day = temp.days[temp.month] - (abs(day - nday));
        }else temp.day = day - nday;
        return temp;
    }

    Date operator ++(int nday) {
        Date temp;
        temp.month = month;
        temp.year = year;
        temp.day = day;
        if (day + 1 > temp.days[temp.month]) {
            temp.day = ((day + 1) - temp.days[temp.month]);
            if (temp.month + 1 > 12) {
                temp.month = 1;
                temp.year++;
            }
            temp.month++;
        }
        else temp.day = day + 1;
        return temp;
    }

    Date operator --(int nday) {
        Date temp;
        temp.month = month;
        temp.year = year;
        temp.day = day;
        if (day - 1 < 0) {
            temp.month--;
            temp.day = temp.days[temp.month] - (abs(day - 1));
        }
        else temp.day = day - 1;
        return temp;
    }
};

ostream& operator<<(ostream& out, Date& other) {

    return out << other.day << "." << other.month << "." << other.year;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Date start(12, 4, 2010), stroitelstvo(10, 3, 2);
    Date sdachi(24, 8, 2020);
    cout << "Дата начала строительства: " << start << endl;
    cout << "Продолжительность строительства: " << stroitelstvo << endl;
    cout << "Дата сдачи постройки: " << sdachi << endl << endl;

    Date vr = start + stroitelstvo;
    cout << "Дата сдачи: " << vr << endl;
    vr = sdachi - stroitelstvo;
    cout << "Дата начала: " << vr << endl;
    vr = start + 20;
    cout << "Дата + int: " << vr << endl;
    vr = start - 20;
    cout << "Дата - int: " << vr << endl;
    vr = start++;
    cout << "Дата++: " << vr << endl;
    vr = start--;
    cout << "Дата--: " << vr << endl;

}

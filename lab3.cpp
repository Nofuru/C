#include <iostream>

using namespace std;

class goods {
    string Name, Odate;
    double price;
    int kol_vo, number;
public:
    goods() {
        Name = "";
        Odate = "0.0.0";
        price = 0.0;
        kol_vo = 0;
        number = 0;
        cout << "Вызвался конструктор с параметрами" << endl;
    }
    ~goods() {
        cout << "Вызвался деструктор" << endl;
    }
    goods(const goods &a) {
        Name = a.Name;
        Odate = a.Odate;
        price = a.price;
        kol_vo = 0; 
        number = 0;
        cout << "Вызвался конструктор копирования" << endl;
    }
    
    void setName(string vName) {
        Name = vName;
    }
    void setOdate(string vOdate) {
        Odate = vOdate;
    }
    void setprice(double vprice) {
        price = vprice;
    }
    void setkol_vo(int vkol_vo) {
        kol_vo = vkol_vo;
    }
    void setnumber(int vnumber) {
        number = vnumber;
    }
    double getS() {
        double S;
        S = kol_vo* price;
        return S;
    }
};
goods tovar(goods s) {
    return s;
};
void main(void)
{
    setlocale(LC_ALL, "RU");
    cout << "Вход в функцию main()" << endl;
    goods fg;
    goods ass;
    tovar(fg);
    tovar(ass);

    cout << "Выход из функции main()" << endl;
}

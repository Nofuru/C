#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    
    cout << "переход на след строку ->" << endl << "след строка";

    bool log_true = 1;
    cout << boolalpha << log_true << endl; //вывод true || false

    log_true = true;
    cout << noboolalpha << log_true << endl; // теже самые true || false, но цифрами

    int value = 64;
    cout << oct << value << endl; // вывод в восьмеричном виде
    cout << dec << value << endl; // вывод в обычном, десятичном виде
    cout << hex << value << endl; // вывод в шестнадцатеричном виде

    value = 255;
    cout << uppercase << hex << value << endl; // вывод с использованием верхнего регистра
    cout.unsetf(ios::uppercase | ios::hex);

    cout << nouppercase << hex << value << endl; //вывод без использования верхнего регистра (по умолчанию)
    cout.unsetf(ios::hex);

    cout << showpos << value << endl; // добовляет + для положительных чисел
    cout.unsetf(ios::showpos);

    cout << noshowpos << value << endl; // не добавляет + для положительных чисел (по умолчанию)

    double value1 = 1024.165;
    cout << scientific << value1 << endl; // выводит дробные числа в экспоненциальной (научной) форме
    cout.unsetf(ios::scientific);
    cout << fixed << value1 << endl; // вывод по умолчанию

    cout << setw(50) << "123456789" << endl; // устанавливает ширину поля, число в нутри скобок - кол-во знаков(сама ширина)

    cout << setw(50) << right << "123456789" << endl; // right - выравнивает по правой части
                                                      // (если установленная ширина больше, чем введенное число, то все будет видно наглядно)

    cout << setw(50) << left << "123456789" << endl; // так же как и "right", только по левой части (было бы нагляднее видно в выводе, если бы символ заполнитель был не пробел)

    cout << fixed << setprecision(3) << 34.34456789 << endl; // задает кол-во знаков для отображения после запятой (если за последнией(в нашем случае 3) цифрой идет больше 5, то он округляет в большую сторону)
    
    cout << setfill('-') << setw(50) << "123456789" << endl; // если что-то, что выводится больше чем, указанная ширина (setw()), то пустое пространство заполнит символ заполнитель
}
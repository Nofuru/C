#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    
    //Зад 1.
    //На данную цепочку вывода. При одновременно поднятых нескольких флагах происхлдит коллизия, которая решается в пользу десятичной системы.
    // нужно делать unset, чтобы этого избежать.


    //Зад 2.
    //Ничего не обрезается.

    //при выводе setprecision может округлить значение(например, при setprecision(3) при вводе числа 123.5 он окуглит его до 124. 
    //При вводе числа с большим кол-вом знаков он переведет его в экспоненциальный вид оставив одно число в целой части 
    //и два в десятичной(оставит именно столько из-за того, что указано 3 у setprecision))


    //Зад 3.
    float a = 12345.1234567;
    cout.width(12);
    cout << a << "_______" << scientific << a << endl;
    cout.unsetf(ios::scientific);

    cout.setf(ios::left);
    cout.width(12);
    cout.fill('-');
    cout << a << endl;

    cout.setf(ios::right); cout.unsetf(ios::left);
    cout.width(12);
    cout << a << endl << endl << endl;
    cout.unsetf(ios::right);
    cout.fill(' ');

    // магипуляторами
    cout << setw(12) << a << "_______" << scientific << a << endl;
    cout.unsetf(ios::scientific);

    cout << setfill('-') << setw(12) << left << a << endl; 
    cout.unsetf(ios::left);
    cout << setfill('-') << setw(12) << right << a << endl;

    //Зад 3.
}
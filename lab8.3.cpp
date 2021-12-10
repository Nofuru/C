#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	
	cout.setf(ios::boolalpha); // выводит true || false в текстовом виде
	bool log_false = 0, log_true = 1;
	cout << log_false << endl << log_true << endl;
	cout.unsetf(ios::boolalpha); 


	cout.unsetf(ios::dec); // снимаеи флаг dec(десятичную форму вывода)
	cout.setf(ios::oct); // вывод в восьмиричной системе
	int value = 64;
	cout << value << endl;
	cout.unsetf(ios::oct); // снимаем флаг с вывода в восьмиричной системе
	cout.setf(ios::dec); // вывод в десятичной системе счисления (по умолчанию)

	cout.unsetf(ios::dec);
	cout.setf(ios::hex); // вывод в шестнадцатиричной системе
	cout << value << endl;

	cout.unsetf(ios::dec);
	cout.setf(ios::oct | ios::showbase); //показывает основание системы счсления
	cout << value << endl; 

	cout.unsetf(ios::dec);
	cout.setf(ios::hex | ios::uppercase); // выводит "буквы" в верхнем регистре
	cout << value << endl; 
	cout.unsetf(ios::hex | ios::uppercase);

	cout.setf(ios::showpos); // выводит + перед положительными числами
	cout << value << endl;

	cout.setf(ios::scientific); //выводит дробные числа в экспоненциальной (научной) форме
	double value1 = 1024.165;
	cout << value1 << endl;

	cout.unsetf(ios::scientific);
	cout << value1 << endl; // вывод по умолчанию

	cout.width(50);
	cout << "123456789" << endl; // right - выравнивает по правой части (по умолчанию)

	cout.setf(ios::left); //  так же как и "right", только по левой части
	cout.width(50); 
	cout << "123456789" << endl;
	cout.unsetf(ios::left);

	cout.fill('-');
	cout.setf(ios::left);
	cout.width(50); // если что-то, что выводится больше чем, указанная ширина (setw()), то пустое пространство заполнит символ заполнитель
	cout << "123456789" << endl;
	
    //Зад 3
    /*
    cout << endl << endl << setfill('*') << setw(50) << "ex3" << endl;
    //boolalpha, oct, dec, hex, showbase, uppercase, showpos, scientific, fixed, right, left , fill

    cout.setf(ios::hex);
    cout << 12 << endl;
    cout.unsetf(ios::hex);
    */


    //Зад 4.1
    /*
    cout << endl << endl << setfill('*') << setw(50) << "ex4" << endl;
    for (i = 0; i < 7; i++)
        cout << s << endp;
    */

    //Зад 4.2
    /*
    cout << endl << endl << setfill('*') << setw(50) << "ex4.1" << endl;
    for (i = 0; i < 7; i++)
        cout << s << endp(2);
    */
    // work but in theory

    //Зад 4.3
    /*
    cout << endl << endl << setfill('*') << setw(50) << "ex4.1" << endl;
    int f = 2;
    for (i = 0; i < 7; i++)
        cout << s << endp(f,s);
    */
}

#include <iostream>
#include <math.h>
using namespace std;
class complex {
private:
	int re, im;
public:
	complex() {
		re = 0;
		im = 0;
	}
	complex(int re) {
		this->re = re;
		im = 0;
	}
	complex(int re, int im) {
		this->re = re;
		this->im = im;
	}

	complex operator+(const complex& other) {
		complex z1;
		z1.re = this->re + other.re;
		z1.im = this->im + other.im;
		return z1;
	}

	complex operator-(const complex& other) {
		complex z1;
		z1.re = this->re - other.re;
		z1.im = this->im - other.im;
		return z1;
	}
	friend ostream& operator<<(ostream&, complex&);
	friend istream& operator>>(istream&, complex&);
};

ostream& operator<<(ostream& os, complex& complex)
{
	if (complex.im < 0) {
		os << complex.re << " - " << abs(complex.im) << "i";
		return os;
	}
	else if (complex.im == 0) {
		os << complex.re << " + i";
		return os;
	}
	else {
		os << complex.re << " + " << complex.im << "i";
		return os;
	}
}

istream& operator>>(istream& os, complex& complex)
{
	os >> complex.re >> complex.im;
	return os;
}


template <class T>
class matrix {

private:
    T** M; // matrix
    int m; // col-vo str
    int n; // col-vo stlb

public:

    matrix()
    {
        n = m = 0;
    }

    matrix(int _m, int _n)
    {
        m = _m;
        n = _n;

        M = (T**) new T * [m];


        for (int i = 0; i < m; i++)
            M[i] = (T*)new T[n];

        //matrix full 0
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
    }

    void SetMij(int i, int j, T value)
    {
        if ((i < 0) || (i >= m))
            return;
        if ((j < 0) || (j >= n))
            return;
        M[i][j] = value;
    }

    void Print(const char* ObjName)
    {
        cout << "Object: " << ObjName << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << "---------------------" << endl << endl;
    }

    matrix operator=(const matrix& _M)
    {
        if (n > 0)
        {

            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
        {
            delete[] M;
        }

        // coppy data M <= _M
        m = _M.m;
        n = _M.n;

        // memory clean
        M = (T**) new T * [m];
        for (int i = 0; i < m; i++)
            M[i] = (T*) new T[n];

        // copy
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j];
        return *this;


    }

    ~matrix()
    {
        if (n > 0)
        {
            // освободить выделенную память для каждой строки
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
            delete[] M;
    }
};

#pragma endregion

#pragma region Ex3
template <typename T> class Stack
{
    T* stackPtr;
    int size; 
    T top;

public:
    Stack(int = 10);

    ~Stack();

    bool push(const T); 
    bool pop(); 
    void printStack();
};

template <typename T> Stack<T>::Stack(int s)
{
    size = s > 0 ? s : 10;   
    stackPtr = new T[size]; 
    top = -1; // çíà÷åíèå -1 ãîâîðèò î òîì, ÷òî ñòåê ïóñò
}

template <typename T> Stack<T>::~Stack()
{
    delete[] stackPtr; 
}

template <typename T> bool Stack<T>::push(const T value)
{
    if (top == size - 1)
        return false; 

    top++;
    stackPtr[top] = value; 

    return true; 
}

template <typename T> bool Stack<T>::pop()
{
    if (top == -1)
        return false; 

    stackPtr[top] = 0; 
    top--;

    return true; 
}

template <typename T> void Stack<T>::printStack()
{
    for (int ix = size - 1; ix >= 0; ix--)
        cout << "|" << setw(4) << stackPtr[ix] << endl;
}
#pragma endregion


int main()
{
	setlocale(LC_ALL, "rus");

	complex a(12, 34);
	complex b(24, 68);
	complex z1 = a + b;
	complex z2 = b - a;
	complex z3 = a - b;
	cout << z1 << endl << z2 << endl << z3 << endl;

	/*                                                                          */

	matrix<int> in(2, 3);
	in.SetMij(1, 1, 2.1);
	in.SetMij(1, 2, 3);
	in.SetMij(2, 1, 'h');

    complex complex1(1.0);

	in.SetMij(2, 2, complex1);

}

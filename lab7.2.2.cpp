#include <iostream>
using namespace std;

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

    // destructor
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


int main()
{
    setlocale(LC_ALL, "rus");
    matrix<int> in(2, 3);
    in.SetMij(1, 1, 2.1);
    in.SetMij(1, 2, 3);
    in.SetMij(2, 1, 'h');
}

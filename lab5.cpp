#include <iostream>

using namespace std;
void ff() {
    cout << "Я на глобальном уровне" << endl;
};
class BASE {
    public: int i;
    protected: long l;
    private: double d;
    
public:
    BASE() {
        i = l = 0;
        d = 0.0;
    }
    BASE(int v_i, long v_l, double v_d) {
        i = v_i;
        l = v_l;
        d = v_d;
    }
    void setd(double v_d) {
        d = v_d;
    }
    double getd() {
        return d;
    }
    double *adressd() {
        return &d;
    }
    long* adressl() {
        return &l;
    }
    int* adressi() {
        return &i;
    }
protected:
    void ff() {
        cout << "Я в классе BASE" << endl;
    };
};

class DERIVED : public BASE {
    friend ostream& operator<<(ostream& out, DERIVED& ob);
    private: float f;
public: 
    DERIVED() {
        i = l = 0;
        f = 0.0f;
        setd(0.0);
    }
    DERIVED(int v_i, long v_l, double v_d, float v_f) {
        i = v_i;
        l = v_l;
        setd(v_d);
        f = v_f;
    }
    void setf(float v_f) {
        f = v_f;
    }
    float getf() {
        return f;
    }
    float* adressf() {
        return &f;
    }
protected:
    void ff() {
        cout << "Я в классе DERIVED" << endl;
    };
}; 

class DERIVED_1 : public DERIVED {
public:
    DERIVED_1() {
        i = l = 0;
        setf(0.0f);
        setd(0.0);
    }
    void foo() {
        i++;
        l += 1;
        ff();
    }
};

ostream& operator<<(ostream& out, DERIVED& ob) {

    out << ob.getf() << " " << ob.i << " " << ob.l << " " << ob.getd() << endl;
    out << ob.adressf() << " " << ob.adressi() << " " << ob.adressl() << " " << ob.adressd();
    return out;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int g = sizeof(BASE);
    int h = sizeof(DERIVED);
    cout << "BASE: " << g << endl << "DERIVED: " << h << endl;

    DERIVED der1;
    DERIVED der2(23, 25, 12.32, 43.54f);

    DERIVED_1 asd;
    asd.foo();  


}

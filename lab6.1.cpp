#include <iostream>

using namespace std;

class Base1 {
private:
	int i;	
public:
	Base1() {
		cout << "Конструктор Base1 без параметров" << endl;
		i = 0;
	}
	Base1(int v_i) {
		cout << "Конструктор Base1 с параметром" << endl;
		i = v_i;
	}

	void seti(int v_i) {
		i = v_i;
	}
	int geti() {
		return i;
	}
};

class Base2 {
private:
	string name;
public:
	Base2() {
		name = "пусто";
		cout << "Конструктор Base2 без параметров" << endl;
	}
	Base2(string v_name) {
		name = v_name;
		cout << "Конструктор Base2 с параметром" << endl;
	}

	void setn(string v_name) {
		name = v_name;
	}
	string getn() {
		return name;
	}

};

class Derived: public Base1, public Base2{
	friend ostream& operator<<(ostream& out, Derived& ob);
private:
	char ch;
public:
	Derived(){
		ch = 'V';
		cout << "Конструктор Derived без параметров" << endl;
	}

	Derived(char v_ch, string v_name, int v_i):Base2(v_name), Base1(v_i) {
		setn(v_name);
		ch = v_ch;
		seti(v_i);
		cout << "Конструктор Derived с параметрами" << endl;
	}
	void setch(char v_ch) {
		ch = v_ch;
	}
	char getch() {

		return ch;
	}
};
ostream& operator<<(ostream& out, Derived& ob) {

	out << ob.getch() << " " << ob.geti() << " " << ob.getn() << endl;
	return out;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Derived f;
	Derived ff('a', "aaaa", 5);
	cout << ff;
	//Зад. 7 никак, потому что классы уже вызвались на эьапе наследования


	// Зад.8 если поменять порядок вызова базовых кассов derived, 
	//то в данном примере изменится только порядок вызова конструкторов этих классов(порядок зависит от того как они записана в классе наследнике)
	//но если бы у нас были переменный или функции имеющие зависимость, то они бы просто перестали работать
}



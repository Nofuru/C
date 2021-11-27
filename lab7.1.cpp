#include <iostream>

using namespace std;

template <typename T> void swap(T a, T b) {
	T s = a;
	a = b;
	b = s;
	cout << a << ", " << b << endl;
}

template <typename T> T maxi(T x, T y) {
	cout << "Вызвана шаблонная функция" << endl;
	if (x > y) {
		return x;
	}
	else if (y > x) {
		return y;
	}
	else {
		cout << "введенные данные равны между собой." << endl;
	}
}

template<> char maxi(char x, char y) {
	cout << "Вызвана специальная функция" << endl;
	if (sizeof(x) > sizeof(y)) {
		return x;
	}
	else if (sizeof(y) > sizeof(x)) {
		return y;
	}
	else {
		cout << "строки равны между собой" << endl;
		return ' ';
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	//swap(5, 9);
	//swap('a', 'b');

	cout << maxi('a', '1') << endl;
	cout << maxi(0, 1) << endl;
	cout << maxi("Hello", "World") << endl;


}

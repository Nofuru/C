#include <iostream>
using namespace std;

class DomesticAnimal {
protected:
	int weight;
	float price;
	string color;
public:
	DomesticAnimal(){
		weight = 0;
		price = 0.0f;
		color = "Нет";
	}
	DomesticAnimal(int v_weight, float v_price, string v_color){
		weight = v_weight;
		price = v_price;
		color = v_color;
	}
	void printd() {
		cout << "из класса DomesticAnimal" << " Вес: " << weight << " Стоимость: " << price << " Окраска: " << color << endl;
	}
};

class Cow : public virtual DomesticAnimal{
public: 
	Cow()
	{

	}
	Cow(int v_weight, float v_price, string v_color)
	{
		weight = v_weight;
		price = v_price;
		color = v_color;
	}
	void print() {
		cout << "из класса Cow" << endl;
		printd();
	}
};

class Buffalo : public virtual DomesticAnimal {
public: 
	void print() {
		cout << "из класса Buffalo" << endl;
		printd();
	}
};

class Beefalo : public Cow, public Buffalo {
public:
	Beefalo(int v_weight, float v_price, string v_color) {
		weight = v_weight;
		price = v_price;
		color = v_color;
	}
	void print() {
		cout << "из класса Beefalo" << endl;
		printd();
	}
};
	
int main()
{
	setlocale(LC_ALL, "rus");	

	Cow f(70, 23.23f, "black-white");
	f.print();
	Beefalo s(20, 40.42f, "black-white-brown");
	s.print();

	//Зад. 5 была ошибка из-за того, что классы Cow и Buffalo не наследовали Domestic виртуально и из-за этого параметры weight, price, color не были однозначными
}

#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Stock {
	string Name;
	int kol_ak, Size;
	double S, G;
	vector <double> price;
	vector <double> mass;

	double set_tot(double kol) {
		for (int i = 0; i != kol; i++) {
		S += price[i];
		}
		return S;
	}
public:
	Stock() {
		kol_ak = 0;
		S = 0.0;
		G = 0.0;
		cout << "Вызвался конструктор по умолчанию" << endl;
	}

	Stock(int valuekol_ak, string valueName) {
		kol_ak = valuekol_ak;
		Name = valueName;
		S = 0.0;
		G = 0.0;
		cout << "Вызвался конструктор с параметрами" << endl;
	}

	Stock(int valueSize) {
		Size = valueSize;
	}

	~Stock() {
		cout << "Вызвался деструктор" << endl;
	}

	void inpmass() {
		for (int i = 0; i < Size; i++) {
			double p;
			cout << "Введите " << i + 1 << " элемент массива: ";
			cin >> p;
			mass.push_back(p);
		}
	}

	void acquire() {
		for (int i = 0; i < kol_ak; i++) {
			double p;
			cout << "Введите стоимость " << i + 1 << " акции : ";
			cin >> p;
			price.push_back(p);
		}
	}

	void acquire(string cname) {
		cout << "Введите первоначальное кол-во акций: ";
		cin >> kol_ak;
		Name = cname;
		for (int i = 0; i < kol_ak; i++) {
			double p;
			cout << "Введите стоимость " << i + 1 << " акции : ";
			cin >> p;
			price.push_back(p);
		}
	}

	void buy(int N) {
		double pri;
		if (N <= 0) {
			cout << "Невозможно преобрести отрицательное или нулевое кол-во акций.";
			return;
		}
		for (int i = 0; i < N; i++) {
			cout << "Введите цену" << i + 1 << "акции: ";
			cin >> pri;
			price.push_back(pri);
			kol_ak += 1;
		}
	}
	void sell() {
		if (kol_ak <= 0) {
			cout << "У вас нет акций для продажи.";
			return;
		}
		price.pop_back();
		kol_ak -= 1;
	}
	void update1(int n, double nprice) {
		n -= 1;
		price[n] = nprice;
	}
	void show() {
		cout <<"У компании "<< Name << " в пакете вот это число акций: " << kol_ak << endl << "Стоимость каждой акции отдельно: ";
		for (int i = 0; i != kol_ak; i++) {
			if (i == kol_ak -1) {
				cout << price[i] << ". ";
				cout << endl << "Общая стоимость акций: " << set_tot(kol_ak) << endl;
				return;
			}
			cout << price[i] << ", ";
		}
	}
	void showmass() {
		for (int i = 0; i != Size; i++) {
			if (i == Size - 1) {
				cout << mass[i] << ". " << endl;
				return;
			}
			cout << mass[i] << ", ";
		}
	}

	void show(double valueS) {
		G = valueS;
		if (set_tot(kol_ak) != G) {
			cout << "Введенная вами общая сумма акций не соответствует общей сумме, рассчитанной нами." << endl;
			return;
		}
		cout << "У компании " << Name << " в пакете вот это число акций: " << kol_ak << endl << "Стоимость каждой акции отдельно: ";
		for (int i = 0; i != kol_ak; i++) {
			if (i == kol_ak - 1) {
				cout << price[i] << ". ";
				cout << endl << "Общая стоимость акций: " << S << endl;
				return;
			}
			cout << price[i] << ", ";
		}
	}
};

class Student {
	string Name, SName, Patro, adress, faq;
	int Year, pnumber, kurs;
public:
	Student() {
		Year = 0;
		pnumber = 0;
		kurs = 0;
	}
	Student(string vName, string vSName, string vPatro, string vadress, string vfaq, int vYear, int vpnumber, int vkurs) {
		Name = vName;
		SName = vSName;
		Patro = vPatro;
		adress = vadress;
		faq = vfaq;
		Year = vYear;
		pnumber = vpnumber;
		kurs = vkurs;
	}

	string setName(string vName) {
		Name = vName;
	}
	string setSname(string vSName) {
		SName = vSName;
	}
	string setPatro(string vPatro) {
		Patro = vPatro;
	}
	string setadress(string vadress) {
		adress = vadress;
	}
	string setfaq(string vfaq) {
		faq = vfaq;
	}
	int setYear(int vYear) {
		Year = vYear;
	}
	int setpnumber(int vpnumber) {
		pnumber = vpnumber;
	}
	int setkurs(int vkurs) {
		kurs = vkurs;
	}

	string getName() {
		return Name;
	}
	string getSname() {
		return SName;
	}
	string getPatro() {
		return Patro;
	}
	string getadress() {
		return adress;
	}
	string getfaq() {
		return faq;
	}
	int getYear() {
		return Year;
	}
	int getpnumber() {
		return pnumber;
	}
	int getkurs() {
		return kurs;
	}

	void show() {
		cout << "Имя: " << Name << endl
			<< "Фамилия: " << SName << endl
			<< "Отчество: " << Patro << endl
			<< "Адрес: " << adress << endl 
			<< "Факультет: " << faq << endl
			<< "Год рождения: " << Year << endl
			<< "Номер телефона: " << pnumber << endl
			<< "Курс: " << kurs << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	/*
	Stock company1(2, "Com1");
	company1.acquire();
	company1.show(46.46);

	Stock company2;
	company2.acquire("Com2");
	company2.show();
	company2.buy(3);
	company2.show();


	Stock mass1(5);
	mass1.inpmass();
	mass1.showmass();
	*/

	vector <Student> Smass;
	int kkurs, kol_vo = 0, Year;
	string faqq;
	Student Vetrov("Артем", "Ветров", "Александрович", "adress", "ИиВТ", 2002, 89546721891, 3);
	Smass.push_back(Vetrov);
	kol_vo++;
	Student Chichkanov("Владлен", "Чичканов", "Александрович", "adress", "ИиВТ", 2002, 89546721891, 3);
	Smass.push_back(Chichkanov);
	kol_vo++;
	Student Sitnikov("Сергей", "Ситников", "Александрович", "adress", "ИСИТ", 2001, 89546721891, 4);
	Smass.push_back(Sitnikov);
	kol_vo++;

	cin >> kkurs;
	for (int i = 0; i < kol_vo; i++) {
		if (Smass[i].getkurs() == kkurs) {
			cout << Smass[i].getSname() << endl;
		};
	}
	cout << endl;

	for (int i = 0; i < kol_vo; i++) {
		if (Smass[i].getfaq() == "ИиВТ") {
			cout << Smass[i].getfaq() << ", " << Smass[i].getkurs() << " Курс: " << Smass[i].getSname() << endl;
		}
		if (Smass[i].getfaq() == "ИСИТ") {
			cout << Smass[i].getfaq() << ", " << Smass[i].getkurs() << " Курс: " << Smass[i].getSname() << endl;
		}
	}
	cout << endl;
	cout << endl << "Введите год рождения: ";
	cin >> Year;
	
	for (int i = 0; i < kol_vo; i++) {
		if (Smass[i].getYear() > Year) {
			cout << Smass[i].getSname() << endl;
		};
	}
	

}

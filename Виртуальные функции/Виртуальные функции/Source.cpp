#include <iostream>

class base {
public:
	virtual void who() {
		std::cout << "Базовый класс\n";
	}


};

class first_d : public base {
public: 
	void who() {

		std::cout << "Первый производный класс.\n";
	}

};

class second_d : public base {
public:
	void who() {

		std::cout << "Второй производный класс\n";
	}
};

int main() {

	setlocale(LC_ALL, "ru");

	base Bobj;
	base* p;
	first_d Fdobj;
	second_d Sdobj;

	p = &Bobj;
	p->who();//Версия функции для класса base

	p = &Fdobj;
	p->who();//Версия функции для класса first_d

	p = &Sdobj;
	p->who();//Версия функции для класса second_d

	return 0;
}
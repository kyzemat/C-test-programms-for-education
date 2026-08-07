#include <iostream>
#include <functional>
using std::cout;


void vline(int i);
void hline(int i);

void space(int num);
void space(int num, const char ch);


int main() {
	setlocale(LC_ALL, "ru");

	//void (*p) (int i);
	//auto p = vline;//Можно объявить вот так
	std::function<void(int)> p = vline;//Или вот так по современному стандарту

	p(4); //Вызов функции vline()

	p = hline;

	p(3);

	//************************************
	//			Старый вариант
	//************************************
	//void (*p1) (int num);

	//p1 = space;

	//(*p1) (10);

	//void (*p2) (int num, const char ch);

	//p2 = space;

	//(*p2) (10, 'a');


	//************************************
	//			Новый стандарт
	//************************************

	std::function<void(int)> p1 = static_cast<void(*)(int)>(space);

	p1(10);

	std::function<void(int, const char)> p2 = static_cast<void(*)(int,const char)>(space);

	p2(10, 'a');

	return 0;
}

void hline(int i) {
	for (; i > 0; i--) {
		cout << "-";
	}
	cout << '\n';
}

void vline(int i) {

	for (; i > 0; i--) {
		cout << "|\n";
	}
}

void space(int num) {
	for (; num > 0; num--) {
		cout << ' ';
	}
}
void space(int num, const char ch) {
	for (; num > 0; num--) {
		cout << ch;
	}
}
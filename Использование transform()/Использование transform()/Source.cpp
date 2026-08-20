#include <iostream>
#include <list>
#include <algorithm>
using std::cout;
using std::list;

int xform(int i) {
	return i * i;
}

int doublexform(int i, int j) {
	return i * j;
}

int main() {
	setlocale(LC_ALL, "ru");

	list<int> x1, x2;

	for (int i = 0; i < 10; i++) {
		x1.push_back(i);
		x2.push_back(i);
	}

	cout << "Исходный список x1: ";
	list<int>::iterator p = x1.begin();
	while (p != x1.end()) {
		cout << *p << ' ';
		p++;
	}

	cout << '\n';

	p = transform(x1.begin(), x1.end(), x1.begin(), xform);

	cout << "Преобразованный список x1: ";
	p = x1.begin();
	while (p != x1.end()) {
		cout << *p << ' ';
		p++;
	}

	//Бинарная форма вызова transform:

	cout << "\n\nИсходный список x1: ";
	p = x1.begin();
	while (p != x1.end()) {
		cout << *p << ' ';
		p++;
	}

	cout << '\n';

	cout << "Исходный список x2: ";
	p = x2.begin();
	while (p != x2.end()) {
		cout << *p << ' ';
		p++;
	}

	cout << '\n';

	p = transform(x1.begin(), x1.end(), x2.begin(), x1.begin(), doublexform);

	cout << "Преобразованный список x1 (x1*x2): ";
	p = x1.begin();
	while (p != x1.end()) {
		cout << *p << ' ';
		p++;
	}

	return 0;

}

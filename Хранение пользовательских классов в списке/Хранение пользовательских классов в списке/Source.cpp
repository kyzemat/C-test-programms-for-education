#include <iostream>
#include <list>
#include <cstring>
using std::list;
using std::cout;

class myclass {
	int a, b;
	int sum;
public:
	myclass() { a = b = sum = 0; }
	myclass(int i, int j) {
		a = i;
		b = j;
		sum = a + b;
	}

	int getsum() const { return sum; }

	friend bool operator<(const myclass& a, const myclass& b);

	friend bool operator>(const myclass& a, const myclass& b);

	friend bool operator==(const myclass& a, const myclass& b);

	friend bool operator!=(const myclass& a, const myclass& b);
};

bool operator<(const myclass& a, const myclass& b) {
	return a.sum < b.sum;
}

bool operator>(const myclass& a, const myclass& b) {
	return a.sum > b.sum;
}

bool operator==(const myclass& a, const myclass& b) {
	return a.sum == b.sum;
}

bool operator!=(const myclass& a, const myclass& b) {
	return a.sum != b.sum;
}


int main() {
	setlocale(LC_ALL, "ru");

	list<myclass> lst1;

	for (int i = 0; i < 10; i++) lst1.push_back(myclass(i, i));

	cout << "Первый список: \n";
	list<myclass>::iterator p = lst1.begin();
	while (p != lst1.end()) {
		cout << p->getsum() << ' ';
		p++;
	}
	cout << std::endl;

	list<myclass> lst2;
	for (int i = 0; i < 10; i++) lst2.push_back(myclass(i * 2, i * 3));

	cout << "Второй список: \n";
	p = lst2.begin();
	while (p != lst2.end()) {
		cout << p->getsum() << ' ';
		p++;
	}
	cout << std::endl;

	lst1.merge(lst2);

	cout << "Объединенный список: \n";
	p = lst1.begin();
	while (p != lst1.end()) {
		cout << p->getsum() << ' ';
		p++;
	}

	return 0;
}
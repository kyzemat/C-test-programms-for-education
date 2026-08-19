#include <iostream>
#include <map>
using std::cin;
using std::cout;
using std::map;


int main() {
	setlocale(LC_ALL, "ru");
	map<char, int> m;

	for (int i = 0; i < 10; i++) {
		m.insert(std::pair<char, int>('A' + i, i));
	}

	char ch;
	cout << "Введите ключ: ";
	cin >> ch;

	map<char, int>::iterator p;

	p = m.find(ch);
	if (p != m.end()) {
		cout << p->second;
	}
	else cout << "Такого ключа в отображении нет.\n";

	return 0;
}
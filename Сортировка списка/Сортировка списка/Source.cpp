#include <iostream> 
#include <list>
#include <cstdlib>
#include <time.h>
using std::cout;
using std::list;



int main() {
	setlocale(LC_ALL, "ru");
	list<int> lst;
	srand(time(NULL));

	for (int i = 0; i < 10; i++) lst.push_back(rand()%100);

	cout << "Исходное содержимое списка:\n";
	list<int>::iterator p = lst.begin();
	while (p != lst.end()) {
		cout << *p << " ";
		p++;
	}

	lst.sort();

	cout << "\nОтсортированное содержимое списка: \n";
	p = lst.begin();
	while (p != lst.end()) {
		cout << *p << " ";
		p++;
	}

	list<char> charlist1, charlist2;

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			charlist2.push_back('A' + i);
		}
		else {
			charlist1.push_back('A' + i);
		}
	}

	cout << "\n\n\nСодержимое списка 1: \n";
	list<char>::iterator p1 = charlist1.begin();
	while (p1 != charlist1.end()) {
		cout << *p1;
		p1++;
	}

	cout << "\nСодержимое списка 2: \n";
	p1 = charlist2.begin();
	while (p1 != charlist2.end()) {
		cout << *p1;
		p1++;
	}

	charlist1.merge(charlist2);
	if (charlist2.empty()) cout << "\n\nСписок 2 теперь пуст!\n";

	cout << "Содержимое списка 1 после слияния: \n";
	p1 = charlist1.begin();
	while (p1 != charlist1.end()) {
		cout << *p1;
		p1++;
	}

	return 0;
}
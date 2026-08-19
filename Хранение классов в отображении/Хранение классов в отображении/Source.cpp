#include <iostream>
#include <map>
#include <cstring>
using std::cout;
using std::map;
using std::cin;

class word {
	char str[20];
public:
	word() { strcpy_s(str, ""); }
	word(const char* s) { strcpy_s(str, s); }
	char* get() { return str; }
};

bool operator<(word a, word b) {
	return strcmp(a.get(), b.get()) < 0;
}

class meaning {
	char str[80];
public:
	meaning() { strcmp(str, ""); }
	meaning(const char* s) { strcpy_s(str, s); }
	char* get() { return str; }
};

int main() {
	system("chcp 1251");//Чтобы консоль считывала символы в кодировке win 1251

	setlocale(LC_ALL, "ru");//Чтобы отображались символы внутри консоли
	map<word, meaning> dictionary;

	dictionary.insert(std::make_pair(word("Дом"), meaning("Место проживания")));

	dictionary.insert(std::make_pair(word("Клавиатура"), meaning("Устройство ввода данных")));

	dictionary.insert(std::make_pair(word("Программирование"), meaning("Процесс создания программы")));

	dictionary.insert(std::make_pair(word("STL"), meaning("Стандартная библиотека шаблонов")));

	char str[80];

	cout << "Введите слово: ";
	cin >> str;

	map<word, meaning>::iterator p;
	p = dictionary.find(word(str));
	if (p != dictionary.end())
		cout << "Определение: " << p->second.get();
	else
		cout << "Такого слова в словаре нет!\n";

	return 0;
}
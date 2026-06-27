#include <iostream>

class base {
public:
	base() { std::cout << "Создание base-объекта\n"; }
	~base() { std::cout << "Разрушение base-объекта\n"; }
};

class derived : public base {
public:
	derived() { std::cout << "Создание derived-объекта\n"; }
	~derived() { std::cout << "Разрушение derived-объекта\n"; }
};

int main() {
	setlocale(LC_ALL, "ru");
	derived ob;

	//Никаких действий кроме создания и разрушения объекта ob.

	return 0;
}
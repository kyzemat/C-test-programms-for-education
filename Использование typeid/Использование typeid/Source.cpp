#include <iostream>
#include <typeinfo>

class Base {
	virtual void f() {};
};

class Derived1 : public Base {
	//...
};

class Derived2 : public Base {
	//...
};

void what_type(Base& ob) {
	std::cout << "Внутрь функции был передан объект типа: ";
	std::cout << typeid(ob).name() << "\n";
}


int main() {
	setlocale(LC_ALL, "ru");

	int i, j;
	float f;
	Base baseob, *p;
	Derived1 Dob1;
	Derived2 Dob2;

	p = &baseob;

	std::cout << "Переменная p указывает на объект типа: " << typeid(*p).name() << "\n";

	p = &Dob1;
	std::cout << "Переменная p указывает на объект типа: " << typeid(*p).name() << "\n";

	p = &Dob2;
	std::cout << "Переменная p указывает на объект типа: " << typeid(*p).name() << "\n";

	std::cout << "\nТип переменной i: " << typeid(i).name();
	std::cout << "\nТип переменной f: " << typeid(f).name();
	std::cout << "\nТип переменной ob: " << typeid(baseob).name() << "\n\n";

	what_type(baseob);
	what_type(Dob1);
	what_type(Dob2);


	if (typeid(i) == typeid(j)) {
		std::cout << "\nПеременные i и j имеют один тип\n";
	}

	if (typeid(i) != typeid(f)) {

		std::cout << "Переменные i и f имеют разные типы!";
	}

	return 0;
}
#include <iostream>

class Base {
public:
	virtual void f() { std::cout << "В классе Base\n\n"; }
};

class Derived : public Base {
public:
	void f() { std::cout << "В классе Derived\n\n"; }
};

int main() {
	setlocale(LC_ALL, "ru");

	Base* bp, b_ob;
	Derived* dp, d_ob;

	dp = dynamic_cast<Derived*> (&d_ob);

	if (dp) {
		std::cout << "Приведение типов из (Derived* в Derived*) реализовано успешно!\n";
		dp->f();
	}
	else {
		std::cout << "Ошибка преобразования типов!\n";
	}

	bp = dynamic_cast<Base*> (&b_ob);

	if (bp) {
		std::cout << "Приведение типов из (Base* в Base*) реализовано успешно!\n";
		bp->f();
	}
	else {
		std::cout << "Ошибка преобразования типов!\n";
	}

	dp = dynamic_cast<Derived*> (&b_ob);

	if (!dp) {
		std::cout << "Приведение типов из (Base* в Derived*) не реализовано!\n\n";
	}
	else {
		std::cout << "Ошибка преобразования типов!\n";
	}

	bp = dynamic_cast<Base*> (&d_ob);

	if (bp) {
		std::cout << "Приведение типов из (Derived* в Base*) реализовано успешно!\n";
		bp->f();
	}
	else {
		std::cout << "Ошибка преобразования типов!\n";
	}

	bp = &d_ob;//Указывает на объект Derived
	dp = dynamic_cast<Derived*> (bp);
	if (dp) {
		std::cout << "Приведение bp к Derived* реализовано, так как bp действительно " <<
			"указывает на объект типа Derived\n";
		dp->f();
	}
	else {
		std::cout << "Ошибка преобразования типов!\n";
	}

	bp = &b_ob;
	dp = dynamic_cast<Derived*> (bp);
	if (!dp) {
		std::cout << "Теперь приведение bp к типу Derived не реализовано, так как bp в действительности " <<
			"указывает на объект класса Base\n\n";

	}
	else {
		std::cout << "Ошибка преобразования типов!\n";
	}

	dp = &d_ob;
	bp = dynamic_cast<Base*> (dp);
	if (bp) {
		std::cout << "Приведение dp к типу Base* реализовано!\n";
		bp->f();
	}
	else {
		std::cout << "Ошибка преобразования типов!\n";
	}

	return 0;
}
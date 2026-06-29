#include <iostream>

class base1 {
protected:
	int i;
public:
	base1(int x) { i = x; std::cout << "Создание base1 объекта\n"; }
	~base1() { std::cout << "Разрушение base1 объекта\n"; }
};

class base2 {
protected:
	int k;
public:
	base2(int x) { k = x; std::cout << "Создание base2 объекта\n"; }
	~base2() { std::cout << "Разрушение base2 объекта\n"; }
};

class derived : public base1, public base2 {
	int j;
public:
	//Класс derived использует x, y передается конструктору base1, а z передается конструктору base2
	derived(int y, int z) : base1(y), base2(z) { j = 10; std::cout << "Создание derived объекта\n"; }
	~derived() { std::cout << "Разрушение derived объекта\n"; }

	void show() { std::cout << i << ' ' << k << " " << j << '\n'; }
};

int main() {
	setlocale(LC_ALL, "ru");
	derived ob(4, 5);

	ob.show();

	return 0;

}
#include <iostream>

class three_d {
	int x, y, z; // Трехмерные координаты
public:
	three_d() { x = y = z = 0; }
	three_d(int i, int j, int k) { x = i; y = j; z = k; }

	three_d operator=(three_d op2);
	friend three_d operator+(three_d op1, three_d op2);

	friend three_d operator++(three_d& op);
	friend three_d operator++(three_d& op, int notused);

	void show();
};

three_d operator++(three_d& op) {

	op.x++;
	op.y++;
	op.z++;

	return op;
}

three_d operator++(three_d& op, int notused) {
	three_d temp=op;

	op.x++;
	op.y++;
	op.z++;

	return temp;
}


three_d three_d::operator=(three_d op2) {

	x = op2.x;
	y = op2.y;
	z = op2.z;

	return *this;
}

//Функция-друг для перегрузки оператора +
three_d operator+(three_d op1, three_d op2) {
	three_d temp;

	temp.x = op1.x + op2.x;
	temp.y = op1.y + op2.y;
	temp.z = op1.z + op2.z;

	return temp;
}

//Перегрузка префиксного оператора ++


void three_d::show() {
	std::cout << x << ", ";
	std::cout << y << ", ";
	std::cout << z << "\n";
}



int main() {
	setlocale(LC_ALL, "ru");

	three_d a(1, 2, 3), b(10, 10, 10), c;

	a.show();
	b.show();

	c = a + b;
	c.show();
	
	c = a + b + c;
	c.show();

	c = b = a;

	c.show();
	b.show();

	++c;
	c.show();

	c++;
	c.show();

	a = ++c;//Значение а и с одинаковы
	a.show();
	c.show();

	a = c++;//Значение а и с разные
	a.show();
	c.show();

	return 0;
}
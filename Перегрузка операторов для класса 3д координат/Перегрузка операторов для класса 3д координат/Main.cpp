#include <iostream>

class three_d {
	int x, y, z; // Трехмерные координаты
public:
	three_d() { x = y = z = 0; }
	three_d(int i, int j, int k) { x = i; y = j; z = k; }
	three_d operator+(three_d op2); //Операнд 1 передается неявно
	three_d operator=(three_d op2); //Операнд 1 передается неявно
	three_d operator++(); //Единственный операнд this
	three_d operator++(int notused);
	three_d operator--();
	three_d operator--(int notused);
	void show();
};

three_d three_d::operator--() {
	x--;
	y--;
	z--;

	return *this;
}

three_d three_d::operator--(int notused) {
	three_d temp = *this;

	x--;
	y--;
	z--;

	return temp;
}

//Перегрузка префиксного оператора ++
three_d three_d::operator++() {
	x++;
	y++;
	z++;

	return *this;
}

void three_d::show() {
	std::cout << x << ", ";
	std::cout << y << ", ";
	std::cout << z << "\n";
}

three_d three_d::operator+(three_d op2) {
	three_d temp;

	temp.x = x + op2.x;
	temp.y = y + op2.y;
	temp.z = z + op2.z;

	return temp;
}

three_d three_d::operator=(three_d op2) {
	x = op2.x;
	y = op2.y;
	z = op2.z;

	return *this;
}

three_d three_d::operator++(int notused) {
	three_d temp = *this;//Сохранение исходного значения

	x++;
	y++;
	z++;

	return temp;// возврат исходного значения
}

int main() {
	setlocale(LC_ALL, "ru");
	three_d a(1, 2, 3), b(10, 10, 10), c;

	a.show();
	b.show();

	c = a + b; //Сложение объектов a и b
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

	a = ++c;//Объект а получает значение после инкремента

	a.show();
	c.show();

	a = c++;//Объект а получает значение до инкремента

	a.show();
	c.show();



	return 0;
}
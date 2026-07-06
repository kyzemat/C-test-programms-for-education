#include <iostream>

class figure {
protected:
	double x, y;
public:
	figure() {
		x = 0;
		y = 0;
	}//Конструктор по умолчанию

	figure(double i) {//Конструктор для класса circle
		x = i;
		y = 0;
	}

	figure(double i, double j) {
		x = i;
		y = j;
	}//Конструктор для классов triangle и rectangle

	virtual void show_area() = 0;	/*Обявляю абстрактную функцию, для того чтобы производные классы
									  обязательно реализовывали ее по-своему*/

};

class triangle : public figure {
public:
	triangle(double i, double j) : figure(i, j) {}
	void show_area() {
		std::cout << "Треугольник с высотой " << x << " и основанием "
			<< y << " имеет площадь " << x * 0.5 * y << '\n';
	}
};

class rectangle : public figure {
public:
	rectangle(double i, double j) : figure(i, j) {}
	void show_area() {
		std::cout << "Прямоугольник с размерами: " << x << " на " << y
			<< " имеет площадь " << x * y << "\n";
	}
};

class circle : public figure {
public:
	circle(double i) : figure(i) {}

	void show_area() {
		std::cout << "Окружность с радиусом: " << x << " имеет площадь: "
			<< 3.14 * x * x << "\n";
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	figure* p;

	triangle t(10.0, 5.0);
	rectangle r(10.0, 5.0);
	circle c(9.0);

	p = &t;
	p->show_area();

	p = &r;
	p->show_area();

	p = &c;
	p->show_area();

	return 0;
}
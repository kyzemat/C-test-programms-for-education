#include <iostream>
#include <cstdlib>
#include <iomanip>

template <typename type> class figure {
protected:
	type x, y;
public:
	figure(type i, type j) {
		x = i;
		y = j;
	}
	virtual type area() = 0;

};

template <typename type> class triangle : public figure<type> {
public:
	triangle(type i, type j) : figure<type>(i, j) {}

	type area() {
		return this->x * 0.5 * this->y;
	}

};

template <typename type> class rectangle : public figure<type> {
public:
	rectangle(type i, type j) : figure<type>(i, j) {}

	type area() {
		return this->x * this->y;
	}
};

template <typename type>class circle : public figure<type> {
public:
	circle(type i, type j = 0) : figure<type>(i, j) {}

	type area() {
		return 3.14 * this->x * this->x;
	}
};

double random_decimal() {
	return (rand() % 10) + (rand() % 10) / 10.0;
}

figure<double>* factory() {
	switch (rand() % 3) {
	case 0: return new circle<double>(random_decimal());
	case 1: return new triangle<double>(random_decimal(), random_decimal());
	case 2: return new rectangle<double>(random_decimal(), random_decimal());
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "ru");

	srand(time(nullptr));

	figure<double>* p;

	int t = 0, r = 0, c = 0;

	for (int i = 0; i < 10; i++) {
		p = factory();
		std::cout << "Объект имеет тип: " << typeid(*p).name() << ". ";

		if (typeid(*p) == typeid(triangle<double>)) t++;
		if (typeid(*p) == typeid(circle<double>)) c++;
		if (typeid(*p) == typeid(rectangle<double>)) r++;
		std::cout << std::setprecision(2) << std::setiosflags(std::ios::showpoint | std::ios::fixed);

		std::cout << "Площадь объекта равна: " << p->area() << std::endl;
	}

	std::cout << "\nБыли сгенерированы объекты: ";
	std::cout << "\nТреугольников: " << t << std::endl;
	std::cout << "Прямоугольников: " << r << std::endl;
	std::cout << "Окружностей: " << c << std::endl;

	return 0;
}
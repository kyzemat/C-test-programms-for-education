#include <iostream>
#include <cstdlib>
#include <iomanip>

class figure {
protected:
	double x, y;
public:
	figure(double i, double j) {
		x = i;
		y = j;
	}
	virtual double area() = 0;

};

class triangle : public figure {
public:
	triangle(double i, double j) : figure(i,j) {}

	double area() {
		return x * 0.5 * y;
	}

};

class rectangle : public figure {
public:
	rectangle(double i, double j) : figure(i, j) {}

	double area(){
		return x * y;
	}
};

class circle : public figure {
public:
	circle(double i, double j=0) : figure(i,j) {}

	double area() {
		return 3.14 * x * x;
	}
};

double random_decimal() {
	return (rand() % 10) + (rand() % 10) / 10.0;
}

figure* factory() {
	switch (rand() % 3) {
	case 0: return new circle(random_decimal());
	case 1: return new triangle(random_decimal(), random_decimal());
	case 2: return new rectangle(random_decimal(), random_decimal());
	}
	return 0;
}


int main() {
	setlocale(LC_ALL, "ru");

	srand(time(nullptr));

	figure* p;

	int t = 0, r = 0, c = 0;

	for (int i = 0; i < 10; i++) {
		p = factory();
		std::cout << "Объект имеет тип: " << typeid(*p).name() << ". ";
	
		if (typeid(*p) == typeid(triangle)) t++;
		if (typeid(*p) == typeid(circle)) c++;
		if (typeid(*p) == typeid(rectangle)) r++;
		std::cout << std::setprecision(2) << std::setiosflags(std::ios::showpoint | std::ios::fixed);
		std::cout << "Площадь объекта равна: " << p->area() << std::endl;
	}

	std::cout << "\nБыли сгенерированы объекты: ";
	std::cout << "\nТреугольников: " << t << std::endl;
	std::cout << "Прямоугольников: " << r << std::endl;
	std::cout << "Окружностей: " << c << std::endl;

	return 0;
}
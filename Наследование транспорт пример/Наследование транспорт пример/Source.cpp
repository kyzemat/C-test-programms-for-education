#include <iostream>

class road_vehicle {
	int wheels;
	int passengers;
public:
	void set_wheels(int i) { wheels = i; }
	int get_wheels() { return wheels; }
	void set_passengers(int i) { passengers = i; }
	int get_passengers() { return passengers; }
};

class truck : public road_vehicle {
	int cargo;
public:
	void set_cargo(int i) { cargo = i; }
	int get_cargo() { return cargo; }
	void show();
};

enum type { car, van, wagon };

class automobile : public road_vehicle {
	enum type car_type;
public:
	void set_type(type t) { car_type = t; }
	enum type get_car_type() { return car_type; }
	void show();
};

void truck::show() {
	std::cout << "колес: " << get_wheels() << "\n";
	std::cout << "пассажиров: " << get_passengers() << "\n";
	std::cout << "грузовместимость в кубических футах: " << cargo << "\n";
}

void automobile::show() {
	std::cout << "колес: " << get_wheels() << "\n";
	std::cout << "пассажиров: " << get_passengers() << "\n";
	std::cout << "тип: ";
	switch (get_car_type()) {
		case van: std::cout << "Автофургон\n";
			break;
		case car: std::cout << "Легковушка\n";
			break;
		case wagon: std::cout << "Фура\n";
			break;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	truck t1, t2;
	automobile c;

	t1.set_wheels(18);
	t1.set_passengers(2);
	t1.set_cargo(3200);

	t2.set_wheels(6);
	t2.set_passengers(3);
	t2.set_cargo(1200);

	t1.show();
	std::cout << '\n';
	t2.show();
	std::cout << '\n';

	c.set_wheels(4);
	c.set_passengers(6);
	c.set_type(van);

	c.show();

	return 0;

}
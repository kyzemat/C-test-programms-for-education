#include <iostream>

class three_d {
	int x, y, z;
public:
	three_d() { x = y = z = 0; }
	three_d(int a, int b, int c) { x = a; y = b; z = c; }

	friend std::ostream& operator<<(std::ostream& stream, three_d obj);

	friend std::istream& operator>>(std::istream& stream, three_d& obj);//Передаем объект по ссылке, чтобы значения поменялись не для копии, а для настоящего объекта
};

std::ostream& operator<<(std::ostream& stream, three_d obj) {
	
	stream << obj.x << ", ";
	stream << obj.y << ", ";
	stream << obj.z << "\n";

	return stream;
}

std::istream& operator>>(std::istream& stream, three_d& obj) {

	std::cout << "\nВведите координаты объекта (x, y, z): ";

	stream >> obj.x >> obj.y >> obj.z;

	return stream;
}

int main() {
	setlocale(LC_ALL, "ru");

	three_d a(1, 2, 3), b(4, 5, 6), c(7, 8, 9), d;

	std::cout << a << b << c;

	std::cin >> d;

	std::cout << d;

	return 0;
}
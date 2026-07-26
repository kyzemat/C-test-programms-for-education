#include <iostream>
#include <iomanip>

std::ostream& setup(std::ostream& stream) {
	stream.setf(std::ios::left);
	stream << std::setw(10) << std::setfill('$');

	return stream;
}

std::istream& prompt(std::istream& stream) {
	std::cin >> std::hex;
	std::cout << "¬ведите число в шестандцатеричном формате: ";

	return stream;
}

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << 10 << " " << setup << 10 << std::endl;

	int i;

	std::cin >> prompt >> i;
	std::cout << i;


	return 0;
}
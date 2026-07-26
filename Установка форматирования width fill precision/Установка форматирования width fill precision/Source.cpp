#include <iostream>

int main() {

	std::cout.setf(std::ios::showpos | std::ios::scientific);
	std::cout << 123 << " " << 123.23 << '\n';

	std::cout.precision(2);
	std::cout.width(10);// Необходимо каждый раз перед выводом устанавливать параметр width
	std::cout << 123 << ' ';
	std::cout.width(10);
	std::cout << 123.23 << "\n";

	std::cout.fill('#');
	std::cout.width(10);
	std::cout << 123 << " ";

	std::cout.width(10);
	std::cout << 123.23;


	return 0;
}
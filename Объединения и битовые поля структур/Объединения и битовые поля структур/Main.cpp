#include <iostream>
#include <conio.h>

struct byte {
	unsigned a : 1;
	unsigned b : 1;
	unsigned c : 1;
	unsigned d : 1;
	unsigned e : 1;
	unsigned f : 1;
	unsigned g : 1;
	unsigned h : 1;
};

union bits {
	char ch;
	struct byte bit;
} ascii;


void disp_bits(bits bit);

int main() {

	do {
		std::cin >> ascii.ch;
		std::cout << ": ";
		disp_bits(ascii);

	} while (ascii.ch != 'q');

	return 0;
}

void disp_bits(bits b) {

	if (b.bit.h) std::cout << "1 ";
	else std::cout << "0 ";
	if (b.bit.g) std::cout << "1 ";
	else std::cout << "0 ";
	if (b.bit.f) std::cout << "1 ";
	else std::cout << "0 ";
	if (b.bit.e) std::cout << "1 ";
	else std::cout << "0 ";
	if (b.bit.d) std::cout << "1 ";
	else std::cout << "0 ";
	if (b.bit.c) std::cout << "1 ";
	else std::cout << "0 ";
	if (b.bit.b) std::cout << "1 ";
	else std::cout << "0 ";
	if (b.bit.a) std::cout << "1 ";
	else std::cout << "0 ";
	std::cout << '\n';
}
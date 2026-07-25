#include <iostream>

void showflags(std::ios::fmtflags f);

int main() {
	std::ios::fmtflags f;

	f = std::cout.flags();

	showflags(f);
	std::cout.setf(std::ios::showpos | std::ios::scientific);

	f = std::cout.flags();
	showflags(f);


	std::cout.unsetf(std::ios::scientific);

	f = std::cout.flags();
	showflags(f);

	return 0;
}

void showflags(std::ios::fmtflags f) {
	long i;

	for (i = 0x4000; i; i = i >> 1)
		if (i & f) std::cout << "1 ";
		else std::cout << "0 ";

	std::cout << "\n";
}
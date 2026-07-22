#include <iostream>
#include <new>

int main() {
	setlocale(LC_ALL, "ru");

	int* p, i;

	try {
		p = new int[32];
	}
	catch (std::bad_alloc ex) {
		std::cout << "Память не выделена\n";
		return 1;
	}

	for (i = 0; i < 32; i++) p[i] = i;

	for (i = 0; i < 32; i++) std::cout << p[i] << " ";

	delete[] p;

	return 0;
}
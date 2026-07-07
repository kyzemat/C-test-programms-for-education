#include <iostream>

template <typename type> void swapargs(type& a, type& b) {

	type temp;

	temp = a;
	a = b;
	b = temp;
}

int main() {
	setlocale(LC_ALL, "ru");

	int i = 10, j = 20;
	double a = 324.312, b = 534.24;
	char x = 'a', y = 'z';

	std::cout << "Исходные значения i, j: " << i << ' ' << j << '\n';
	std::cout << "Исходные значения a, b: " << a << ' ' << b << '\n';
	std::cout << "Исходные значения x, y: " << x << ' ' << y << '\n';

	swapargs(i, j);
	swapargs(a, b);
	swapargs(x, y);

	std::cout << "После перестановки i, j: " << i << ' ' << j << '\n';
	std::cout << "После перестановки a, b: " << a << ' ' << b << '\n';
	std::cout << "После перестановки x, y: " << x << ' ' << y << '\n';

	return 0;
}
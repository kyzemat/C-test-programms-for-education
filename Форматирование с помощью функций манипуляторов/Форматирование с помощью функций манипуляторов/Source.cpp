#include <iostream>
#include <iomanip>

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << std::setprecision(2) << std::fixed << 1000.234 << std::endl;
	std::cout << std::setw(20) << "Всем привет!\n";

	std::cout << std::resetiosflags(std::ios::fixed) << std::endl;

	std::cout << std::setiosflags(std::ios::showpos);

	std::cout << std::setprecision(6) << std::setiosflags(std::ios::scientific);
	std::cout << 123 << " " << 123.23 << std::endl;


	char s[90];

	std::cin >> std::ws;//Игнорирует пробелы введенные до первого символа
	std::cin.getline(s, 90);
	std::wcout << s;

	return 0;
}
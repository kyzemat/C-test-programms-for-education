#include <iostream>
#include <fstream>

const char* MY_FILE = "text_file.txt";

int main() {
	setlocale(LC_ALL, "ru");

	char ch;
	std::fstream in(MY_FILE, std::ios::in | std::ios::binary);

	if (!in) {
		std::cout << "Не удалось открыть файл!";
		return 1;
	}

	unsigned short int pos=0;

	do {
		std::cout << "Введите стартовую позицию: ";
		std::cin >> pos;
	}while (pos < 0);
	

	in.seekg(pos, std::ios::beg);

	while (in.get(ch)) {
		std::cout << ch;
	}

	in.close();

	std::cout << "\n";

	std::fstream out(MY_FILE, std::ios::in | std::ios::out | std::ios::binary);

	if (!out) {
		std::cout << "Не удалось открыть файл!";
		return 1;
	}

	do {
		std::cout << "Введите стартовую позицию: ";
		std::cin >> pos;
	} while (pos < 0);

	out.seekp(pos, std::ios::beg);

	out.put('X');//Помещаем символ X на выбранную позицию
	out.close();

	return 0;
}
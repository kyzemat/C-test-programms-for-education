#include <iostream>
#include <fstream>

const char* FIRST_FILE = "text_file1.txt";
const char* SECOND_FILE = "text_file2.txt";

int main() {
	setlocale(LC_ALL, "ru");
	unsigned char buf1[1024], buf2[1024];

	std::ifstream f1(FIRST_FILE, std::ios::in | std::ios::binary);
	if (!f1) {
		std::cout << "Не удалось открыть первый файл!";
		return 1;
	}

	std::ifstream f2(SECOND_FILE, std::ios::in | std::ios::binary);
	if (!f2) {
		std::cout << "Не удалось открыть второй файл!";
		return 1;
	}

	std::cout << "Сравнение файлов...\n";

	do {
		f1.read((char*)buf1, sizeof buf1);
		f2.read((char*)buf2, sizeof buf2);

		if (f1.gcount() != f2.gcount()) {
			std::cout << "Файлы имеют разные размеры.\n";
			f1.close();
			f2.close();
			return 0;
		}

		for (int i = 0; i < f1.gcount(); i++) {
			if (buf1[i] != buf2[i]) {
				std::cout << "Содержимое файлов отличается друг от друга.";
				f1.close();
				f2.close();

				return 0;
			}
		}
	} while (!f1.eof() && !f2.eof());

	std::cout << "Файлы одинаковы!";

	f1.close();
	f2.close();

	return 0;
}
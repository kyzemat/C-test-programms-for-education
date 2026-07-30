#include <iostream>
#include <fstream>

const char* MY_FILE = "text_file.txt";

int main() {
	int n[5] = { 1,2,3,4,5 };
	
	std::ofstream out(MY_FILE, std::ios::out | std::ios::binary);

	if (!out) {
		std::cout << "Не удалось открыть файл!";
		return 1;
	}

	out.write((char*)&n, sizeof n);

	out.close();

	for (register int i = 0; i < 5; i++) {
		n[i] = 0;
	}

	std::ifstream in(MY_FILE, std::ios::in | std::ios::binary);

	if(!in) {
		std::cout << "Не удалось открыть файл!";
		return 1;
	}

	in.read((char*)&n, sizeof n);

	for (register int i = 0; i < 5; i++) {
		std::cout << n[i] << " ";
	}

	in.close();

	return 0;
}
#include <iostream>
#include <fstream>

const char* MY_FILE = "text_file.txt";

int main() {
	setlocale(LC_ALL, "ru");

	char ch;
	const char* text = "Привет мир!";

	std::ofstream out(MY_FILE, std::ios::out | std::ios::binary);

	if (!out) {
		std::cout << "Не удалось открыть файл!";
		return 1;
	}

	while (*text) out.put(*text++);

	out.close();

	std::ifstream in(MY_FILE, std::ios::in | std::ios::binary);
	if (!in) {
		std::cout << "\nНе удалось открыть файл!";
		return 1;
	}

	while (in) {//При достижении конца файла поток in примет значение false
		in.get(ch);
		if (in) std::cout << ch;
	}
	//ТАкже этот код можно заменить на 
	//while (in.get(ch)) {
	//	std::cout << ch;
	//}


	in.close();

	return 0;
}
#include <iostream>

void handler(int test){
	
	try {
		if (test == 0) throw test;
		if (test == 1) throw 'a';
		if (test == 2) throw 123.43;//Генерируем исключения разных типов
	}
	catch (int i) {
		std::cout << "Перехват исключения типа int: " << i << "\n";
	}
	catch (...) {
		std::cout << "Было перехвачено исключение, не соответствующее типу int!\n";
	}//Обработка исключений для всех типов

}

int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "НАЧАЛО\n";

	handler(1);
	handler(2);
	handler(0);
	handler(3);

	std::cout << "КОНЕЦ";

	return 0;
}
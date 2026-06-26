#include <iostream>
#include <cstring>

class str_type {
	char string[200];
public:
	str_type(const char* str = "") { strcpy_s(string, str); }
	str_type operator+(str_type str); // конкатенация строк
	str_type operator=(str_type str); //Присваивание строк

	str_type operator+(char* str); //Конкатенация строки к объекту
	str_type operator=(char* str); //Присвоение объекту строки

	void show_str() { std::cout << string; }

};

str_type str_type::operator+(char* str) {
	str_type temp;

	strcpy_s(temp.string, string); //копируем изначальное значение строки в временный объект
	strcat_s(temp.string, str); //Присоединяем к временному объекту строку
	return temp;//Возвращаем временный объект
}

str_type str_type::operator=(char* str) {
	strcpy_s(string, str);
	return *this;

}

str_type str_type::operator+(str_type str) {
	str_type temp;

	strcpy_s(temp.string, string); //Копируем в временный объект значение передаваемой строки до изменения
	strcat_s(temp.string, str.string); // Присоединяем к временному объекту строку 
	return temp; //Возвращаем результат
}

str_type str_type::operator=(str_type str) {
	strcpy_s(string, str.string); //Копируем в операнд слева строку справа
	return *this;
}

int main() {
	setlocale(LC_ALL, "ru");

	str_type a("Всем"), b(" привет!"), c;

	c = a + b;

	c.show_str();

	c = "Я люблю плюсы";
	c.show_str();
	std::cout << "\n";

	a = "потому что они хороши для программирования";

	b = c + " " + a;
	b.show_str();

	return 0;

}
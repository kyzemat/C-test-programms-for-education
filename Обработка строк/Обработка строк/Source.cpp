#include <iostream>
#include <string>
using std::cout;
using std::string;

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "ru");

	string str1("Класс string позволяет эффективно ");
	string str2("обрабатывать строки.");
	string str3;

	//Присваивание строк
	str3 = str1;
	cout << str1 << "\n" << str3 << '\n';

	//Конкатенация строк
	str3 = str1 + str2;
	cout << str3 << '\n';

	//Сравнение string объектов
	if (str3 > str1) cout << "str3 > str1\n";
	if (str3 == str1 + str2) cout << "str3 == str1+str2\n";

	//Присвоение string-объекту обычной строки
	str1 = "Это строка с завершающим нулем\n";
	cout << str1;

	//СОздание string объекта с помощью другого string объекта
	string str4(str1);
	cout << str4;

	//Ввод строки
	cout << "Введите строку: ";
	std::cin >> str4;
	cout << str4;

	return 0;
}
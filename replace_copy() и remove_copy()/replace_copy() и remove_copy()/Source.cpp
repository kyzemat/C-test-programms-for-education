#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::vector;

int main() {
	setlocale(LC_ALL, "ru");
	char str[] = "Это очень простой тест.";
	vector<char> v, v2(30);
	
	for (int i = 0; str[i]; i++) v.push_back(str[i]);

	cout << "Входная последовательность: ";
	for (int i = 0; i < v.size(); i++) cout << v[i];
	cout << "\n";

	remove_copy(v.begin(), v.end(), v2.begin(), 'т');

	cout << "После удаления буквы т: ";
	for (int i = 0; v2[i]; i++) cout << v2[i];
	cout << "\n\n";

	//repalce copy

	cout << "Входная последовательность: ";
	for (int i = 0; i < v.size(); i++) cout << v[i];
	cout << "\n";

	replace_copy(v.begin(), v.end(), v2.begin(), 'о', 'Х');

	cout << "После замен букв о на буквы Х: ";
	for (int i = 0; v2[i]; i++) cout << v2[i];
	cout << "\n\n";

	return 0;
}
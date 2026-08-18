#include <iostream>
#include <vector>
using std::cout;
using std::vector;


int main() {
	setlocale(LC_ALL, "ru");

	vector<int> v;
	unsigned int i;

	cout << "Размер = " << v.size() << std::endl;

	for (i = 0; i < 10; i++) v.push_back(i);

	cout << "\nТекущее содержимое:\n";
	cout << "Новый размер: " << v.size() << std::endl;

	for (i = 0; i < v.size(); i++) cout << v[i] << ' ';

	for (i = 0; i < 10; i++) v.push_back(i + 10);

	cout << "\nНовый размер: " << v.size() << std::endl;

	cout << "Текущее содержимое:\n";
	for (i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << std::endl;

	for (i = 0; i < v.size(); i++) v[i] = v[i] + v[i];

	cout << "Содержимое удвоено:\n";
	for (i = 0; i < v.size(); i++) cout << v[i] << ' ';
	cout << "\n\n\n\n";


	vector<char> v1;

	for (int i = 0; i < 10; i++) v1.push_back('A' + i);

	cout << "Размер = " << v1.size() << '\n';
	cout << "Исходное содержимое вектора:\n";
	for (int i = 0; i < v1.size(); i++) cout << v1[i] << ' ';
	cout << "\n\n";

	vector<char>::iterator p = v1.begin();
	p += 2;//УКазатель на 3 элемент

	v1.insert(p, 10, 'X');

	cout << "Размер вектора после вставки: " << v1.size() << '\n';

	cout << "Содержимое вектора после вставки:\n";
	for (int i = 0; i < v1.size(); i++) cout << v1[i] << ' ';
	cout << "\n\n";

	p = v1.begin();
	p += 2;
	v1.erase(p, p + 10);//Удаляем 10 элементов начиная с p

	cout << "Размер вектора после удаления символов: " << v1.size() << '\n';

	cout << "Содержимое вектора после удаления:\n";
	for (int i = 0; i < v1.size(); i++) cout << v1[i] << ' ';
	cout << "\n\n";

	return 0;
}
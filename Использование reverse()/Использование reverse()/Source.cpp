#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::vector;

int main() {
	setlocale(LC_ALL, "ru");

	vector<int> v;

	for (int i = 0; i < 10; i++) v.push_back(i);

	cout << "исходная последовательность: ";
	for (int i = 0; i < 10; i++) cout << v[i] << ' ';
	cout << '\n';

	reverse(v.begin(), v.end());


	cout << "реверсивная последовательность: ";
	for (int i = 0; i < 10; i++) cout << v[i] << ' ';
	cout << '\n';

	return 0;
}
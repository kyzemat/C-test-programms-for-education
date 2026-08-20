#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using std::cout;
using std::vector;

const vector<int> vowel = { 'а', 'е', 'и', 'о', 'у', 'ы', 'я', 'ё', 'ю', 'э'};

bool isvowel(char ch) {
	ch = tolower(ch);
	if (std::find(vowel.begin(), vowel.end(), ch) != vowel.end()) return true;//Если буква внутри вектора, возвращаем true
	
	return false;
}


int main() {
	system("chcp 1251");

	setlocale(LC_ALL, "ru");

	char str[] = "-- Программирование это сила!!! --";
	vector<char> v;
	
	for (int i = 0; str[i]; i++) v.push_back(str[i]);

	cout << "Последовательность: ";
	for (int i = 0; i < v.size(); i++) cout << v[i];
	cout << std::endl;

	int num_of_vowels;

	num_of_vowels = count(v.begin(), v.end(), 'м');
	cout << num_of_vowels << " символа м \n";

	num_of_vowels = count_if(v.begin(), v.end(), isvowel);
	cout << num_of_vowels << " символов представляющих гласные звуки \n";

	return 0;
}
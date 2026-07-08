#include <iostream>

template <typename type> class mass {
	int size;
	type* mas;

public:
	mass(int size) {
		if (size <= 0) {
			std::cout << "Размер должен быть больше 0!\n";
			exit(1);
		}
		mas = new type[size];
		this->size = size;
	}

	~mass() {
		delete[] mas;
	}

	mass(const mass& obj);
	mass& operator=(const mass& obj);
	type& operator[](int index);//Возвращаем ссылку, чтобы элементу можно было присваивать что-нибудь
};

template <typename type> 
mass<type>::mass(const mass& obj) {
	mas = new type[obj.size];

	size = obj.size;
	for (int i = 0; i < size; i++) {
		mas[i] = obj.mas[i];
	}
}

template <typename type>
mass<type>& mass<type>::operator=(const mass& obj) {
	if (this->size < obj.size) {
		delete[] mas;

		mas = new type[obj.size];
	}
	size = obj.size;

	for (int i = 0; i < size; i++) {
		mas[i] = obj.mas[i];
	}

	return *this;
}

template <typename type>
type& mass<type>::operator[](int index) {
	if (index<0 || index >= size) {
		std::cout << "Выход за границы массива!\n";
		exit(1);
	}
	return mas[index];
}

int main() {
	setlocale(LC_ALL, "ru");
	
	mass<int> mas1(10), mas2(20);

	for (int i = 0; i < 20; i++) {
		mas2[i] = i+10;
	}

	for (int i = 0; i < 10; i++) {
		mas1[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << mas1[i] << ' ';
	}

	mas1 = mas2;

	for (int i = 0; i < 20; i++) {
		std::cout << mas1[i] << ' ';
	}

	mass<char> mas3(10);

	for (int i = 0; i < 10; i++) {
		mas3[i] = 97 + i;
	}
	for (int i = 0; i < 20; i++) {//Выход за границы массива!
		std::cout << mas3[i] << ' ';
	}

	return 0;
}
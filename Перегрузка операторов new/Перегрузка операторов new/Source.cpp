#include <iostream>
#include <new>
#include <cstdlib>

class three_d {
	int x, y, z;
public:
	three_d() {
		x = y = z = 0;
		std::cout << "Создание объекта 0, 0, 0.\n";
	}
	three_d(int i, int j, int d) {
		x = i;
		y = j;
		z = d;

		std::cout << "Создание объекта " << i << ", " << j << ", " << d << '\n';
	}
	~three_d() { std::cout << "Разрушение объекта\n"; }
	void* operator new(size_t size);
	void* operator new[](size_t size);
	void* operator new(size_t size, const std::nothrow_t& n);
	void* operator new[](size_t size, const std::nothrow_t& n);
	void operator delete(void *p);
	void operator delete[](void* p);
	void operator delete(void* p, const std::nothrow_t& n);
	void operator delete[](void* p, const std::nothrow_t& n);

	void show();
};

void* three_d::operator new(size_t size) {
	void* p;//Указатель на неопределенный тип

	std::cout << "Выделение памяти для объекта класса three_d.\n";
	p = malloc(size);

	//Генерирование исключения в случае неудачного выделения памяти
	if (!p) {
		throw std::bad_alloc();
	}
	return p;
}

void* three_d::operator new[](size_t size) {
	void* p;

	std::cout << "Выделение памяти для массива three_d-объектов\n";

	//Генерация исключения
	p = malloc(size);
	if (!p) {
		throw std::bad_alloc();
	}
	return p;
}

void three_d::operator delete(void *p) {
	std::cout << "Удаление объекта класса three_d\n";
	free(p);
}

void three_d::operator delete[](void* p) {
	std::cout << "Удаление массива объектов типа three_d\n";
	free(p);
}

void* three_d::operator new(size_t size, const std::nothrow_t& n) {
	void* p;

	p = malloc(size);
	
	std::cout << "Выделение памяти для объекта three_d оператором new(nothrow)\n";

	if (!p) {
		std::cout << "Ошибка при выделении памяти!\n";
		return nullptr;
	}

	return p;
}

void* three_d::operator new[](size_t size, const std::nothrow_t& n) {
	void* p;

	p = malloc(size);

	std::cout << "Выделение памяти для массива объектов three_d оператором new(nothrow)\n";

	if (!p) {
		std::cout << "Ошибка при выделении памяти!\n";
		return nullptr;
	}

	return p;
}

void three_d::operator delete(void *p, const std::nothrow_t& n) {
	
	std::cout << "Освобождение памяти объекта three_d nothrow\n";

	free(p);
}

void three_d::operator delete[](void* p, const std::nothrow_t& n) {

	std::cout << "Освобождение памяти массива объектов three_d nothrow\n";

	free(p);
}

void three_d::show() {
	std::cout << x << ", " << y << ", " << z << '\n';
}

int main() {
	setlocale(LC_ALL, "ru");

	three_d* p1, * p2;

	try {
		p1 = new three_d[3];
		p2 = new three_d(5, 6, 7);
	}
	catch (std::bad_alloc ex) {
		std::cout << "Ошибка при выделении памяти\n";
		return 1;
	}

	p1[1].show();//Отображение элементов
	p2->show();

	delete[] p1;//Освобождение памяти
	delete p2;

	p1 = new(std::nothrow) three_d[4];
	p2 = new(std::nothrow) three_d(2, 3, 4);

	if (!p1 || !p2) {
		std::cout << "Произошла ошибка выделения памяти!\n";
		return 1;
	}

	p1[1].show();
	p2->show();

	delete[] p1;
	delete p2;


	return 0;
}
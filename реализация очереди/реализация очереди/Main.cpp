#include <iostream>

//Очередь
class queue {
	int sloc, rloc;
	int q[100];
public:
	void init();
	void qput(int i);
	int qget();
};

//Помещаем значение в очередь
void queue::qput(int i) {

	if (sloc == 100) {
		std::cout << "Очередь заполнена!";
		return;
	}
	sloc++;
	q[sloc] = i;
}

//Что-то типа конструктора
void queue::init() {
	rloc = sloc = 0;
}

int queue::qget() {
	if (rloc == sloc) {
		std::cout << "Очередь пуста!";
		return 0;
	}
	rloc++;
	return q[rloc];

}



int main() {
	setlocale(LC_ALL, "ru");


	queue a, b; //Инициализируем два объекта

	a.init();
	b.init();

	a.qput(10);
	a.qput(20);
	a.qput(50);

	b.qput(100);
	b.qput(200);
	b.qput(500);

	std::cout << "Содержимое очереди a: ";
	for (int i = 0; i < 3; i++) {
		std::cout << a.qget() << ' ';
	}

	std::cout << "\nСодержимое очереди b: ";
	for (int i = 0; i < 3; i++) {
		std::cout << b.qget() << ' ';
	}



	return 0;
}
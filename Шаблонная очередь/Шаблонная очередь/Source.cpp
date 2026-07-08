#include <iostream>

template <typename type> class queue {// ласс очереди
	type* q;
	int sloc, rloc, size;

public:
	queue(int size) {
		q = new type[size];
		rloc = sloc = 0;
		
		this->size = size;
	}

	~queue() {
		delete[] q;
	}

	queue(const queue& obj);// онструктор копии
	queue& operator=(const queue& obj); //ѕерегрузка оператора =
	/*я все это сделал на вс€кий случай, чисто чтобы проверить свои навыки
	* было на самом деле не очень просто, так как € забыл, что, во-первых
	* необходимо копировать все данные, а не только значение массива q
	* а также при перегрузке оператора = € забыл, что об€зательно необходимо
	* провер€ть, чтобы размер массива в который копирую был больше или равен 
	* размеру массива из которого копирую, короче надо быть внимательнее!
	*/


	void qput(type object);
	type qget();
};

template <typename type>
queue<type>::queue(const queue& obj) {// онструктор копии

	sloc = obj.sloc;
	rloc = obj.rloc;
	size = obj.size;

	q = new type[obj.size];

	for (int i = 0; i < obj.size; i++) {
		q[i] = obj.q[i];
	}

}


template <typename type>
queue<type>& queue<type>::operator=(const queue& obj) {//¬озвращаем ссылку, потому что если бы возвращали объект, то оп€ть вызывалс€ бы конструктор копии

	if (this->size < obj.size) {//≈сли размер выделенной пам€ти объекта не хватает дл€ присваивани€ - удал€ем старую пам€ть и выдел€ем новую
		delete[] q;
		q = new type[obj.size];
	}

	sloc = obj.sloc;
	rloc = obj.rloc;
	size = obj.size;// опируем все данные

	for (int i = 0; i < obj.size; i++) {// опируем очередь из правого операнда
		q[i] = obj.q[i];
	}

	return *this;
}

template <typename type>
void queue<type>::qput(type object) {
	if (sloc == this->size) {
		std::cout << "ќчередь заполнена\n";
		return;
	}

	q[sloc] = object;
	sloc++;
}

template <typename type>
type queue<type>::qget() {
	if (rloc == sloc) {
		std::cout << "ќчередь пуста\n";
		return type{};//это стандартна€ шаблонна€ заглушка дл€ возврата пустых значений разных типов данных
	}

	type temp = q[rloc];
	rloc++;
	return temp;
}


int main() {
	setlocale(LC_ALL, "ru");

	queue<int> a(100), d(100);

	a.qput(10);
	a.qput(20);
	a.qput(40);

	d.qput(100);
	d.qput(200);
	d.qput(400);

	std::cout << a.qget() << '\n' << a.qget() << '\n' << a.qget() << '\n' << a.qget() << '\n';

	a = d;

	std::cout << a.qget() << '\n' << a.qget() << '\n' << a.qget() << '\n' << a.qget() << '\n';

	queue<double> b(100);

	b.qput(3.5);
	b.qput(50.545);
	b.qput(45.545);

	std::cout << b.qget() << '\n' << b.qget() << '\n' << b.qget() << '\n' << b.qget() << '\n';

	queue<char> c(100);

	c.qput('h');
	c.qput('c');
	c.qput('d');

	std::cout << c.qget() << '\n' << c.qget() << '\n' << c.qget() << '\n' << c.qget() << '\n';


	

	return 0;
}
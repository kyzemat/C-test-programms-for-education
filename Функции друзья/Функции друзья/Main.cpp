//#include <iostream>
//
//const int IDLE = 0;
//const int INUSE = 1;
//
//class C2; // ќпережающее объ€вление
//class C1 {
//
//	int status; //IDLE если неактивно INUSE если активно
//public:
//	void set_status(int state);
//	friend int idle(C1 a, C2 b);
//
//};
//
//class C2{
//	int status;
//public:
//	void set_status(int state);
//	friend int idle(C1 a, C2 b);
//};
//
//void C1::set_status(int state) {
//	status = state;
//}
//
//void C2::set_status(int state) {
//	status = state;
//}
//
//int idle(C1 a, C2 b) {
//	if (a.status || b.status) return 0;
//	else return 1;
//}
//
//int main() {
//	setlocale(LC_ALL, "ru");
//
//	C1 x;
//	C2 y;
//
//	x.set_status(IDLE);
//	y.set_status(IDLE);
//
//	if (idle(x, y)) std::cout << "Ёкран свободен!\n";
//	else std::cout << "ќтображаетс€ сообщение!\n";
//
//	x.set_status(INUSE);
//
//	if (idle(x, y)) std::cout << "Ёкран свободен!\n";
//	else std::cout << "ќтображаетс€ сообщение!\n";
//
//	return 0;
//}
#include <iostream>

const int IDLE = 0;
const int INUSE = 1;

class C2; // ќпережающее объ€вление
class C1 {

	int status; //IDLE если неактивно INUSE если активно
public:
	void set_status(int state);
	int idle(C2 b);

};

class C2 {
	int status;
public:
	void set_status(int state);
	friend int C1::idle(C2 b);//ќбатите внимание на то, как объ€вл€етс€ данна€ функци€-друг
};

void C1::set_status(int state) {
	status = state;
}

void C2::set_status(int state) {
	status = state;
}

int C1::idle(C2 b) {
	if (status || b.status) return 0;
	else return 1;
}

int main() {
	setlocale(LC_ALL, "ru");

	C1 x;
	C2 y;

	x.set_status(IDLE);
	y.set_status(IDLE);

	if (x.idle(y)) std::cout << "Ёкран свободен!\n";
	else std::cout << "ќтображаетс€ сообщение!\n";

	x.set_status(INUSE);

	if (x.idle( y)) std::cout << "Ёкран свободен!\n";
	else std::cout << "ќтображаетс€ сообщение!\n";

	return 0;
}
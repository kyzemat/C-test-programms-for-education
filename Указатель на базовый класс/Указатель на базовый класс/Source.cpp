#include <iostream>
#include <cstring>

class B {
	char author[200]; 
public:
	void put_author(const char* s) { strcpy_s(author, s); }
	void show_author() { std::cout << author << "\n"; }
};

class D : public B {
	char title[200];
public:
	void put_title(const char* t) { strcpy_s(title, t); }
	void show_title() { std::cout << "Название: " << title << "\n"; }
};

int main() {
	setlocale(LC_ALL, "ru");

	B* p;
	B B_ob;

	D* dp;
	D D_ob;

	p = &B_ob;

	//Доступ к классу B через указатель
	p->put_author("Эрих Мария Ремарк");

	p = &D_ob;
	p->put_author("Федор Михайлович Достоевский");

	B_ob.show_author();
	D_ob.show_author();
	std::cout << "\n";

	/*Так как Put_title и show_title не являются
	членами класса B мы не можем к ним обратиться 
	через указатель p, поэтому используем указатель
	dp*/

	dp = &D_ob;

	dp->put_title("\"Братья Карамазовы\"");

	p->show_author();
	dp->show_title();

	return 0;
}
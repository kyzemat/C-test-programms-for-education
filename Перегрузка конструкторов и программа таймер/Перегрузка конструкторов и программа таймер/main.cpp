#include <iostream>
#include <cstdlib>
#include <ctime>

class timer {
	int seconds;
public: 
	timer(const char* t) { seconds = atoi(t); }
	timer(int t) { seconds = t; }
	timer(int min, int sec) { seconds = min * 60 + sec; }

	void run();

};

void timer::run() {

	clock_t t1;

	t1 = clock();
	
	while ((clock() - t1 )/CLOCKS_PER_SEC<seconds); //Проверяем что количество секунд прошедших с проверки больше или меньше того, сколько задано тааймером
	std::cout << "Таймер завершен!\n" << '\a';
}

int main() {
	setlocale(LC_ALL, "ru");


	timer a(10), b("20"), c(1, 10);

	a.run();
	b.run();
	c.run();

	return 0;

}
#include <iostream>

using std::cout;

namespace CounterNameSpace {//ќпредел€ем пространство имен
	int upperbound;
	int lowerbound;

	class counter {
		int count;
	public:
		counter(int n) {
			if (n <= upperbound) count = n;
			else count = upperbound;
		}

		void reset(int n) {
			if (n <= upperbound) count = n;
		}

		int run() {
			if (count > lowerbound) return count--;
			else return lowerbound;
		}
	};
}

int main() {
	using CounterNameSpace::upperbound;//ƒелаем upperbound видимым

	upperbound = 100;//¬алидно, так как upperbound есть в глобальном пространстве имен
	CounterNameSpace::lowerbound = 0;//ј вот тут надо указывать пространство имен

	CounterNameSpace::counter ob1(10);
	int i;

	do {
		i = ob1.run();
		cout << i << " ";
	} while (i > CounterNameSpace::lowerbound);
	cout << std::endl;

	using namespace CounterNameSpace;//ƒелаем видимым все пространство имен
	
	//ƒальше все переменные из этого пространства имен можно указывать без уточнени€ области видимости

	counter ob2(20);

	do {
		i = ob2.run();
		cout << i << " "; 
	} while (i > lowerbound);
	cout << std::endl;

	ob2.reset(100);
	lowerbound = 90;

	do {
		i = ob2.run();
		cout << i << ' ';
	} while (i > lowerbound);

	return 0;
}
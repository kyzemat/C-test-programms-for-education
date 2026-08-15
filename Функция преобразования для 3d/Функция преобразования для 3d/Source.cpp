#include <iostream>
using std::cout;

class three_d {
	int x, y, z;
public:
	three_d() { x = y = z = 0; }
	three_d(int a, int b, int c) { x = a; y = b; z = c; }

	three_d operator+(three_d op2);
	friend std::ostream& operator<<(std::ostream& stream, three_d& obj);
	three_d& operator=(const three_d& op2);

	operator int() const { return x * y * z; }
};

three_d& three_d::operator=(const three_d& op2) {
	x = op2.x;
	y = op2.y;
	z = op2.z;

	return *this;
}


three_d three_d::operator+(three_d op2) {
	three_d temp;

	temp.x = x + op2.x;
	temp.y = y + op2.y;
	temp.z = z + op2.z;

	return temp;
}

std::ostream& operator<<(std::ostream& stream, three_d& obj) {

	stream << obj.x << ' ' << obj.y << ' ' << obj.z << '\n';

	return stream;
}

int main() {
	setlocale(LC_ALL, "ru");

	three_d a(1, 2, 3), b(4, 5, 6), c(7, 8, 9);
	int result;
	 

	cout << a << b << c;

	a = b + c;

	cout << a;

	result = a+b+c;

	cout << result;

	cout << '\n' << b + 100;

	return 0;
}
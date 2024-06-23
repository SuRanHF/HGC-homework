#include <iostream>
using namespace std;

class Point
{
	int _x, _y;
public:
	Point(int x = 0, int y = 0) : _x(x), _y(y) {}
	Point& operator++();
	Point operator++(int);
	Point& operator--();
	Point operator--(int);
	friend ostream& operator << (ostream& o, const Point& p);
};

/********** Begin **********/

// 前置递增运算符  
Point& Point::operator++() {
	_x++;
	_y++;
	return *this;
}

// 后置递增运算符  
Point Point::operator++(int) {
	Point temp(*this);
	++(*this); // 调用前置递增运算符  
	return temp;
}

// 前置递减运算符  
Point& Point::operator--() {
	_x--;
	_y--;
	return *this;
}

// 后置递减运算符  
Point Point::operator--(int) {
	Point temp(*this);
	--(*this); // 调用前置递减运算符  
	return temp;
}

/**********  End  **********/

// 剩下的部分保持不变

ostream& operator << (ostream& o, const Point& p) {
	o << '(' << p._x << ", " << p._y << ')';
	return o;
}

int main()
{
	int x, y;
	cin >> x >> y;
	Point p(x, y);
	cout << p << endl;
	cout << p++ << endl;
	cout << ++p << endl;
	cout << p-- << endl;
	cout << --p << endl;
	return 0;
}

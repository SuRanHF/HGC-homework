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

// ǰ�õ��������  
Point& Point::operator++() {
	_x++;
	_y++;
	return *this;
}

// ���õ��������  
Point Point::operator++(int) {
	Point temp(*this);
	++(*this); // ����ǰ�õ��������  
	return temp;
}

// ǰ�õݼ������  
Point& Point::operator--() {
	_x--;
	_y--;
	return *this;
}

// ���õݼ������  
Point Point::operator--(int) {
	Point temp(*this);
	--(*this); // ����ǰ�õݼ������  
	return temp;
}

/**********  End  **********/

// ʣ�µĲ��ֱ��ֲ���

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

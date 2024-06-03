#include <iostream>
using namespace std;

class Animal {
	/********** Begin **********/
public:
	int age;
	/********** End **********/

};

class Dog : public Animal {
public:
	void SetAge(int n) { age = n; }

	void ShowAge() { cout << age; }
};

int main()
{
	int n;
	Dog d;
	cin >> n;
	d.SetAge(n);
	d.ShowAge();
	return 0;
}

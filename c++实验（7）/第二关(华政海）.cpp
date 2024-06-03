#include <iostream>  
using namespace std;

class BaseClass {
    /********** Begin **********/
private:
    int Number;

public:
    BaseClass(int num = 0) : Number(num) {
        cout << "Construction. Number = " << Number << endl;
    }

    ~BaseClass() {
        Number = 0; // 在析构函数中设置Number为0，但这里输出通常发生在Number被销毁之后  
        cout << "Destruction. Number = " << Number << endl; // 这里的Number值可能不是0，因为输出在销毁成员之后  
    }
    /********** End **********/
};

class DerivedClass : public BaseClass {
    /********** Begin **********/
public:
    // 如果没有特殊需求，派生类不需要显式定义构造函数和析构函数  
    // 如果需要，可以在这里添加，并调用基类的构造函数  
    // 例如：  
    // DerivedClass() : BaseClass(1) {} // 显式调用基类的构造函数，并传入1作为Number的初始值  
    DerivedClass(int num) : BaseClass(num) {}
    /********** End **********/
};

int main()
{
    DerivedClass d(1); // 创建DerivedClass对象d时，会调用BaseClass的构造函数，并传入1作为参数  
    return 0; // 程序结束，DerivedClass对象d的析构函数会被调用，然后BaseClass的析构函数也会被调用  
}
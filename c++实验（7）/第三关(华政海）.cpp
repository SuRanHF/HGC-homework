#include <iostream>  
using namespace std;

// Vehicle 基类，设置为虚基类  
class Vehicle {
public:
    int MaxSpeed;
    int Weight;

    // 虚函数，可以被派生类覆盖  
    virtual void Run() {
        cout << "Vehicle run" << endl;
    }

    virtual void Stop() {
        cout << "Vehicle stop" << endl;
    }

    // 其他成员函数和成员变量...  
};

// Bicycle 类，虚继承自 Vehicle  
class Bicycle : virtual public Vehicle {
public:
    int Height;

    // 覆盖 Run 方法  
    void Run() override {
        cout << "Bicycle run" << endl;
    }

    // 其他成员函数和成员变量...  
};

// Motorcar 类，虚继承自 Vehicle  
class Motorcar : virtual public Vehicle {
public:
    int SeatNum;

    // 覆盖 Stop 方法  
    void Stop() override {
        cout << "Motorcar stop" << endl;
    }

    // 其他成员函数和成员变量...  
};

// Motorcycle 类，从 Bicycle 和 Motorcar 派生  
class Motorcycle : public Bicycle, public Motorcar {
    // 如果 Motorcycle 需要特有的行为或属性，可以在这里定义  
};

int main()
{
    Motorcycle motorcycle;
    motorcycle.Run(); // 调用 Bicycle 的 Run 方法  
    motorcycle.Stop(); // 调用 Motorcar 的 Stop 方法  
    return 0;
}
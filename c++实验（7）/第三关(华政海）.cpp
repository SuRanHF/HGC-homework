#include <iostream>  
using namespace std;

// Vehicle ���࣬����Ϊ�����  
class Vehicle {
public:
    int MaxSpeed;
    int Weight;

    // �麯�������Ա������า��  
    virtual void Run() {
        cout << "Vehicle run" << endl;
    }

    virtual void Stop() {
        cout << "Vehicle stop" << endl;
    }

    // ������Ա�����ͳ�Ա����...  
};

// Bicycle �࣬��̳��� Vehicle  
class Bicycle : virtual public Vehicle {
public:
    int Height;

    // ���� Run ����  
    void Run() override {
        cout << "Bicycle run" << endl;
    }

    // ������Ա�����ͳ�Ա����...  
};

// Motorcar �࣬��̳��� Vehicle  
class Motorcar : virtual public Vehicle {
public:
    int SeatNum;

    // ���� Stop ����  
    void Stop() override {
        cout << "Motorcar stop" << endl;
    }

    // ������Ա�����ͳ�Ա����...  
};

// Motorcycle �࣬�� Bicycle �� Motorcar ����  
class Motorcycle : public Bicycle, public Motorcar {
    // ��� Motorcycle ��Ҫ���е���Ϊ�����ԣ����������ﶨ��  
};

int main()
{
    Motorcycle motorcycle;
    motorcycle.Run(); // ���� Bicycle �� Run ����  
    motorcycle.Stop(); // ���� Motorcar �� Stop ����  
    return 0;
}
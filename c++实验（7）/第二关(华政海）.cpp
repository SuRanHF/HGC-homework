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
        Number = 0; // ����������������NumberΪ0�����������ͨ��������Number������֮��  
        cout << "Destruction. Number = " << Number << endl; // �����Numberֵ���ܲ���0����Ϊ��������ٳ�Ա֮��  
    }
    /********** End **********/
};

class DerivedClass : public BaseClass {
    /********** Begin **********/
public:
    // ���û���������������಻��Ҫ��ʽ���幹�캯������������  
    // �����Ҫ��������������ӣ������û���Ĺ��캯��  
    // ���磺  
    // DerivedClass() : BaseClass(1) {} // ��ʽ���û���Ĺ��캯����������1��ΪNumber�ĳ�ʼֵ  
    DerivedClass(int num) : BaseClass(num) {}
    /********** End **********/
};

int main()
{
    DerivedClass d(1); // ����DerivedClass����dʱ�������BaseClass�Ĺ��캯����������1��Ϊ����  
    return 0; // ���������DerivedClass����d�����������ᱻ���ã�Ȼ��BaseClass����������Ҳ�ᱻ����  
}
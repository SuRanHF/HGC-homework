#include <iostream>
#include <cmath>
using namespace std;

int max1(int x, int y); //�������������ֵ

int max1(int x, int y, int z);//�������������ֵ

double max1(double x, double y);//����˫�����������ֵ

double max1(double x, double y, double z);//����˫�����������ֵ


int main()
{
    int a, b, c;
    double m, n, l;


    cin >> a;


    cin >> b;


    cin >> c;

    cout << "\n";

    cout << "max of " << a << " and " << b << " is " << max1(a, b) << endl;

    cout << "max of " << a << ", " << b << " and " << c << " is " << max1(a, b, c) << endl;

    cout << "\n\n";


    cin >> m;


    cin >> n;


    cin >> l;

    cout << "\n";

    cout << "max of " << m << " and " << n << " is " << max1(m, n) << endl;

    cout << "max of " << m << ", " << n << " and " << l << " is " << max1(m, n, l) << endl;


    return 0;
}


int max1(int x, int y) //�������������ֵ
{
    //*******************��Ѵ��벹������begin**********
    if (x > y)

        return x;
    else
        return y;






    //*********************************end***************

}


int max1(int x, int y, int z)//�������������ֵ
{
    //*******************��Ѵ��벹������begin**********
    if (x > y && x > z)
        return x;
    if (y > x && y > z)
        return y;
    if (z > x && z > y)
        return z;

    //*********************************end***************

}

double max1(double x, double y)//����˫�����������ֵ
{
    //*******************��Ѵ��벹������begin**********
    if (x > y)
        return x;
    if (y > x)
        return y;




    //*********************************end***************


}

double max1(double x, double y, double z)//����˫�����������ֵ
{
    //*******************��Ѵ��벹������begin**********

    if (x > y && x > z)
        return x;
    if (y > x && y > z)
        return y;
    if (z > x && z > y)
        return z;






    //*********************************end***************

}





----------------------------------
#include <iostream>
#include <cmath>
using namespace std;

struct complex
{
    double real;
    double image;
};

int fun(unsigned int n, int& zero) {
    unsigned int maxNum = 0; // ��Ϊ unsigned int ����  
    zero = 0;
    while (n > 0) {
        if (n % 10 == 0) {
            zero++;
        }
        // ʹ���������ʽ����ֱ������ת�����������Ͳ�ƥ��  
        maxNum = (maxNum > n % 10) ? maxNum : n % 10; // �������ʽ  
        // ����  
        // maxNum = static_cast<unsigned int>(max(static_cast<int>(maxNum), static_cast<int>(n % 10))); // ��ʽ����ת��  
        n /= 10;
    }
    return static_cast<int>(maxNum); // �����Ҫ���� int ����  
}
int fun(int n, int& zero) {
    unsigned absN = (n < 0) ? -n : n; // ת��Ϊ�޷������Ա㴦��  
    return fun(absN, zero); // �����޷��������汾��fun  
}

int fun(double d, int& zero) {
    int num = round(d); // ��������Ϊ����  
    return fun(static_cast<unsigned>(num), zero); // �����޷��������汾��fun  
}
int fun(complex c, int& zero) {
    return fun(static_cast<int>(round(c.real)), zero); // ��ͳ��ʵ�����������з��������汾��fun  
}
int main()
{
    unsigned uNum;
    int iNum;
    int zero, max;
    double dNum;
    complex c;
    //cout<<"\nEnter an unsigned number:";
    cin >> uNum;
    max = fun(uNum, zero);
    cout << "The result of unsigned: max=" << max << " zero=" << zero << endl;

    //cout<<"\nEnter a signed number:";
    cin >> iNum;
    max = fun(iNum, zero);
    cout << "The result of int: max=" << max << " zero=" << zero << endl;

    //cout<<"\nEnter a double:";
    cin >> dNum;
    max = fun(dNum, zero);
    cout << "The result of double: max=" << max << " zero=" << zero << endl;

    //cout<<"\nEnter a complex:";
    cin >> c.real >> c.image;
    max = fun(c, zero);
    cout << "The result of complex: max=" << max << " zero=" << zero << endl;
    return 0;
}
--------------------------------------
#include <iostream>
using namespace std;
struct complex
{
    double real;
    double imaginary;
};
//ʵ�������������
int add(int a, int b)
{
    //****************begin**********//
    return a + b;



    //***************end************//

}

//ʵ������ʵ�����
double add(double c, double d)
{
    //****************begin**********//

    return c + d;


    //***************end************//

}
//ʵ�������������
//ʵ�������������  
complex add(complex c_1, complex c_2)
{
    //****************begin**********//  
    complex result; // ����һ���ֲ��������洢���  
    result.real = c_1.real + c_2.real;
    result.imaginary = c_1.imaginary + c_2.imaginary;
    return result; // ���ؽ��  
    //***************end************//  
}

int main()
{
    int a, b;
    double c, d;
    complex c_1, c_2, c3;


    //������������
    cin >> a >> b;

    //��������С��
    cin >> c >> d;

    //�����һ��ʵ����ʵ�����鲿
    cin >> c_1.real >> c_1.imaginary;
    //����ڶ���ʵ����ʵ�����鲿
    cin >> c_2.real >> c_2.imaginary;
    //�������������ӵ�ֵ
    cout << add(a, b) << endl;
    //�������ʵ����ӵ�ֵ
    cout << add(c, d) << endl;
    c3 = add(c_1, c_2);
    //�������������Ӻ��ʵ�����鲿ֵ
    cout << c3.real << ',' << c3.imaginary << "\n";
}
#include <iostream>
#include <cmath>
using namespace std;

int max1(int x, int y); //两个整数的最大值

int max1(int x, int y, int z);//三个整数的最大值

double max1(double x, double y);//两个双精度数的最大值

double max1(double x, double y, double z);//三个双精度数的最大值


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


int max1(int x, int y) //两个整数的最大值
{
    //*******************请把代码补充完整begin**********
    if (x > y)

        return x;
    else
        return y;






    //*********************************end***************

}


int max1(int x, int y, int z)//三个整数的最大值
{
    //*******************请把代码补充完整begin**********
    if (x > y && x > z)
        return x;
    if (y > x && y > z)
        return y;
    if (z > x && z > y)
        return z;

    //*********************************end***************

}

double max1(double x, double y)//两个双精度数的最大值
{
    //*******************请把代码补充完整begin**********
    if (x > y)
        return x;
    if (y > x)
        return y;




    //*********************************end***************


}

double max1(double x, double y, double z)//三个双精度数的最大值
{
    //*******************请把代码补充完整begin**********

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
    unsigned int maxNum = 0; // 改为 unsigned int 类型  
    zero = 0;
    while (n > 0) {
        if (n % 10 == 0) {
            zero++;
        }
        // 使用条件表达式或者直接类型转换来避免类型不匹配  
        maxNum = (maxNum > n % 10) ? maxNum : n % 10; // 条件表达式  
        // 或者  
        // maxNum = static_cast<unsigned int>(max(static_cast<int>(maxNum), static_cast<int>(n % 10))); // 显式类型转换  
        n /= 10;
    }
    return static_cast<int>(maxNum); // 如果需要返回 int 类型  
}
int fun(int n, int& zero) {
    unsigned absN = (n < 0) ? -n : n; // 转换为无符号数以便处理  
    return fun(absN, zero); // 调用无符号整数版本的fun  
}

int fun(double d, int& zero) {
    int num = round(d); // 四舍五入为整数  
    return fun(static_cast<unsigned>(num), zero); // 调用无符号整数版本的fun  
}
int fun(complex c, int& zero) {
    return fun(static_cast<int>(round(c.real)), zero); // 仅统计实部，并调用有符号整数版本的fun  
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
//实现两个整数相加
int add(int a, int b)
{
    //****************begin**********//
    return a + b;



    //***************end************//

}

//实现两个实数相加
double add(double c, double d)
{
    //****************begin**********//

    return c + d;


    //***************end************//

}
//实现两个复数相加
//实现两个复数相加  
complex add(complex c_1, complex c_2)
{
    //****************begin**********//  
    complex result; // 定义一个局部变量来存储结果  
    result.real = c_1.real + c_2.real;
    result.imaginary = c_1.imaginary + c_2.imaginary;
    return result; // 返回结果  
    //***************end************//  
}

int main()
{
    int a, b;
    double c, d;
    complex c_1, c_2, c3;


    //输入两个整数
    cin >> a >> b;

    //输入两个小数
    cin >> c >> d;

    //输入第一个实数的实部和虚部
    cin >> c_1.real >> c_1.imaginary;
    //输入第二个实数的实部和虚部
    cin >> c_2.real >> c_2.imaginary;
    //输出两个整数相加的值
    cout << add(a, b) << endl;
    //输出两个实数相加的值
    cout << add(c, d) << endl;
    c3 = add(c_1, c_2);
    //输出两个复数相加后的实部和虚部值
    cout << c3.real << ',' << c3.imaginary << "\n";
}
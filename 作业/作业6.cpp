#include <iostream>
#include <cstdlib>
using namespace std;
class CDate {
	int m_nDay;
	int m_nMonth;
	int m_nYear;
public:
	CDate() {};
	CDate(int year, int month, int day)
	{
		SetDate(year, month, day);
	};
	void Display();
	void AddDay();
	void SetDate(int year, int month, int day)
	{
		m_nYear = year;
		m_nMonth = month;
		m_nDay = day;
	};
	~CDate() {};
private:
	bool IsLeapYear();
};
void CDate::Display()
{

	cout << m_nDay << "/" << m_nMonth << "/" << m_nYear << endl;
}

bool CDate::IsLeapYear()
{
	if (((m_nYear % 4 == 0) && (m_nYear % 100 != 0))
		|| (m_nYear % 400 == 0))
		return true;
	else
		return false;
}
void CDate::AddDay()
{
	// 首先，增加一天  
	m_nDay++;

	// 检查月份是否溢出  
	// 如果是2月，需要特殊处理闰年  
	if (m_nMonth == 2 && m_nDay > (IsLeapYear() ? 29 : 28)) {
		m_nDay = 1;
		m_nMonth++;
	}
	// 对于其他月份，检查是否超过该月的天数  
	else if (m_nMonth == 4 || m_nMonth == 6 || m_nMonth == 9 || m_nMonth == 11) { // 30天的月份  
		if (m_nDay > 30) {
			m_nDay = 1;
			m_nMonth++;
		}
	}
	else if (m_nMonth == 12) { // 12月  
		if (m_nDay > 31) {
			m_nDay = 1;
			m_nMonth = 1; // 重置月份为1月  
			m_nYear++; // 增加年份  
		}
	}
	else { // 其他月份（1, 3, 5, 7, 8, 10）都是31天  
		if (m_nDay > 31) {
			m_nDay = 1;
			m_nMonth++;
		}
	}
}
int main()
{
	int year, month, day;
	//cout << "Please Input Current date：";
	cin >> year >> month >> day;

	CDate d(year, month, day);
	d.Display();
	d.AddDay();
	cout << "Add 1 to Current date:";
	d.Display();



	return 0;
}
--------------------------
#include <iostream>
using namespace std;

const float PI = 3.141593;		//给出p的值
const float FENCE_PRICE = 35;	//栅栏的单价
const float CONCRETE_PRICE = 20;//过道水泥单价

class Circle {	//声明定义类Circle 及其数据和方法
public:		//外部接口
	Circle(float r);		//构造函数
	float circumference();	//计算圆的周长
	float area();			//计算圆的面积
private:	//私有数据成员
	float radius;			//圆半径
};

//类的实现

//构造函数初始化数据成员radius
Circle::Circle(float r) {
	radius = r; // 直接给radius赋值  
}

// 计算圆的周长  
float Circle::circumference() {
	return 2 * PI * radius; // 圆的周长公式：2 * π * r  
}

// 计算圆的面积  
float Circle::area() {
	return PI * radius * radius; // 圆的面积公式：π * r^2  
}

//主函数实现
int main() {
	float radius;
	//cout << "Enter the radius of the pool: ";	 // 提示用户输入半径
	cin >> radius;

	Circle pool(radius);		//游泳池边界
	Circle poolRim(radius + 3);	//栅栏

	//计算栅栏造价并输出
	float fenceCost = poolRim.circumference() * FENCE_PRICE;
	cout << "Fencing Cost is $" << fenceCost << endl;

	//计算过道造价并输出
	float concreteCost = (poolRim.area() - pool.area()) * CONCRETE_PRICE;
	cout << "Concrete Cost is $" << concreteCost << endl;

	return 0;
}
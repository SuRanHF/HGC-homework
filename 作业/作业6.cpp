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
	// ���ȣ�����һ��  
	m_nDay++;

	// ����·��Ƿ����  
	// �����2�£���Ҫ���⴦������  
	if (m_nMonth == 2 && m_nDay > (IsLeapYear() ? 29 : 28)) {
		m_nDay = 1;
		m_nMonth++;
	}
	// ���������·ݣ�����Ƿ񳬹����µ�����  
	else if (m_nMonth == 4 || m_nMonth == 6 || m_nMonth == 9 || m_nMonth == 11) { // 30����·�  
		if (m_nDay > 30) {
			m_nDay = 1;
			m_nMonth++;
		}
	}
	else if (m_nMonth == 12) { // 12��  
		if (m_nDay > 31) {
			m_nDay = 1;
			m_nMonth = 1; // �����·�Ϊ1��  
			m_nYear++; // �������  
		}
	}
	else { // �����·ݣ�1, 3, 5, 7, 8, 10������31��  
		if (m_nDay > 31) {
			m_nDay = 1;
			m_nMonth++;
		}
	}
}
int main()
{
	int year, month, day;
	//cout << "Please Input Current date��";
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

const float PI = 3.141593;		//����p��ֵ
const float FENCE_PRICE = 35;	//դ���ĵ���
const float CONCRETE_PRICE = 20;//����ˮ�൥��

class Circle {	//����������Circle �������ݺͷ���
public:		//�ⲿ�ӿ�
	Circle(float r);		//���캯��
	float circumference();	//����Բ���ܳ�
	float area();			//����Բ�����
private:	//˽�����ݳ�Ա
	float radius;			//Բ�뾶
};

//���ʵ��

//���캯����ʼ�����ݳ�Աradius
Circle::Circle(float r) {
	radius = r; // ֱ�Ӹ�radius��ֵ  
}

// ����Բ���ܳ�  
float Circle::circumference() {
	return 2 * PI * radius; // Բ���ܳ���ʽ��2 * �� * r  
}

// ����Բ�����  
float Circle::area() {
	return PI * radius * radius; // Բ�������ʽ���� * r^2  
}

//������ʵ��
int main() {
	float radius;
	//cout << "Enter the radius of the pool: ";	 // ��ʾ�û�����뾶
	cin >> radius;

	Circle pool(radius);		//��Ӿ�ر߽�
	Circle poolRim(radius + 3);	//դ��

	//����դ����۲����
	float fenceCost = poolRim.circumference() * FENCE_PRICE;
	cout << "Fencing Cost is $" << fenceCost << endl;

	//���������۲����
	float concreteCost = (poolRim.area() - pool.area()) * CONCRETE_PRICE;
	cout << "Concrete Cost is $" << concreteCost << endl;

	return 0;
}
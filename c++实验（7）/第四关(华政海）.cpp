#include <iostream>
#include <cstring>
using namespace std;

class Date
{
public:
	int year;
	int month;
	int day;
	Date() { year = 1900; month = 1; day = 1; }
	Date(int y, int m, int d) : year(y), month(m), day(d) {}
	//	Date(const Date& b) {year = b.year; month = b.month; day = b.day;}
};

class people
{
	char name[11];
	char number[7];
	char sex[3];
	Date birth;
	char id[16];
public:
	char* getName() { return name; }
	char* getNumber() { return number; }
	char* getSex() { return sex; }
	Date getBirth() { return birth; }
	char* getId() { return id; }
	people() {}
	people(const char* nm, const char* no, const char* gd, Date b, const char* i) : birth(b) {
		strcpy(name, nm);
		strcpy(number, no);
		strcpy(sex, gd);
		strcpy(id, i);
	}
};

class teacher : virtual public people
{
	char principalship[11];
	char department[21];
public:
	char* getPs() { return principalship; }
	char* getDpm() { return department; }
	teacher() {}
	teacher(const char* ps, const char* dpm) {
		strcpy(principalship, ps);
		strcpy(department, dpm);
	}
	teacher(const char* nm, const char* no, const char* gd, Date b, const char* i, const char* ps, const char* dpm) : people(nm, no, gd, b, i) {
		strcpy(principalship, ps);
		strcpy(department, dpm);
	}
};

class student : virtual public people
{
	char classNO[7];
public:
	char* getClassNO() { return classNO; }
	student() {}
	student(const char* cln) { strcpy(classNO, cln); }
	student(const char* nm, const char* no, const char* gd, Date b, const char* i, const char* cln) : people(nm, no, gd, b, i) {
		strcpy(classNO, cln);
	}
};

class graduate : public student
{
	char subject[21];
	teacher adviser;
public:
	char* getSubject() { return subject; }
	teacher getAdviser() { return adviser; }
	graduate() {}
	graduate(const char* sbj, teacher adv) : adviser(adv) { strcpy(subject, sbj); }
	graduate(const char* cln, const char* sbj, teacher adv) : student(cln), adviser(adv) { strcpy(subject, sbj); }
	graduate(const char* nm, const char* no, const char* gd, Date b, const char* i, const char* cln, const char* sbj, teacher adv) :
		student(nm, no, gd, b, i, cln), adviser(adv) {
		strcpy(subject, sbj);
	}
};

class TA : public graduate, public teacher
{
public:
	TA() {}
	TA(const char* nm, const char* no, const char* gd, Date b, const char* i, const char* ps, const char* dpm, const char* cln, const char* sbj, teacher adv) :
		people(nm, no, gd, b, i), teacher(ps, dpm), graduate(cln, sbj, adv) {}
};

int main()
{
	// ����һ����ʦʵ��  
	teacher zhengLi("Zheng Li", "1001", "Female", Date(1978, 1, 1), "1234567890", "professor", "CST");

	// ����һ������ʵ��  
	// ע�⣺���ﲻ��ֱ��ʹ��zhengLi������Ϊadviser����Ϊgraduate��Ҫһ��teacher���͵Ŀ���  
	// �������Ǵ���һ���µ�teacher��������������zhengLi��ͬ  
	teacher advisorCopy("Zheng Li", "1001", "Female", Date(1978, 1, 1), "1234567890", "professor", "CST"); // ����advisor�ĸ�����Ϣ�ͽ�ʦ��ͬ  
	TA ta("Li Chao", "011401", "Male", Date(1988, 6, 1), "12345619880601", "TA", "CST", "cst61", "computer science", advisorCopy);

	/********** End **********/
	cout << "TA name: " << ta.getName() << endl;
	cout << "No.: " << ta.getNumber() << endl;
	cout << "Department: " << ta.getDpm() << endl;
	cout << "Class No.: " << ta.getClassNO() << endl;
	cout << "Subject: " << ta.getSubject() << endl;
	cout << "Advisor: " << ta.getAdviser().getName() << endl;
	return 0;
}

#include <iostream>
using namespace std;


/********** Begin **********/
class Vehicle
{
public:
	virtual void Run() { cout << "vehicle run!" << endl; }
	virtual void Stop() { cout << "vehicle stop!" << endl; }
};
class  Bicycle : public virtual Vehicle
{
public:
	void Run() { cout << "bicycle run!" << endl; }
	void Stop() { cout << "bicycle stop!" << endl; }
};
class Motorcar : public  virtual Vehicle
{
public:
	void Run() { cout << "motocar run!" << endl; }
	void Stop() { cout << "motocar stop!" << endl; }
};
/**********  End  **********/

class Motorcycle : public  virtual Bicycle, public virtual Motorcar
{
public:
	void Run() { cout << "motocycle run!" << endl; }
	void Stop() { cout << "motocycle stop!" << endl; }
};

int main()
{
	Vehicle v;
	v.Run();
	v.Stop();
	Bicycle b;
	b.Run();
	b.Stop();
	Motorcar m;
	m.Run();
	m.Stop();
	Motorcycle mc;
	mc.Run();
	mc.Stop();
	Vehicle* vp = &v;
	vp->Run();
	vp->Stop();
	vp = &b;
	vp->Run();
	vp->Stop();
	vp = &m;
	vp->Run();
	vp->Stop();
	vp = &mc;
	vp->Run();
	vp->Stop();
	return 0;
}


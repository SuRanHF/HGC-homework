#include 
using namespace std;
class CSample
{
    int i;
public:
    CSample() { i = 1; cout << i++; }
    void disp() { cout << ++i; }
    ~CSample() { cout << i++; }
};
int  main()
{
    CSample s;
    s.disp();
    return 0;
}
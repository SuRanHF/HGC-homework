#include <iostream>    
#include <string>    
using namespace std;  
  
int main()    
{    
    string s1, s2;   
    cin >> s1 >> s2;   
    /********** Begin **********/  
    string s3 = s1 + s2; // 连接s1和s2  
    cout << s3 << endl;  // 输出连接后的字符串  
    /********** End **********/  
    return 0;    
}
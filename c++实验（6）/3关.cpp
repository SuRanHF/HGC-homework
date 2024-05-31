#include <iostream>    
using namespace std;  
  
char* link(char* a, char* b)   
{    
    /********** Begin **********/  
    // 计算a和b的长度  
    int lenA = 0, lenB = 0;  
    while (a[lenA] != '\0') lenA++;  
    while (b[lenB] != '\0') lenB++;  
  
    // 分配足够的内存来存储连接后的字符串  
    char* result = new char[lenA + lenB + 1]; // 加1是为了存储末尾的'\0'  
  
    // 将字符串a复制到result  
    for (int i = 0; i < lenA; i++) {  
        result[i] = a[i];  
    }  
  
    // 将字符串b追加到result的末尾  
    for (int i = 0; i < lenB; i++) {  
        result[lenA + i] = b[i];  
    }  
  
    // 在连接后的字符串末尾添加'\0'  
    result[lenA + lenB] = '\0';  
  
    return result;  
    /********** End **********/  
}  
  
int main()    
{    
    char a[128], b[128];    
  
    cin >> a >> b;  
  
    // 注意：link函数返回的指针是动态分配的，  
    // 因此在main函数结束时，我们需要手动释放内存  
    char* linkedStr = link(a, b);  
    cout << linkedStr << endl;  
    delete[] linkedStr; // 释放内存  
  
    return 0;    
}
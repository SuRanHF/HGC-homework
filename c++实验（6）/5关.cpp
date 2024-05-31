#include <iostream>  
#include <cstring> // 引入字符串操作函数  
  
using namespace std;  
  
class Employee {  
    char* name;    
    char* address;    
    char* city;    
    char* code;    
  
public:  
    Employee(char* n = "", char* add = "", char* ct = "", char* cd = "")   
    : name(new char[strlen(n) + 1]), address(new char[strlen(add) + 1]), city(new char[strlen(ct) + 1]), code(new char[strlen(cd) + 1])  
    {  
        /********** Begin **********/  
        strcpy(name, n);  
        strcpy(address, add);  
        strcpy(city, ct);  
        strcpy(code, cd);  
        /********** End **********/  
    }  
  
    ~Employee() // 析构函数，用于释放内存  
    {  
        delete[] name;  
        delete[] address;  
        delete[] city;  
        delete[] code;  
    }  
  
    void display()  
    {  
        /********** Begin **********/  
        cout << "name: " << name << endl;  
        cout << "address: " << address << endl;  
        cout << "city: " << city << endl;  
        cout << "code: " << code << endl;  
        /********** End **********/  
    }  
  
    void change_name(char* nm)  
    {  
        /********** Begin **********/  
        delete[] name; // 释放旧名字的内存  
        name = new char[strlen(nm) + 1]; // 分配新名字的内存  
        strcpy(name, nm); // 复制新名字  
        /********** End **********/  
    }  
};  
  

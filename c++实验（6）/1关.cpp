#include <iostream>  
using namespace std;  
  
void swap(int& a, int& b) {      
    int num = a;  
    a = b;  
    b = num;  
}  
  
int main()  
{  
    /********** Begin **********/  
    int arr[3][3];  
  
    // 输入初始矩阵  
    cout <<"输入9个整数作为矩阵元素值"<<endl<< "初始矩阵：" << endl;  
    for(int num1 = 0; num1 < 3; num1++) {  
        for(int num2 = 0; num2 < 3; num2++) {  
            cin >> arr[num1][num2];  
            cout <<arr[num1][num2]<<" ";  
        }  
        cout << endl;  
    }  
  
    // 转置矩阵  
    cout << "转置矩阵：" << endl;  
    for(int num1 = 0; num1 < 3; num1++)  
        for(int num2 = num1 + 1; num2 < 3; num2++)  
            swap(arr[num1][num2], arr[num2][num1]);  
  
    // 输出转置后的矩阵  
    for(int num1 = 0; num1 < 3; num1++) {  
        for(int num2 = 0; num2 < 3; num2++)  
            cout << arr[num1][num2]<<" ";  
        cout << endl;  
    }  
    /********** End **********/  
    return 0;  
}
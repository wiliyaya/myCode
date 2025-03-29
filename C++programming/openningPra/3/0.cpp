//template <class T>
//template <typename T>
//ss类型参数化

/*
    用T代表返回值，形参，局部变量
*/

//调用，用实例化生成T
//用重载区分

#include <iostream>
using namespace std;
template <class T>

    void print(T a)
    {
        cout<<a<<endl;
    }
    int main()
    {
        double a=3.0;
        print(a);








        

    }











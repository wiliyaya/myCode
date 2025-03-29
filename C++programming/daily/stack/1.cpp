//栈容器，符合先进后出的结构
//栈不允许有遍历的行为
//栈可以判断容器个数 empty
//栈可以返回元素个数 size
#include <iostream>
#include <stack>
using namespace std;


void test01()
{
    stack<int>s;

    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //只要栈不为空，查看栈顶，并且执行出栈操作
    while(!s.empty())
    {
        //查看栈顶元素
        cout<<"top: "<<s.top()<<endl;

        //出栈
        s.pop();
    }
    cout<<"size: "<<s.size()<<endl;

}

int main()
{
    test01();
}
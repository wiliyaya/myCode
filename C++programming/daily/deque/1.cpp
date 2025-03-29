//双端数组
//对头部的插入删除速度比vector快
//但是对元素的访问速度vector比较快
//vector内部是一段连续的空间，deque不是
#include <iostream>
#include <deque>
using namespace std;

//打印
void printDeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it=d.begin();it !=d.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}

//构造函数
void test01()
{
    deque<int> d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);   

    deque<int>d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int>d3(10,100);

    deque<int>d4(d3);
    printDeque(d4);
}

int main()
{
    test01();
    return 0;
}



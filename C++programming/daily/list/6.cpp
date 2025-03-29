//反转和排序
#include <iostream>
#include <list>
using namespace std;

void printList(list<int>&L)
{
    for(list<int>::iterator it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

bool cmp(int a,int b)
{
    return a>b;
}

void test01()
{
    list<int>L1;
    L1.pop_back(10);
    L1.pop_back(40);
    L1.pop_back(20);
    L1.pop_back(30);
    L1.pop_back(50);

    //反转
    L1.reverse();

    //排序
    cout<<"排序后:";

    //所有不支持随机访问的容器不能用标准算法
    //这些容器内部会提供一些成员函数
    L1.sort();//默认从小到大
    L1.sort(cmp);



}

int main()
{
    test01();
    return 0;
}
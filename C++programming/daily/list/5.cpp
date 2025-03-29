//数据存取（读取）
#include <iostream>
#include <list>
using namespace std;

void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);

    //不能用[]、at访问list中的元素

    cout<<"第一个元素"<<L1.front()<<endl;
    cout<<"第二个元素"<<L2.back()<<endl;

    //支持迭代器双向访问

}

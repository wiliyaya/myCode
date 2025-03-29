#include <iostream>
#include <list>
using namespace std;

void printList(list<int>&L)
{
    for(list<int>::iterator it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}
//容器的大小

void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);

    //判断容器是否为空
    if(L1.empty())
    {
        cout<<"empty"<<endl;
    }
    else 
    {
        cout<<"not empty"<<endl;
        cout<<"size of it :"<<L1.size()<<endl;
    }

    //重新指定大小
    L1.resize(10,100);//多出来的数用100填充
    printList(L1);


}

int main()
{
    test01();
}
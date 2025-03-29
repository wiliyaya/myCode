#include<iostream>
#include<deque>
using namespace std;

//deque没有容量的概念,因为可以无限添加元素

//deque容器大小操作

void printDeque(const deque<int>d1)
{
    for(deque<int>::const_iterator it=d1.begin();it!=end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}


void test01()
{
    deque<int>01;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }

    printDeque(d1);

    if(d1.empty())//如果容器为空返回真，否则返回假
    {
        cout<<"d1 is empty"<<endl;
    }
    else{
        cout<<"d1 is not empty"<<endl;
        cout<<"size of d1 is"<<d1.size()<<endl;

    }

    //重新指定大小
    d1.resize(15,1);//用‘1’填充
    d1.resize(5);





}
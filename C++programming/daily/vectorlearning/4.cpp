//互换容器swap
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}
void test01()
{
    //cout<<"换前"<<endl;
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    vector<int>v2;
    for(int i=10;i>0;i--)
    {
        v2.push_back(i);
    }
    //换后
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

//实际用途
//巧用swap可以收缩内存空间
void test02()
{
    vector<int>v;
    for(int i=0;i<10000;i++)
    {
        v.push_back(i);
    }

    v.resize(3);
    //大小改为了3，但是容量还是十几万，太浪费
    //此时可以用swap收缩内存
    vector<int>(v).swap(v);
    /*这段代码要分成两个部分来看；
    第一部分为vector<int>(v) ，这是一个匿名对象
    编译器会按v的大小来初始化匿名对象的大小和容量。
    加上.swap(v)后，容器的交换
    v指向匿名对象的大小和容量
    匿名对象在所在行结束后就会被系统回收
    */
}
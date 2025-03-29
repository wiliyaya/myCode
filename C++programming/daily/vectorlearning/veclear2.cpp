#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it =v.begin();it!=v.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}


void printVector(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}

void test01()
{
    vector<int> v1;
    //在v1的末尾加元素
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    //在末尾删
    v1.pop_back();

    //插入
    //注意：第一个参数是迭代器
    v1.insert(v1.begin(),100);//在开头加了一个100
    //可以指定数据个数
    v1.insert(v1.begin(),2,1000);//在开头加两个1000
    v1.insert(v1.begin()+2,4,12);
    v1.insert(v1.begin(),4);

    v1.insert(v1.begin()+2,7);//v1[2]处加int 7；

    //删除 参数也是迭代器
    v1.erase(v1.begin());//删除开头的一个数
    //清空
    v1.erase(v1.begin(),v1.end());
    //清空2
    v1.clear();
};
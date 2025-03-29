//vector的诗句存取操作
#include <iostream>
#include <vector>
using namespace std;

void test01()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }

    //用[] 和at获取元素
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<' ';
    }
    cout<<endl;

    for(int i=0;i<v1.size();i++)
    {
        cout<<v1.at(i)<<' ';
    }
    //特殊
    //第一个元素
    cout<<v1.front()<<endl;//返回第一个元素
    cout<<v1.back()<<endl;//最后一个元素


}
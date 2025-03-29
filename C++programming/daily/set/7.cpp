//改变set的排序规则
//利用仿函数
#include <iostream>
#include <set>
using namespace std;

// void printSet(set<int>&s)
// {
//     for(set<int>::iterator it=s.begin();it!=s.end();it++)
//     {
//         cout<<*it<<" ";
//     }
//     cout<<endl;
//  }

//仿函数
class MyCompare
{
public:
    bool operator()(const int &v1,const int &v2)const  //注意都要用const
    {
        return v1>v2;
    }
};



void test01()
{
    set<int>s1;
    //在创建容器的时候就要修改规则


    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    for(set<int>::iterator it=s1.begin();it!=s1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //指定排序规则从大到小
    
    set<int,MyCompare>s2;
    //在创建容器的时候就要修改规则
    

    s2.insert(10);
    s2.insert(20);
    s2.insert(30);
    s2.insert(40);

    //专属迭代器
    for(set<int,MyCompare>::iterator it=s2.begin();it!=s2.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

}

int main()
{
    test01();
}
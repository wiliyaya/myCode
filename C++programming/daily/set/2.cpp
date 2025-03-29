//大小和交换

#include <iostream>
#include<set>
using namespace std;

void printSet(set<int>&s)
{
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

//大小
void test01()
{
    set<int>s1;
    s1.insert(20);
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);

    printSet(s1);

    //判断是否为空
    if(s1.empty())
    {
        cout<<" s1 is empty"<<endl;
    }
    else 
    {
        cout<<" s1 isn't empty"<<endl;
        cout<<" size of s1: "<<s1.size()<<endl;
    }

    //交换
    set<int> s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(150);

    s1.swap(s2);
    cout<<"after: "<<endl
    <<"s1: ";
    printSet(s1);







}

int main()
{
    test01();
    return 0;
}












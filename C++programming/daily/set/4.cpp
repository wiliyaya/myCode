//查找和统计

#include <iostream>
#include <set>
using namespace std;

void printSet(set<int>&s)
{
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    //查找
    //s1.find()返回的是迭代器，所以创一个迭代器来固定
    set<int>::iterator pos=s1.find(30);
    
    if(pos!=s1.end())
    {
        cout<<"succeed finding "<<*pos<<endl;
    }
    else{
        cout<<"unfind "<<endl;
    }

}

//统计
void test02()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    //统计30的个数
    int num=s1.count(30);
    
    //对于set而言，统计结果 要么是0，要么是1
    cout<<"num= "<<num<<endl;


    
}

int main()
{
    test02();
    return 0;
}
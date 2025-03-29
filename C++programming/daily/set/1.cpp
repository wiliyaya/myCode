
//集合
//set 不允许重复的数 / multiset允许重复
//构造和赋值
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
    set<int>s;
    //插入数据，只有insert 方式
    s.insert(10);
    s.insert(20);
    s.insert(25);
    s.insert(40);
    s.insert(20);

    //遍历容器
    //所有元素在插入的时候自动排序
    //不允许有重复的值
    printSet(s);

    //拷贝构造
    set<int>s2(s);

    //赋值
    set<int>s3;
    s3=s2;

    printSet(s3);

}


int main()
{
    test01();
    return 0;
}




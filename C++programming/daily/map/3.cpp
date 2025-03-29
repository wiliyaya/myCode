#include <iostream>
#include <map>
using namespace std;
//插入和删除

void printMap(map<int,int>&m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<" key: "<<it->first<<" value: "<<it->second<<endl;
    }

}









void test01()
{
    map<int,int>m;

    //插入
    //1
    m.insert({1,10});

    //2
    m.insert(make_pair(2,20));
    m.insert(pair<int,int>(3,30));

    //以下两种不建议用
    //3
    m.insert(map<int,int>::value_type(4,40));

    //4
    m[5]=50;

    printMap(m);
}












int main()
{
    test01();

}
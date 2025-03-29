//map中所有元素都是pair
//pair中第一个元素为key（键值），起索引作用；第二个元素为value（实值）
//所有元素都会根据键值自动排序
//map不允许重复的key值，multimap允许
#include <iostream>
#include <map>
using namespace std;

void printMap(map<int,int> &m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<"Key= "<<it->first<<"  Value= "<<it->second<<endl;
    }
    cout<<endl;
}

//map的构造和赋值
void test01()
{
    map<int,int> m;
    m.insert(pair<int,int>(1,10));
    m.insert({2,20});
    m.insert(pair<int,int>(3,30));
    m.insert({4,40});
    m.insert(pair<int,int>(5,50));
    m.insert({6,60});

    printMap(m);


    //拷贝构造
    map<int,int>m2(m);
    printMap(m2);


    //赋值
    map<int,int>m3;
    m3=m2;
    printMap(m3);

}

int main()
{
    test01();
    return 0;
}

//自定义数据类型的排序规则
#include <iostream>
#include <set>
#include <string>

using namespace std;
class Person
{
public:
    Person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }

    string m_name;
    int m_age;
};

//仿函数的本质是一个类
class compare
{
public:
    bool operator()(const Person &p1,const Person &p2)const
    {
        //按照年龄降序
        return p1.m_age>p2.m_age;
    }
};

void test01()
{
    //对于自定义的数据类型，一般都要写仿函数来制定规则
    set<Person,compare>s;
    Person P1("liu",24);
    Person P2("Guang",25);
    Person P3("Zhan",20);

    s.insert(P1);
    s.insert(P2);
    s.insert(P3);
    
    for(set<Person,compare>::iterator it =s.begin();it!=s.end();it++)
    {
        cout<<"name: "<<it->m_name<<" age: "<<it->m_age;
    }

}

int main()
{
    test01();
}

















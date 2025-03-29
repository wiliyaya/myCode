//先进先出
//队列
//（先吃啥先拉）
//允许从一端（队尾）新增元素，从另一端（队头）移除元素
//只有队头和队尾可以被外界访问，因此不允许遍历行为
#include <iostream>
#include <queue>
#include <string>
using namespace std;


class Person
{
public:
    string m_name;
    int m_age;
    Person(string name,int age)
    {
        this->m_name=name;
        this->m_age=age;
    }

};

void test01()
{
    //创建队列
    queue<Person>q;

    //准备数据
    Person p1("Tang",30);
    Person p2("Sun",1000);
    Person p3("Zhu",800);
    Person p4("Sha",500);

    //入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    //判断只要队列不为空，查看对头，查看队尾，出列
    while(!q.empty()){
    cout<<"队头： "<<q.front().m_name<<" age: "<<q.front().m_age<<endl;
    cout<<"tail: "<<q.back().m_name<<" age: "<<q.back().m_age<<endl;

    q.pop();
    }
    cout<<"size: "<<q.size()<<endl;
}

int main()
{
    test01();
    return 0;
}

#include <iostream>

using namespace std;

//pair对组
void test01()
{
    //第一种方式
    pair<string,int>p("Tom",20);

    cout<<"name: "<<p.first<<"  age: "<<p.second<<endl;

    //第二种
    pair<string,int>p2=make_pair("Aiiy",25);
    cout<<"name: "<<p2.first<<" age: "<<p2.second;

}

int main()
{
    test01();
}
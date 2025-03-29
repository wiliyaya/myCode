#include <iostream>
#include <set>
using namespace std;
//set 容器 和 multiset


void test01()
{
    set<int>s1;
    pair<set<int>::iterator ,bool>ret =s1.insert(10);
    if(ret.second)
    {
        cout<<"Success"<<endl;
    }
    else{
        cout<<"Failure"<<endl;
    }

    ret=s1.insert(10);
    if(ret.second)
    {
        cout<<"Success"<<endl;
    }
    else{
        cout<<"Failure"<<endl;
    }

    multiset<int>ms;
    //允许插入重复值
    ms.insert(10);
    ms.insert(10);

    for(multiset<int>::it=ms.begin();it!=ms.end();it++)
    {
        
    }

}


int main()
{
    test01();
}
#include <iostream>
#include <map>
using namespace std;

void printMap(map<int,int>&m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
    }
    cout<<endl;
}

//map容器 大小和交换
//大小
void test01()
{
    map<int,int>m;
    m.insert({1,10});
    m.insert(pair<int,int>(2,20));
    m.insert({3,30});
    m.insert({4,40});

    if(m.empty())
    {
        cout<<"m is empty"<<endl;
    }
    else 
    {
        cout<<"isn't empty"<<endl;
        cout<<"size of m is "<<m.size()<<endl;
    }


}


//交换
void test02()
{
    
    map<int,int>m;
    m.insert({1,10});
    m.insert(pair<int,int>(2,20));
    m.insert({3,30});
    m.insert({4,40});


    
    map<int,int>m2;
    m2.insert({1,100});
    m2.insert(pair<int,int>(2,200));
    m2.insert({3,300});
    m2.insert({4,400});

    cout<<"before swap:"<<endl;
    printMap(m);
    printMap(m2);


    m.swap(m2);
    cout<<"after swap:"<<endl;
    printMap(m);
    printMap(m2);

    

}

int main()
{
    test02();
    return 0;
}


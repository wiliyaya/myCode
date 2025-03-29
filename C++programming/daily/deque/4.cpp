#include <iostream>
#include <deque>
using namespace std;

//deque的容器的插入和删除
//注意插入和删除提供的位置都是迭代器

void printDeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}


//两端的操作
void test01()
{
    deque<int>d1;

    //尾插法
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(100);

    //尾删
    d1.pop_back();

    //头删
    d1.pop_front();

    printDeque(d1);
}


//插入 insert
void test02()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    printDeque(d1);
    //insert
    d1.insert(d1.begin(),1000);//d1.insert(迭代器，加入的数字)
    d1.insert(d1.begin(),2,2222);//d1.insert(迭代器，插入几个数，插入的数字)
    
    //按区间进行插入
    deque<int>d2;
    d2.push_back(10);
    d2.push_back(20);
    d2.push_back(30);

    d1.insert(d1.begin(),d2.begin(),d2.end());

}

//删除
void test03()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);

    //删除
    deque<int>::iterator it=d1.begin();
    it++;
    d1.erase(it);//通过自己写一个迭代器来实现对指定位置的删除

    //按区间的方式删除
    d1.erase(d1.begin(),d1.end());

    //清空
    d1.clear();   

}


int main()
{
    test02(); 
    return 0;
}

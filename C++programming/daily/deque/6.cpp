//deque排序
#include <iostream>
#include <deque>
using namespace std;
#include <algorithm>
void printDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}
// void printDeque(const deque<int> &b)
// {
//     for(deque<int>const_iterator::it =b.begin();it!=b.end();it++)
//     {
//         cout<<*it<<" ";
//     }
//     cout<<endl;

// }


void test01()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    printDeque(d);

    //排序 默认排序规则：从小到大，升序
    //对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    //vector容器也可以利用sort排序
    sort(d.begin(),d.end());
    cout<<"after sort:";
    printDeque(d);
}

int main()
{
    test01();
    return 0;
}









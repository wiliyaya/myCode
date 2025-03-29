//插入和删除
/*
push_back(elem);//在容器尾部加一个元素
pop_back();//删除容器的最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//删除容器的第一个元素
insert(pos,elem);//在pos位置插入elem的拷贝，返回新数据的位置
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据,无返回值
clear();//移除所有数据
erase(beg,end);//删除[beg，end)区间的数据，返回下一个数据的位置
erase(pos);//删除pos位置的数据，返回下一个数据的位置
remove(elem);//删除元素中所有与elem值匹配的元素
*/
#include <iostream>
#include <list>
using namespace std;

void printList(list<int>&L)
{
    for(list<int>::iterator it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}

void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);

    //尾删
    L1.pop_back();
    L1.pop_front();

    printList(L1);

    //insert
    list<int>::iterator it=L1.begin();
    L1.insert(++it,1000);//list迭代器只能用++来偏移，不能加int型的整数

    //erase
    it=L1.begin();
    it=L1.erase(it);

    //remove 移除
    L1.push_back(1234);
    L1.push_back(1234);
    L1.remove(1234);//移除所有的1234


    //清空
    L1.clear();

    printList(L1);

}


int main()
{
    test01();
    return 0;
}
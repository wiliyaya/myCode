#include <iostream>
#include <vector>
using namespace std;

//打印vector函数
void printVector(vector<int> & v)
{
    for(vector<int>::iterator it =v.begin();it!=v.end();it++)
    {
        cout<<*it<<' ';//注意这个it要解引用
    }
    cout<<endl;
}

//vector的容量和大小
void test01()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //判断v1是否为空
    if(v1.empty())//若为空则返回true
    {
        cout<<"v1空"<<endl;
    }
    else{
        cout<<"v1不空"<<endl;
        cout<<v1.capacity()<<endl;//输出v1的容量
        cout<<v1.size()<<endl;//大小
        //容量>=大小
    }

    //重新指定大小
    v1.resize(15);//会默认用‘0’来填充新的位置
    v1.resize(16,100);//可以用重载指定默认填充值
    printVector(v1);
    
    v1.resize(5);//会删除多出来的数
}
int main()
{
    test01();
    return 0;
}

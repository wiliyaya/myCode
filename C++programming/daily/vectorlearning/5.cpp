//预留空间
#include <iostream>
#include <vector>
using namespace std;
void test01()
{
    vector<int> v1;

    //利用reserve预留空间
    v.reserve(100000);

    //统计开辟空间的次数
    int num=0;
    int *p=NULL;
    for(int i=0;i<10000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;
        }
    }
    //num即开辟空间的次数
}
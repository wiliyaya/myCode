#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    string str;
    cin>>str;
    map<char,int>m;
    for(int i=0;i<str.length();i++)
    {
        m.insert({str[i],0});
    }
    for(int i=0;i<str.length();i++)
    {
        for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
        {
            if(str[i]==it->first)
            {
                it->second++;
                break;
            }
        }
    }
    int num=0;
    for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
    {
        if(it->second>=3)
        {
            num++;
        }
    }
    cout<<num;
    return 0;
}
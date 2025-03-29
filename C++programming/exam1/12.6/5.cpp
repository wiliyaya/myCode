#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <cctype>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<string>a,b;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]>'Z')
            s[j]-=32;
        }
        if(count(a.begin(),a.end(),s)==0) a.push_back(s);
    }
    for(int i=0;i<m;i++)
    {
        string s;cin>>s;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]>'Z')
            s[j]-=32;
        }
        if(count(b.begin(),b.end(),s)==0)
        {
            b.push_back(s);
        }
    }
    int t=0;
    for(int i=0;i<a.size();i++)
    {
        if(count(b.begin(),b.end(),a[i])!=0)
        t++;
    }
    cout<<t<<endl;
    return 0;
}
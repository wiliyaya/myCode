#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        if(a<=15)
        {
            v1.push_back(a);
        }
        else{
            v2.push_back(a);
        }
    }
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<' ';
    }
    for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
    {
        cout<<*it<<' ';
    }
    return 0;

}
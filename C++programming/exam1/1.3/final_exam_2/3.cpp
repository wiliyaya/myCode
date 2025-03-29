#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(n==m*k)
    {
        cout<<'0'<<endl;
        return 0;
    }
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<m;i++)
    {
        int num=0;
        for(int j=0;j<(i+1)*k;j++)
        {
            if(vec[j]==i+1)
            {
                num++;
            }
        }
            if(num<k)
            {
                cout<<i+1<<' ';
                for(int p=num+1;p<=k;p++)
                {
                    cout<<p<<' ';
                }
            }
        cout<<endl;
    }

    return 0;

}
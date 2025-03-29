#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n+1,0);
    int a;cin>>a;
    for(int i=0;i<a;i++)
    {
        int x;
        cin>>x;
        vec[x]++;
    }
    int b;cin>>b;
    for(int i=0;i<b;i++)
    {
        int x;
        cin>>x;
        vec[x]++;
    }
    int c;cin>>c;
    for(int i=0;i<c;i++)
    {
        int x;
        cin>>x;
        vec[x]++;
    }
    int num=0;
    for(int k:vec)
    {
        if(k!=1)
        {
            num++;
        }
    }
    cout<<num-1;
    return 0;

}
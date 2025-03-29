#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int num=0;
    while(n--)
    {
        int a;
        cin>>a;
        if(a==m)
        {num++;}
    }
    cout<<num<<endl;
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int n,m,k;//行，列，高度
    cin>>n>>m>>k;
    if(k==1&&n==1)
    {
        for(int i=0;i<m;i++)
        {
            cout<<'#';
        }
    }
}



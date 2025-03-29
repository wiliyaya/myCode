#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    vector<int>A;
    for(int i=0;i<n*m;i++)
    {
        int a;
        cin>>a;
        A.push_back(a);
    }
    int k=0;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            cout<<A[k]<<' ';
            k++;
        }
        cout<<endl;
    }
    return 0;
}
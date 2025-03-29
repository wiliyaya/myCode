#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int Tnum=0;//楼梯个数
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        a.push_back(k);
        if(k==1)
        {
            Tnum++;
        }
    }
    cout<<Tnum<<endl;

    for(int i=0;i<n;i++)
    {
        if(a[i]==1&&i!=0)
        {
            cout<<a[i-1]<<" ";
        }
        
    }
    cout<<a[n-1];
    return 0;

}

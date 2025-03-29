#include<iostream>
#include<vector>
using namespace std;

struct Cos
{
    int t;
    int l;
};

int main()
{
    int n,L,a;
    cin>>n>>L>>a;
    vector<Cos> cos(n);
    for(int i=0;i<n;i++)
    {
        cin>>cos[i].t>>cos[i].l;
    }
    int gap=0;
    int times=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            gap=cos[i].t-0;
        }
        else if(i==n-1)
        {
            gap=L-(cos[i].t+cos[i].l);
        }
        else 
        {
            gap=cos[i+1].t-cos[i].t-cos[i].l;        
        }
        times+=gap/a;
    }
    cout<<times<<endl;
    return 0;

}
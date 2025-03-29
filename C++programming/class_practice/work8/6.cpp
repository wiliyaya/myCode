#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Frog
{
    long long x;
    long long t;
    long long num;
};
struct Wenzi
{
    long long p;
    long long b;
};
int main()
{
    long long n,m;
    cin>>n>>m;
    //Frog *frog=new Frog[n];
    vector<Frog> frog(n);
    for(long long i=0;i<n;i++)
    {
        cin>>frog[i].x>>frog[i].t;
        frog[i].num=0;
    }
    Wenzi *wenzi=new Wenzi[m];
    for(long long i=0;i<m;i++)
    {
        cin>>wenzi[i].p>>wenzi[i].b;
    }
    for(long long i=0;i<m;i++)
    {
        for(long long j=0;j<n;j++)
        {
            if(frog[j].x+frog[j].t>=wenzi[i].p&&frog[j].x<=wenzi[i].p)
            {
                frog[j].t+=wenzi[i].b;
                frog[j].num++;
                break;
            }
        }
    }
    for(long long i=0;i<n;i++)
    {
        cout<<frog[i].num<<' '<<frog[i].t<<endl;
    }


    //delete[] frog;
    delete[] wenzi;
    return 0;
}
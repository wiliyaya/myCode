#include <iostream>
#include <set>
using namespace std; 

int main()
{
    int n,m,a,d;
    cin>>n>>m>>a>>d;
    set<int> time;
    for(int i=1;i<=n;i++)
    {
        time.insert(i*a);
    }
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        time.insert(t);
    }
    int num=0;
    int closeTime=0;
    bool isfirst=true;
    for(set<int>::iterator it =time.begin();it!=time.end();it++)
    {
        if(isfirst)
        {
        closeTime=*it+d;
        isfirst=false;
        num++;
        continue;
        }

        if(*it<=closeTime)
        {
            continue;
        }
        else{
            closeTime=*it+d;
            num++;
        }
    }
    cout<<num;
    return 0;
 
}




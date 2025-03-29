#include <iostream>
#include <vector>
using namespace std;

struct C
{
    int x;
    int y;
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec;
    int temp=n;
    while(temp--)
    {
        int r;
        cin>>r;
        vec.push_back(r);
    }

    vector<C> v(k);
    for(int i=0;i<k;i++)
    {
        cin>>v[i].x>>v[i].y;
    }

    vector<int> v1(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j&&vec[i]>vec[j])
            {
                bool hasConflict=false;
                for(int m=0;m<k;m++)
                {
                    if((i+1==v[m].x&&j+1==v[m].y)||(j+1==v[m].x&&i+1==v[m].y))
                    {
                        hasConflict=true;
                        break;
                    }
                }

                if(!hasConflict)
                {
                    v1[i]++;
                }
            }
        }
    }

    for(vector<int>::iterator it =v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<' ';
    }
    return 0;


}
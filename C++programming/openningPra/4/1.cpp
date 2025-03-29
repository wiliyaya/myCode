#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,g,r;
    cin>>n>>g>>r;
    vector<int> vec;
    for(int i=0;i<n+1;i++)
    {
        int a;cin>>a;
        vec.push_back(a);
    }
    int q;
    cin>>q;
    vector<int> leaveTime;
    for(int i=0;i<q;i++)
    {
        int a;cin>>a;
        leaveTime.push_back(a);
    }

    vector<int>arriveTime;
    int T=g+r;

    for(int i=0;i<q;i++)
    {
        int cur_t=leaveTime[i];

        for(int j=0;j<n;j++)
        {
            cur_t+=vec[j];

            int time_cycle=cur_t%T;

            if(time_cycle>=g)
            {
                int wait_time=T-time_cycle;
                cur_t+=wait_time;
            }
        }
        arriveTime.push_back(cur_t+vec[vec.size()-1]);
    }

    for(vector<int>::iterator it=arriveTime.begin();it!=arriveTime.end();it++)
    {
        cout<<*it<<' ';
    }
    return 0;

}
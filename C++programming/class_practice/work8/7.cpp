#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event
{
    int time;//时间
    char action;//动作：t代表取钥匙，，r代表还
    int key;//钥匙编号

    bool operator<(const Event& other)const{
        if(time==other.time)
        {
            return action<other.action;
        }
        return time<other.time;
    }
};

int main()
{
    int N,K;
    cin>>N>>K;
    
    //初始化钥匙盒，钥匙编号从1到N
    vector<int> keys(N);
    for(int i=0;i<N;++i)
    {
        keys[i]=i+1;
    }

    vector<Event> events;

    //读取每位老师的请求
    for(int i=0;i<K;i++)
    {
        int w,s,c;
        cin>>w>>s>>c;
        events.push_back({s,'t',w});
        events.push_back({s+c,'r',w});
    }

    //按时间排序
    sort(events.begin(),events.end());

    //处理时间排序事件
    for(const auto& event:events)
    {
        if(event.action=='r')
        {
            //还钥匙
            //找到最左边的空挂钩
            for(int j=0;j<N;j++)
            {
                if(keys[j]==0)//0表示空挂钩
                {
                    keys[j]=event.key;//还钥匙
                    break;
                }
            }
        }
        else if(event.action=='t')
        {
            //找到钥匙并取走
            for(int j=0;j<N;j++)
            {
                if(keys[j]==event.key)
                {
                    keys[j]=0;//取走钥匙，并设为空
                    break;
                }
            }
        }
    }

    //输出最终的钥匙状态
    for(int i=0;i<N;i++)
    {
        cout<<keys[i]<<" ";
    }
    cout<<endl;
    return 0;
}
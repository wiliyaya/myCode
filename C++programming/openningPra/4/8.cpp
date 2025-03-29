#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//j为单位时间
bool canWaterAll(int n,const vector<int>& taps,int j)
{
    vector<bool> watered(n+1,false);
    for(int tap:taps)
    {
        int left=max(1,tap-(j-1));//左边界
        int right=min(n,tap+(j-1));//右边界
        for(int i=left;i<=right;i++)
        {
            watered[i]=true;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(!watered[i])return false;
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>taps(k);
        for(int i=0;i<k;i++)
        {
            cin>>taps[i];
        }

        //二分法找最小时单位
        int left=0,right=n;
        int result=n;//最小时间单位的初始值
        while(left<=right)
        {
            int mid=left+(right-left)/2;//中间时间单位
            if(canWaterAll(n,taps,mid))
            {
                result=mid;//更新结果
                right=mid-1;//尝试更小的时间单位
            }
            else {
                left=mid+1;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}

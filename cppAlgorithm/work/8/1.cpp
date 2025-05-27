#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
void solve(){
  ll n,x; //列数和使用的最大水量
  cin>>n>>x;
  vector<ll> a(n); //每列的水量
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end()); //从小到大排序
  ll l=1,r=a[n-1]+x; //二分的左右端点
  ll ans=0; //记录答案
  while(l<=r){
    ll mid=(l+r)>>1; //猜测的水量
    ll waterSum=0; //当前水量总和
    for(ll i=0;i<n;i++){
      if(a[i]<mid){
        waterSum+=mid-a[i]; //如果当前列水量小于mid，补充到mid
      }
      if(waterSum>x){ //如果水量总和超过了最大水量x
        break; //直接跳出循环
      }
    }
    if(waterSum<=x){
      ans=mid;
      l=mid+1; //如果水量总和不超过x，说明mid可以更大
    }
    else {
      r=mid-1; //如果水量总和超过x，说明mid太大了
    }
  }
  cout<<ans<<endl; //输出最大水量
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve(); //每个测试用例调用solve函数
  }
  return 0;
}
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main(){
  int n,m;//n:苹果总数  m:每天最大投喂量
  cin>>n>>m;
  vector<int> profit(n+1,0);
  for(int i=0;i<=n;i++){
    cin>>profit[i];
  }
  vector<int> dp(n+1,0);
  for(int i=1;i<=m;i++){
    for(int j=i;j<=n;j++){
      dp[j]=max(dp[j],dp[j-i]+profit[i]);
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}
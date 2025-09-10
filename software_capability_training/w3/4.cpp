#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

long long maxPreArray(vector<long long >& add){
  int n=add.size();
  vector<long long > dp(n,0);
  dp[0]=add[0];
  long long ans=dp[0];
  for(int i=1;i<n;i++){
    dp[i]=dp[i-1]+add[i];
    ans=max(ans,dp[i]);
  }
  return ans;

}

long long minPreArray(vector<long long>&add){
  int n=add.size();
  vector<long long > dp(n,0);
  dp[0]=add[0];
  long long ans=dp[0];
  for(int i=1;i<n;i++){
    dp[i]=dp[i-1]+add[i];
    ans=min(ans,dp[i]);
  }
  return ans;
}

int main(){
  int n;
  long long w;
  cin>>n>>w;
  vector<long long > add(n+1,0);
  for(int i=1;i<=n;i++){
    cin>>add[i];
  }
  long long maxAddNum=maxPreArray(add);
  //ans<=w-maxAddNum
  if(w-maxAddNum<0){
    cout<<0<<endl;
    return 0;
  }
  long long minAddNum=minPreArray(add);
  if(minAddNum>=0){
    cout<<w-maxAddNum+1<<endl;
  }
  else
  if(-minAddNum>w){
    cout<<0<<endl;
  }
  else {
    cout<<w-maxAddNum+minAddNum+1<<endl;
  }
  return 0;


}
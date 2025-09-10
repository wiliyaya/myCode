#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
if(n==0){return 0;}

vector<int> dp(n);
dp[0]=0;
int ans=0;
for(int i=1;i<n;i++){
if(s[i]=='('){
    dp[i]=0;
    continue;
}
int p=i-1-dp[i-1];
if(p>=0 && s[p]=='('){
    dp[i]=dp[i-1]+2+(p>0 ? dp[p-1] : 0);	
}
ans=max(ans,dp[i]);
}
cout<<ans<<endl;
    return 0;
}
    
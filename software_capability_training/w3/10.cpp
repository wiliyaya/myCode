#include <iostream>
#include <map>

using namespace std;
int main(){
  int n,m;
  map<int,int,greater<int>> mp;
  for(int i=0;i<2;i++){
    while(cin>>n>>m){
      if(n==0 && m==0) break;
      mp[n]+=m;
    }
  }
  for(auto& [key,val]:mp){
    if(val==0) continue;
    cout<<key<<" "<<val<<endl;
  }
  return 0;
  


}
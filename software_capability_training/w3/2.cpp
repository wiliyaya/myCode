#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
  string N;
  cin>>N;
  vector<int> cnt(10,0);
  for(char c:N){
    cnt[c-'0']++;
  }
  for(int i=0;i<10;i++){
    if(cnt[i]){
      cout<<i<<":"<<cnt[i]<<endl;
    }
  }
  return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
  int n;//参数人数
  cin>>n;
  unordered_map<int,int> mp;
  for(int i=0;i<n;i++){
    int id,score;
    cin>>id>>score;
    mp[id]+=score;
  }
  int maxid,maxscore=0;
  for(auto &[id,score]:mp){
    if(score>maxscore){
      maxscore=score;
      maxid=id;
    }
  }
  cout<<maxid<<' '<<maxscore<<endl;
  return 0;
}
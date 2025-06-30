#include <iostream>
#include <vector>
using namespace std;
int main(){
  int T;
  cin>>T;
  vector<int> IP(4,0);
  while(T--){
    int count=0;
    scanf("%d.%d.%d.%d",&IP[0],&IP[1],&IP[2],&IP[3]);
    for(int i=0;i<4;i++){
      while(IP[i]){
        IP[i] &=(IP[i]-1);
        count++;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
//正常模式 P1
//T1分钟后，保护模式 P2
// T2分钟后，睡眠模式 P3
#include <iostream>
#include <vector>
using namespace std;
struct Time{
  int l;
  int r;
};
int main(){
  int n,P1,P2,P3,T1,T2;
  cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;
  vector<Time> times(n);
  int totalTime = 0;
  for(int i = 0; i < n; i++){
    cin >> times[i].l >> times[i].r;
    totalTime+=(times[i].r-times[i].l)*P1;
  }
  for(int i=1;i<n;i++){
    int duration=times[i].l-times[i-1].r;
    if(duration<T1){
      totalTime+=duration*P1;
    }
    else if(duration<T1+T2){
      totalTime+=T1*P1+(duration-T1)*P2;
    }
    else{
      totalTime+=T1*P1+T2*P2+(duration-T1-T2)*P3;
    }
  }
  cout << totalTime << endl;
  return 0;
}
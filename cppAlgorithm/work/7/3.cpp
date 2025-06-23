#include <iostream>
#include <vector>
using namespace std;

vector<long long> A;//各点的海拔
vector<long long> diff;//各点的海拔差
long long temp=0;//温度
//因为最终只要知道N位置的温度，所以不需要数组存储每个位置的温度

int main(){
  long long N,Q,S,T;//N个点，Q天，第j日，下降S度，上升T度
  cin>>N>>Q>>S>>T;
  A.resize(N+2);
  diff.resize(N+2);
  // temp.resize(N+2);
  A[0]=0;
  for(long long i=1;i<=N+1;i++){
    cin>>A[i];
    diff[i]=A[i]-A[i-1];
    //初始也可能就已经有温度差了
    if(diff[i]>0){
      temp-=1LL* diff[i]*S;
    }
    else {
      temp+=1LL*(-diff[i])*T;
    }
  }
  for(long long i=0;i<Q;i++){
    long long L,R,X;
    cin>>L>>R>>X;//X代表海拔的变化，可为负数

    
    //更新海拔差
    //首先要减去该点原有的高度差对temp的贡献
    if(diff[L]>0){
      temp+=1LL*diff[L]*S;
    }
    else temp-=1LL*(-diff[L])*T;
    diff[L]+=X;
    //更新后再计算对temp的贡献
    if(diff[L]>0){
      temp-=1LL*diff[L]*S;
    }
    else temp+=1LL*(-diff[L])*T;

  
    //R+1位置
    if(diff[R+1]>0){
      temp+=1LL*diff[R+1]*S;
    }
    else temp-=1LL*(-diff[R+1])*T;
    diff[R+1]-=X;
    if(diff[R+1]>0){
      temp-=1LL*diff[R+1]*S;
    }
    else temp+=1LL*(-diff[R+1])*T;

  cout<<temp<<endl;
  }
   
  
return 0;
}
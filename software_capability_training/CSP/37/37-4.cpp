#include <iostream>
#include <vector>
using namespace std;
long long mod=998244353;

long long gcd(long long a,long long b){
  return b==0 ? a : gcd(b,a%b);
}

// long long f(long long l,int r,vector<int>& power){
//   int g=power[l];
//   for(int i=l+1;i<=r;i++){
//     g=gcd(g,power[i]);
//   }
//   return g*l*r;
// }

int main(){
  long long n;
  cin>>n;
  vector<long long> power(n+1,0);
  for(long long i=1;i<=n;i++){
    cin>>power[i];
  }
  long long result=0;
  for(long long i=1;i<=n;i++){
    long long cur_gcd=power[i];
    for(long long j=i;j<=n;j++){
      cur_gcd=gcd(cur_gcd,power[j]);
      result=(result+cur_gcd*i*j)%mod;
      // result=(result+f(i,j,power))%mod;
    }
  }
  cout<<result%mod<<endl;
  return 0;


}
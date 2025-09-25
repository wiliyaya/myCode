#include <iostream>
#include <map>
using namespace std;

void allPrime(int n,map<long long,long long>& primeMap){
  for(int i=2;i*i<=n;i++){
    while(n%i==0){
      primeMap[i]++;
      n=n/i;
    }
  }
  if(n>1){
    primeMap[n]++;
  }
}

int main(){
  int q;
  cin>>q;
  while(q--){
    long long number;
    int k;
    cin>>number>>k;
    map<long long ,long long > primeMap;
    allPrime(number,primeMap);
    for(auto& [prime,times]:primeMap){
      if(times<k){
        for(int i=0;i<times;i++){
          number/=prime;
        }
      }
    }
    cout<<number<<endl;
  }
  return 0;
}
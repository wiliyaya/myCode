#include <iostream>
using namespace std;
int main(){
  int k,w;
  long long n;
  cin>>k>>n>>w;
  long long sum=(w+1)*w/2;
  if(sum*k>n){
    cout<<sum*k-n<<endl;
  }
  else{
    cout<<0<<endl;
  }
  return 0;
}
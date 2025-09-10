#include <iostream>
#include <set>

using namespace std;
int main()
{
  long long n,k;
  cin>>n>>k;
  set<long long> figures;
  for(int i=0;i<n;i++){
    long long x;
    cin>>x;
    figures.insert(x);
  }
  long long num=1;
  for(int value:figures){
    if(num>k){
      break;
    }
    cout<<value<<" ";
    num++;
  }
  return 0;
}
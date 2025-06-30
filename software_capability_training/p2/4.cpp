#include <iostream>
using namespace std;
int main(){
  int n,x,y;
  cin>>n>>x>>y;
  if(n-(y+x-1)/x >=0){
    cout<<n-(y+x-1)/x<<endl;
  }
  else cout<<0;
  return 0;

}
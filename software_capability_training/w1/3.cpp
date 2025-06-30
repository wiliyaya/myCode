#include <iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int xp_num=0,xn_num=0;
  while(n--){
    long long x,y;
    cin>>x>>y;
    if(x>0){
      xp_num++;
    }
    else if(x<0){
      xn_num++;
    }
  }

  if(xp_num==1 || xn_num==1 || xp_num==0 || xn_num==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}
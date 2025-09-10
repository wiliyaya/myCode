#include<iostream>
using namespace std;

long long f(int b,int c,int x){
  return x*x+b*x+c; 
}

int main(){
  int b,c,l,r;
  cin>>b>>c>>l>>r;
  //找到l和r之间的第一个整数
  int cur;
  if(l%2==0){
    cur=l;
  }
  else cur=l+1;

  long long s=0;
  while(cur<=r){
    s+=f(b,c,cur)*2;
    cur+=2;
  }
  cout<<s<<endl;
  return 0;
}
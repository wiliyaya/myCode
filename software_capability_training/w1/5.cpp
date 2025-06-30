#include<iostream>
#include<string>
using namespace std;

//查找是否包含n
bool isin(int n,int tar){
  string str=to_string(tar);
  string t=to_string(n);
  // if(str.find(t) != string::npos){
  //   return true;
  // }
  // return false;
  return str.find(t) != string::npos;
}

int main(){
  int m,n;
  cin>>m>>n;
  for(int i=n;i<=m;i++){
    if(i%n==0){
      cout<<i<<' ';
    }
    else if(isin(n,i)){
      cout<<i<<' ';
    }
  }
  return 0;
}
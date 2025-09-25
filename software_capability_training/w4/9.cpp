#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//如果要让它变成奇数长度的回文串要加多少字符
int makeOddstr(string str){
  int size=str.size();
  int times=0;
  int add=100000;
  for(int i=size/2;i<size;i++){
    int l=i-1;
    int r=i+1;
    while(str[l]==str[r]&& r<size &&l>=0){
      l--;
      r++;
      times++;
    }
    if(r!=size){
      continue;
    }
    else {
      add=min(add,size-(2*times+1));
    }
    times=0;
  }
  return add;

}

//如果要让它变成偶数长度的回文串要加多少字符
int makeEvenstr(string str){
  int size=str.size();
  int times=0;
  int add=100000;
  for(int i=size/2;i<size;i++){
    int l=i-1;
    int r=i;
    while(str[l]==str[r]&& r<size &&l>=0){
      l--;
      r++;
      times++;
    }
    if(r!=size){
      continue;
    }
    else {
      add=min(add,size-(2*times));
    }
    times=0;
  }
  return add;
}


int main(){
  int n;
  while(cin>>n){
    if(n==0) break;
    string str;
    cin>>str;
    cout<<min(makeOddstr(str),makeEvenstr(str))<<endl;

  }
  return 0;

}
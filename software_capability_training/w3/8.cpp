#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
  string sale;
  string wantMake;
  cin>>sale>>wantMake;
  unordered_map<char,int> saleMap;
  for(char c:sale){
    saleMap[c]++;
  }
  bool canMake=true;
  int need=0;
  for(char c:wantMake){
    if(saleMap[c]>0){
      saleMap[c]--;
    }
    else {
      need++;
      canMake=false;
    }
  }
  if(canMake){
    cout<<"Yes"<<' '<<sale.size()-wantMake.size()<<endl;
  }
  else {
    cout<<"No"<<' '<<need<<endl;

  }
  return 0;

}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  vector<int> number;
  int n;
  while(cin>>n){
    number.push_back(n);
  }
  sort(number.begin(),number.end());
  if(number[0]==0){
    int i=1;
    while(i<number.size()&& number[i]==0){
      i++;
    }
    swap(number[0],number[i]);
  }
  for(int num:number){
    cout<<num;
  }
  cout<<endl;
  return 0;

}
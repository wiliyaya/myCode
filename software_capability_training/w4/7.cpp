#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long cur;
  long long last;
  int length=1;
  int maxLength=1;
  cin>>cur;
  for(int i=1;i<n;i++){
    last=cur;
    cin>>cur;
    if(cur>last){
      length++;
      maxLength=max(maxLength,length);
    }
    else {
      length=1;
    }
  }
  cout<<maxLength<<endl;
  return 0;
}
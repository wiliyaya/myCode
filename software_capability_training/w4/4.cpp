#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    if(n==0) break;
    vector<int> vec(n);
    for(int i=0;i<n ;i++){
      cin>>vec[i];
    }
    int number =0;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(vec[i]>vec[j]){
          number++;
        }
      }
    }
    cout<<number<<endl;
  }
  return 0;
}
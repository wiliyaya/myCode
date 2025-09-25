#include<iostream>
#include <vector>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> vec(N,0);
  vec[0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N-i;j++){
      if(j==0){
        vec[j]=vec[j]+i;
      }
      else {
        vec[j]=vec[j-1]+i+j+1;
      }
      cout<<vec[j]<<' ';
    }
    cout<<endl;
  }
  return 0;
}
#include <iostream>
using namespace std;
int main(){
  int M,N;
  cin>>M>>N;
  if(M%2==0){
    cout<<M/2*N<<endl;
  }
  else if(N%2==0){
    cout<<N/2*M<<endl;
  }
  else{
    cout<<M/2*N+N/2+1<<endl;
  }
  return 0;
}
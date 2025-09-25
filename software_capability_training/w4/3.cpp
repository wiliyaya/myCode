#include <iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    if(n==0) break;
    char cur;
    char last;
    cin>>cur;
    int numAB=0,numBA=0;
    for(int i=1;i<n;i++){
      last=cur;
      cin>>cur;
      if(last=='a'&&cur=='b'){
        numAB++;
      }
      else if(last=='b'&&cur=='a'){
        numBA++;
      }
    }
    cout<<numAB-numBA<<endl;
  }
  return 0;
}
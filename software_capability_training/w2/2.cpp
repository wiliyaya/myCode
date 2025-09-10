#include <iostream>

using namespace std;

int main(){
  int n;
  while(cin>>n&&n!=0){
    int times=0;
    while(n!=1){
      if(n%2==0){
        n=n/2;
      }
      else {
        n=(3*n+1)/2;
      }

      times++;
    }
    cout<<times<<endl;
  }
  return 0;
}
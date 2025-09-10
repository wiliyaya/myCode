#include <iostream>
using namespace std;
int main(){
  long long A,B;
  int DA,DB;
  cin>>A>>DA>>B>>DB;
  int num_A=0,num_B=0;
  while(A){
    if(A%10==DA){
      num_A++;
    }
    A=A/10;
  }

  while(B){
    if(B%10==DB){
      num_B++;
    }
    B=B/10;
  }

  long long PA=0,PB=0;
  for(int i=0;i<num_A;i++){
    PA=PA*10+DA;
  }

  for(int i=0;i<num_B;i++){
    PB=PB*10+DB;
  }
  cout<<PA+PB<<endl;
  return 0;
}
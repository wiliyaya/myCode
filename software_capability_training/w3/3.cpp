#include <iostream>
#include <string>
using namespace std;
int main(){
  string A;
  int B;
  cin>>A>>B;
  int size=A.size();
  int carry=0;
  string Q;
  // if(A[0]-'0'>=B){
  //   Q=Q+char((A[0]-'0')/B+'0');
  //   carry=(A[0]-'0')%B;
  // }
  for(int i=0;i<size;i++){
    int cur=(A[i]-'0')+carry*10;
    if(i==0&&cur<B){
      carry=cur;
      continue;
    }
    Q=Q+char(cur/B+'0');
  
    carry=cur%B;
  }
  if(Q.size()==0){
    Q="0";
  }
  cout<<Q<<' '<<carry<<endl;
  return 0;
}
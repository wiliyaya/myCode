#include <iostream>
#include <string>
using namespace std;
int main(){
  long long M1,M2;
  while(cin>>M1>>M2){
    string order;
    cin>>order;
    long long R1=0,R2=0,R3=0;
    for(char op:order){
      switch (op)
      {
      case 'A':
      R1=M1;  
      //R1+=M1;
        //M1=0;
        break;
      case 'B':
      R2=M2;  
      //R2+=M2;
        //M2=0;
        break;
      case 'C':
      M1=R3;  
      //M1+=R3;
        //R3=0;
        break;
      case 'D':
      M2=R3;  
      //M2+=R3;
        //R3=0;
        break;
      case 'E':
        R3=R1+R2;
        break;
      case 'F':
        R3=R1-R2;
        break;
      default:
        break;
      }
    }

    cout<<M1<<','<<M2<<endl;
  }

  return 0;
  

}
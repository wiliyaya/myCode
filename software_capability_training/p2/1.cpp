#include <iostream>
using namespace std;
int main(){
  long long n;
  cin>>n;
  int mi=n/(1760*3*12);
  int yd=(n-mi*1760*3*12)/(3*12);
  int ft=(n-mi*1760*3*12-yd*3*12)/12;
  int in=n-mi*1760*3*12-yd*3*12-ft*12;
  if(mi>0){
    cout<<mi<<" mi ";
  }
  if(yd>0){
    cout<<yd<<" yd ";
  } 
  if(ft>0){
    cout<<ft<<" ft ";
  }
  if(in>0){
    cout<<in<<" in";
  }
  return 0;

}
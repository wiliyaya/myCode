#include <iostream>
#include<iomanip>
using namespace std;
int main(){
  double F;
  cin >> F;
  cout <<fixed<<setprecision(5)<<5*(F-32)/9.0<<endl;
  return 0;
}
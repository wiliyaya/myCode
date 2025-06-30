#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  int a,b;
  cin>>a>>b;
  double c=a*1.0/3+b*1.0/4;
  cout<<fixed<<setprecision(2)<<c<<endl;
  return 0;
}
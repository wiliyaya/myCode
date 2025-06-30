#include<iostream>
#include <iomanip>

using namespace std;

int main(){
  long n;
  cin>>n;
  double money;
  cin>>money;
  cout<<setfill('0')<<setw(8)<<n<<endl;
  cout<<fixed<<setprecision(2)<<money<<endl;
  return 0;
}
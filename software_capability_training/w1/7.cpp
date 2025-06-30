#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  double x1,y1,x2,y2,x3,y3;
  while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
    if(x1==0 && y1==0 && x2==0 && y2==0 && x3==0 && y3==0){
      break;
    }
    double a1=(x2-x1);
    double a2=y2-y1;
    double b1=x3-x1;
    double b2=y3-y1;
    double area=(a1*b2-a2*b1)/2.0;
    if(abs(area)<1e-10){
      area=0.0;
    }
    else if(area<0){area=-area;}
    cout<<fixed<<setprecision(6)<<area<<endl;

  }
  return 0;
}

#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<double>> operation(n+1,vector<double>(2,0));
  for(int i=1;i<=n;i++){
    cin>>operation[i][0]>>operation[i][1];
  }
  for(int j=0;j<m;j++){
    int l,r;
    cin>>l>>r;
    double x,y;
    cin>>x>>y;
    for(int k=l;k<=r;k++){
      if(operation[k][0]==1){
        x=x*operation[k][1];
        y=y*operation[k][1];
      }
      else {
        double newX=x*cos(operation[k][1])-y*sin(operation[k][1]);
        double newY=x*sin(operation[k][1])+y*cos(operation[k][1]);
        x=newX;
        y=newY;
      }
    }
    // cout<<fixed<<setprecision(3);
    // cout<<x<<' '<<y<<endl;
    x=round(x*1000.0)/1000.0;
    y=round(y*1000.0)/1000.0;
    cout<<x<<' '<<y<<endl;
  }
  return 0;
}


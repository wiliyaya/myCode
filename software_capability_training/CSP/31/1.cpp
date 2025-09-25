#include <iostream>

using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int dx=0,dy=0;
  for(int i=0;i<n;i++){
    int changeX,changeY;
    cin>>changeX>>changeY;
    dx+=changeX;
    dy+=changeY;
  }
  for(int j=0;j<m;j++){
    int x,y;
    cin>>x>>y;
    cout<<x+dx<<' '<<y+dy<<endl;
  }
  return 0;
}
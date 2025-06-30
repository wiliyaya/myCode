#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  int h1,m1,s1,h2,m2,s2;
  scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
  int t1=h1*3600+m1*60+s1;
  int t2=h2*3600+m2*60+s2;
  int t=t2-t1;
  int h=t/3600;
  int m=(t%3600)/60;
  int s=t%60;
  cout<<h<<":"<<setfill('0')<<setw(2)<<m<<":"
  <<setfill('0')<<setw(2)<<s<<endl;
  return 0;

}
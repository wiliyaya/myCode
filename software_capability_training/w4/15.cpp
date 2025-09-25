#include <iostream>
#include <vector>
#include <string>
using namespace std;

//判断是否为闰年
bool isleap(int year){
  return (year%4==0 && year%100!=0) || year%400==0;
}

vector<string> week={
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};

vector<int> monthDay={
  0,31,28,31,30,31,30,31,31,30,31,30,31
};

int main(){
  int n;
  while(cin>>n){
    if(n==-1) break;
    //n--;//因为2000-01-01是第0天
    //先计算星期
    int weekday=(6+n)%7;

    //计算年份
    int curYear=2000;
    //这种写法是错误的，如果n=366就会死循环
    while(n>365){
      if(isleap(curYear)){
        if(n>366){
          n-=366;
          curYear++;
        }
      }
      else {
        n-=365;
        curYear++;
      }
    }
    //计算月份
    int curMonth=1;
    while(n>=monthDay[curMonth]){
      if(curMonth==2 && isleap(curYear)){
        if(n>29){
          n-=29;
          curMonth++;
        }
      }
      else {
        n-=monthDay[curMonth];
        curMonth++;
      }
    }
    cout<<curYear<<'-';
    if(curMonth<10) cout<<'0';
    cout<<curMonth<<'-';
    if(n<10) cout<<'0';
    cout<<n<<' ';
    cout<<week[weekday]<<endl;
    
  }
  return 0;
}
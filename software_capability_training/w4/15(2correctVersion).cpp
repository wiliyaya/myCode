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
  while(cin>>n && n!=-1){
    int weekday=(6+n)%7;
    int curYear=2000;
    //找年份
    while(true){
      int daysInYear=isleap(curYear)? 366:365;
      if(n>=daysInYear){
        n-=daysInYear;
        curYear++;
      }
      else break;
    }
    //找月份
    int curMonth=1;
    while(true){
      int daysInMonth=monthDay[curMonth];
      if(curMonth==2 && isleap(curYear)){
        daysInMonth=29;
      }
      if(n>=daysInMonth){
        n-=daysInMonth;
        curMonth++;
      }
      else break;
    }

    //注意，最终日期是剩余天数+1
    int curDay=n+1;
    cout<<curYear<<'-';
    if(curMonth<10) cout<<'0';
    cout<<curMonth<<'-';
    if(curDay<10) cout<<'0';
    cout<<curDay<<' ';
    cout<<week[weekday]<<endl;

  }
  return 0;
}

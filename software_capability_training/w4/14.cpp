#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Student{
  string id;
  int month;
  int day;
};

int main(){
  int n;
  cin>>n;
  if(n<=0) return 0;
  //n小于200，所以这题用暴力是可以的
  vector<Student> student(n);
  for(int i=0;i<n;i++){
    cin>>student[i].id>>student[i].month>>student[i].day;
  }
  stable_sort(student.begin(),student.end(),[](const Student& a,const Student& b){
    if(a.month!=b.month){
      return a.month<b.month;
    }
    return a.day<b.day;
  });
  cout<<student[0].month<<' '<<student[0].day<<' '<<student[0].id;
  for(int i=1;i<n;i++){
    if(student[i].month==student[i-1].month &&student[i].day==student[i-1].day){
      cout<<' '<<student[i].id;
    }
    else {
      cout<<endl;
      cout<<student[i].month<<' '<<student[i].day<<' '<<student[i].id;
    }
  }
  return 0;
}
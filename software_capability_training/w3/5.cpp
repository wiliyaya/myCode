#include <iostream>
#include <string>
using namespace std;
struct Student{
  string name;
  string id;
  int score;
};

int main(){
  int n;
  cin>>n;
  Student maxStudent={"","",-1};
  Student minStudent={"","",101};
  for(int i=0;i<n;i++){
    Student curStudent;
    cin>>curStudent.name>>curStudent.id>>curStudent.score;
    if(curStudent.score>maxStudent.score){
      maxStudent=curStudent;
    }
    if(curStudent.score<minStudent.score){
      minStudent=curStudent;
    }
  }
  cout<<maxStudent.name<<" "<<maxStudent.id<<endl;
  cout<<minStudent.name<<" "<<minStudent.id<<endl;
  return 0;
}
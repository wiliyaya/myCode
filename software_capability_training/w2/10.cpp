#include<iostream>
#include<iomanip>
#include <vector>
using namespace std;


int main(){
  int n;
  cin>>n;
  vector<int> credits(n);
  vector<int> scores(n);
  double sumOfCredits=0;
  double sumOfGPA=0;
  for(int i=0;i<n;i++){
    cin>>credits[i];
    sumOfCredits+=credits[i];
  }

  double curGPA=0;
  for(int i=0;i<n;i++){
    cin>>scores[i];
    if(scores[i]>=90){
      curGPA=4.0;
    }
    else if(scores[i]>=85){
      curGPA=3.7;
    }
    else if(scores[i]>=82){
      curGPA=3.3;
    }
    else if(scores[i]>=78){
      curGPA=3.0;
    }
    else if(scores[i]>=75){
      curGPA=2.7;
    }
    else if(scores[i]>=72){
      curGPA=2.3;
    }
    else if(scores[i]>=68){
      curGPA=2.0;
    }
    else if(scores[i]>=64){
      curGPA=1.5;
    }
    else if(scores[i]>=60){
      curGPA=1.0;
    }
    else {
      curGPA=0.0;
    }

    sumOfGPA+=curGPA*credits[i];
  }

  cout<<fixed<<setprecision(2)<<sumOfGPA/sumOfCredits<<endl;

  return 0;
}


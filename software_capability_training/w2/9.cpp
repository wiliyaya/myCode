#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//难绷，要输出的是获胜次数最多的手势而不是出现最多的！

struct Person {
  int win=0;
  int lose=0;
  int draw=0;//平局
  unordered_map<char,int> choice={{'B',0}, {'C',0}, {'J',0}}; // 记录每种选择的次数
};

char getMaxChoice(const unordered_map<char,int>& choice){
  int maxCnt=0;
  char res='B';
  for(char c:{'B','C','J'}){
    if(choice.at(c)>maxCnt){
      maxCnt=choice.at(c);
      res=c;
    }else if(choice.at(c)==maxCnt){
      if(c<res){
        res=c;
      }
    }
  }
  return res;
}
 
int main(){
  int N;cin>>N;
  Person jia,yi;
  for(int i=0;i<N;i++){
    char J_choice,Y_choice;
    cin>>J_choice>>Y_choice;

    // jia.choice[J_choice]++;
    // yi.choice[Y_choice]++;

    if(J_choice==Y_choice){
      jia.draw++;
      yi.draw++;
    }
    else if((J_choice=='B' && Y_choice=='C') || (J_choice=='C' && Y_choice=='J') || (J_choice=='J' && Y_choice=='B')){
      jia.win++;
      jia.choice[J_choice]++;
      yi.lose++;
    }
    else {
      jia.lose++;
      yi.choice[Y_choice]++;
      yi.win++;
    }
    
  }

  cout <<jia.win<<" "<<jia.draw<<" "<<jia.lose<<endl;
  cout <<yi.win<<" "<<yi.draw<<" "<<yi.lose<<endl;
  cout<<getMaxChoice(jia.choice)<<" "<<getMaxChoice(yi.choice)<<endl;
  return 0;
}


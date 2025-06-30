#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TeamData{//最好初始化结构体的成员
  int win;
  // int lose;
  int score;
};

bool cmp(const pair<string,TeamData>& a,const pair<string,TeamData>& b ){
  if(a.second.score != b.second.score){
    return a.second.score>b.second.score;
  }
  else return a.second.win>b.second.win;
}


int main(){
  int T;
  cin>>T;
  while(T--){
    unordered_map<string,TeamData> teams;
    string vs;
    for(int i=0;i<12;i++){
      string team1,team2;
      int score1,score2;
      cin>>team1>>score1>>vs>>score2>>team2;
    
      if(score1>score2){
        teams[team1].score+=3;
        teams[team1].win+=score1;
        teams[team2].win+=score2-score1;
      }
      else if(score1<score2){
        teams[team2].score+=3;
         teams[team2].win+=score2;
        teams[team1].win+=score1-score2;
      }
      else{
        teams[team1].score+=1;
        teams[team2].score+=1;
      }
    }

    vector<pair<string,TeamData>> teamsVec(teams.begin(), teams.end());

    sort(teamsVec.begin(),teamsVec.end(),cmp);
    
    cout<<teamsVec[0].first<<" "<<teamsVec[1].first<<endl;
  }
  return 0;
}



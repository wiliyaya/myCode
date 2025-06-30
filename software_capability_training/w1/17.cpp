#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct TeamData {
  int score=0;
  int goal=0;
  int win=0;
};

bool cmp(const pair<string, TeamData>& a, const pair<string, TeamData>& b) {
  if (a.second.score != b.second.score) {
    return a.second.score > b.second.score;
  } else if (a.second.goal != b.second.goal) {
    return a.second.goal > b.second.goal;
  } else 
  return a.second.win > b.second.win;
}

bool cmp2(const pair<string, TeamData>& a, const pair<string, TeamData>& b) {
  return a.first<b.first;
}

void print( vector<pair<string,TeamData>>& vec,int n){
  int i=1;
  for(const auto& team : vec){
    if(i>n/2) break;
    cout<<team.first<<endl;
    i++;
  }

}

int main(){
  int n;
  cin>>n;
  unordered_map<string, TeamData> teams; // 使用unordered_map存储每个队伍的数据
  for(int i=0;i<n;i++){
    string teamName;
    cin>>teamName;
    teams[teamName];
  }
  for(int i=0;i<n*(n-1)/2;i++){
    string team1, team2;
    int score1, score2;
    // scanf("%d-%d %d:%d",&team1,&team2,&score1,&score2);

    string s;
    cin>>s;
    size_t pos=s.find('-');
    team1=s.substr(0,pos);
    team2=s.substr(pos+1);

    scanf("%d:%d",&score1,&score2);

    teams[team1].win+=score1;
    teams[team1].goal+=score1-score2;

    teams[team2].win+=score2;
    teams[team2].goal+=score2-score1;

    if(score1>score2){
        teams[team1].score+=3;
      }
      else if(score1<score2){
        teams[team2].score+=3;
      }
      else{
        teams[team1].score+=1;
        teams[team2].score+=1;
      }
  }

  vector<pair<string,TeamData>> teamsVec(teams.begin(),teams.end());
  
  sort(teamsVec.begin(), teamsVec.end(),cmp);
  sort(teamsVec.begin(), teamsVec.begin()+n/2,cmp2);
  // vector<pair<string,TeamData>> temp(teamsVec.begin(),teamsVec.begin()+n/2);
  // sort(temp.begin(),temp.end(),cmp2);
  print(teamsVec,n);
  return 0;


}



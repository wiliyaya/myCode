#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> teamA;
vector<char> teamB;
int scoreA=0,scoreB=0;
void Turn(string str,int i){
      if(i%2==0){
        if(str.find("no good")!=string ::npos){
          teamA.push_back('X');
        }
        else{
          teamA.push_back('O');
          scoreA++;
        }
      }
      else{
        if(str.find("no good")!=string ::npos){
          teamB.push_back('X');
        }
        else{
          teamB.push_back('O');
          scoreB++;
        }
      }

}

int main(){
  int N;
  while(cin>>N&& N!=0){
    cin.ignore();
    teamA.clear();
    teamB.clear();
    scoreA=0,scoreB=0;
    for(int i=0;i<N;i++){
      string str;
      getline(cin,str);
      Turn(str,i);
    }
    int size=max(teamA.size(),teamB.size());
    for(int i=1;i<=size;i++){
      cout<<i<<" ";
    }
    cout<<"Score"<<endl;
    for(int i=0;i<teamA.size();i++){
      cout<<teamA[i]<<" ";
    }
    cout<<scoreA<<endl;
    for(int i=0;i<teamB.size();i++){
      cout<<teamB[i]<<" ";
    }
    if(teamB.size()<teamA.size()){
      cout<<"- "<<scoreB<<endl;
    }
    else{
      cout<<scoreB<<endl;
    }
}
return 0;
}

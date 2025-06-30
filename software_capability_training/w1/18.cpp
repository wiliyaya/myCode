#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct personData{
  int score=0;
  vector<int> rank;
};

bool cmp1(const pair<string,personData>& a,const pair<string,personData>& b){
  if(a.second.score!=b.second.score){
    return a.second.score>b.second.score;
  }
  else {
    for(int i=1;i<a.second.rank.size();i++){
      if(a.second.rank[i]!=b.second.rank[i]){
        return a.second.rank[i]>b.second.rank[i];
      }
    }
  }
  
}
  
bool cmp2(const pair<string,personData>& a,const pair<string,personData>& b){
  if(a.second.rank[1]!=b.second.rank[1]){
    return a.second.rank[1]>b.second.rank[1];
  }
  else if(a.second.score!=b.second.score){
    return a.second.score>b.second.score;
  }
  else {
    for(int i=2;i<a.second.rank.size();i++){
      if(a.second.rank[i]!=b.second.rank[i]){
        return a.second.rank[i]>b.second.rank[i];
      }
    }
  }
}

int main(){
  int t;
  cin>>t;
  unordered_map<string,personData> persons;
  while(t--){
    int n;
    cin>>n;
    for(int i=1;i<n+1;i++){
      string name;
      cin>>name;
      persons[name];
      persons[name].rank.resize(n+1,0);
      switch (i)
      {
      case 1:
        persons[name].score+=25;
        persons[name].rank[i]++;
      break;
      case 2:
        persons[name].score+=18;
         persons[name].rank[i]++;
      break;
      case 3:
        persons[name].score+=15;
         persons[name].rank[i]++;
      break;
      case 4:
        persons[name].score+=12;
         persons[name].rank[i]++;
      break;
      case 5:
        persons[name].score+=10;
         persons[name].rank[i]++;
      break;
      case 6:
        persons[name].score+=8;
         persons[name].rank[i]++;
      break;
      case 7:
        persons[name].score+=6;
         persons[name].rank[i]++;
      break;
      case 8:
        persons[name].score+=4;
         persons[name].rank[i]++;
      break;
      case 9:
        persons[name].score+=2;
         persons[name].rank[i]++;
      break;
      case 10:
        persons[name].score+=1;
         persons[name].rank[i]++;
      break;
      default:
       persons[name].rank[i]++;
        break;
      }
    
    }

  }
    vector<pair<string,personData>> personsVec(persons.begin(),persons.end());
    sort(personsVec.begin(),personsVec.end(),cmp1);
    cout<<personsVec[0].first<<endl;
    
    sort(personsVec.begin(),personsVec.end(),cmp2);
    cout<<personsVec[0].first<<endl;
    
    return 0;
}
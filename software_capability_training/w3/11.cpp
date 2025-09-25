#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool isIn(vector<vector<int>>& vec,int cur,int target){
  for(int i=0;i<vec[cur].size();i++){
    if(vec[cur][i]==target){
      return true;
    }
  }
  return false;
}

int main(){
  vector<vector<int>> vec={
    {1,7,8},
    {0,3,4,7,8,9},
    {8},
    {1,7,8,9},
    {1,8,9},
    {8,9},
    {0,1,3,8,9},
    {0,1,2,3,4,5,6,7,9},
    {1,3,4,5,7,8}
  };
  string str;
  while(getline(cin,str)){
    if(str=="-1"){break;}
    istringstream iss(str);
    string number;
    vector<int> num;
    while(iss>>number){
      num.push_back(stoi(number));
    }

    bool falg=true;
    for(int i=0;i<num.size()-1;i++){
      if(!isIn(vec,num[i],num[i+1])){
        cout<<"NO"<<endl;
        falg=false;
        break;
      }
    }
    if(falg){
      cout<<"YES"<<endl;
    }
  }
  return 0;
}
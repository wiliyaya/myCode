#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
  vector<int> changeNumber(10,0);
  unordered_map<char,string> tran={
    {'0',"(Zero)"},
    {'1',"(One)"},
    {'2',"(Two)"},
    {'3',"(Three)"},
    {'4',"(Four)"},
    {'5',"(Five)"},
    {'6',"(Six)"},
    {'7',"(Seven)"},
    {'8',"(Eight)"},
    {'9',"(Nine)"}
  };
  string str;
  // cin>>str;
  getline(cin,str);
  string result;
  for(char c:str){
    if(c-'0'>=0 && c-'0'<=9){
      changeNumber[c-'0']++;
      result+=tran[c];
    }
    else {
      result+=c;
    }
  }
  cout<<result<<endl;
  for(int i=0;i<=9;i++){
      cout<<changeNumber[i]<<' ';
  }
  return 0;
}
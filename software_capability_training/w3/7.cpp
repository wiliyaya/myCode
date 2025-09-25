#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int main(){
  unordered_map<char,string> tran={
    {'0',"ling"},
    {'1',"yi"},
    {'2',"er"},
    {'3',"san"},
    {'4',"si"},
    {'5',"wu"},
    {'6',"liu"},
    {'7',"qi"},
    {'8',"ba"},
    {'9',"jiu"}
  };
  char c;
  long long sum=0;
  while(cin>>c){
    sum+=c-'0';
  }
  string number=to_string(sum);
  for(char ch:number){
    cout<<tran[ch]<<' ';
  }
  return 0;
}
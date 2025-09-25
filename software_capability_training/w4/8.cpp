#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<char,char> tran={
  {'A','F'},
  {'B','G'},
  {'C','H'},
  {'D','I'},
  {'E','J'},
  {'F','K'},
  {'G','L'},
  {'H','M'},
  {'I','N'},
  {'J','O'},
  {'K','P'},
  {'L','Q'},
  {'M','R'},
  {'N','S'},
  {'O','T'},
  {'P','U'},
  {'Q','V'},
  {'R','W'},
  {'S','X'},
  {'T','Y'},
  {'U','Z'},
  {'V','A'},
  {'W','B'},
  {'X','C'},
  {'Y','D'},
  {'Z','E'}
};

void passwordTrans(string str){
  for(char c:str){
    if(c==' '){
      cout<<' ';
      continue;
    }
    else if(c==','){
      cout<<',';
      continue;
    }

    else {
      cout<<tran[c];
    }
  }
}

int main(){
  string start;
  while(cin>>start){
    if(start=="ENDOFINPUT"){break;}
    string str;
    cin.ignore();
    getline(cin,str);
    passwordTrans(str);
    cout<<endl;
    string end;
    cin>>end;
  }
  return 0;
}
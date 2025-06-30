#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    stack<char> s;
    bool isleagal=true;
    for(char c:str){
      if(c=='<' ||c=='('||c=='['||c=='{'){
        s.push(c);
      }
      else if(c=='>'){
        if(!s.empty()&&s.top()=='<'){
          s.pop();
        }
        else {
          cout<<"No"<<endl;
          isleagal=false;
          break;
        }
      }
      else if(c==')'){
        if(!s.empty()&&s.top()=='('){
          s.pop();
        }
        else {
          cout<<"No"<<endl;
          isleagal=false;
          break;
        }
      }
      else if(c==']'){
        if(!s.empty()&&s.top()=='['){
          s.pop();
        }
        else {
          cout<<"No"<<endl;
          isleagal=false;
          break;
        }
      }
      else if(c=='}'){
        if(!s.empty()&&s.top()=='{'){
          s.pop();
        }
        else {
          cout<<"No"<<endl;
          isleagal=false;
          break;
        }



      }
      
    }
    if(isleagal){
      if(s.empty()){
        cout<<"Yes"<<endl;
      }
      else {
        cout<<"No"<<endl;
      }
    }

  }
}
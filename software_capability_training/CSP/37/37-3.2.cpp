#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;
long long mod=1000000007;
int main(){
  int n;
  cin>>n;
  unordered_map<string,long long> value; 
  for(int i=0;i<n;i++){
    int number ;
    cin>>number;
    if(number==1){
      string var;
      string expr;
      cin>>var;
      value[var]=0;
      cin.ignore();
      getline(cin,expr);

      istringstream iss(expr);
      string word;
      while(iss>>word){
        if(word[0]=='$'){
          value[var]=(value[var]+value[word.substr(1)])%mod;
        }
        else {
          value[var]=value[var]+word.size();
        }
      }









      // stringstream result_builder;
      // while(iss>>word){
      //   if(word[0]=='$'){

      //     result_builder << value[word.substr(1)];
      //   }
      //   else {
      //     result_builder<<word;
      //   }

      // }
      // value[var]=result_builder.str();
      // if(expr[0]=='$'){
      //   value[var]=value[expr.substr(1)];
      //   continue;
      // }
      // value[var]=expr;
    }
    
    if(number==2){

    }
    if(number==3){
      string var;
      cin>>var;
      // long long size=value[var].size();
      // cout<<size%mod<<endl;
      cout<<value[var]%mod<<endl;
    }
  }
  return 0;

}
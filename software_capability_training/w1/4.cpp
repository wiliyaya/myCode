#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main(){
  int n;
  cin>>n;
  cin.ignore();
  while(n--){
    string line;
    getline(cin,line);
    istringstream iss(line);
    string word;
    while(iss>>word){
      reverse(word.begin(),word.end());
      cout<<word<<" ";
    }
    cout<<endl;
  }
  
  return 0;

}
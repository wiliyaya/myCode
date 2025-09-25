#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main(){
  vector<int> w={7,9,10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  map<int,char> check={
    {0,'1'},
    {1,'0'},
    {2,'X'},
    {3,'9'},
    {4,'8'},
    {5,'7'},
    {6,'6'},
    {7,'5'},
    {8,'4'},
    {9,'3'},
    {10,'2'}
  };
  string id;
  while(cin>>id){
    if(id=="-1") break;
    int sum=0;
    for(int i=0;i<17;i++){
      sum+=(id[i]-'0')*w[i];
    }
    int Y=sum%11;
    if(id[17]==check[Y]){
      cout<<'1'<<endl;
    }
    else {
      cout<<'0'<<endl;
    }

  }
  return 0;
}
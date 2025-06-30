#include <iostream>
#include<unordered_map>
#include <string>

using namespace std;

int main(){

unordered_map<char,int> ctoi={
  {'a',10},
  {'b',11},
  {'c',12},
  {'d',13},
  {'e',14},
  {'f',15},
  {'0',0},
  {'1',1},
  {'2',2},
  {'3',3},
  {'4',4},
  {'5',5},
  {'6',6},
  {'7',7},
  {'8',8},
  {'9',9}
};
unordered_map<int,char> itoc={
  {10,'a'},
  {11,'b'},
  {12,'c'},
  {13,'d'},
  {14,'e'},
  {15,'f'},
  {0,'0'},
  {1,'1'},
  {2,'2'},
  {3,'3'},
  {4,'4'},
  {5,'5'},
  {6,'6'},
  {7,'7'},
  {8,'8'},
  {9,'9'}
};
  int t;
  cin >> t;
  while(t--){
    int B;
    string N;
    cin >> B >> N;
    int num=0;
    for(char c:N){
      num+=ctoi[c];
    }
    for(int i=0;i<B;i++){
    
      if((num+i)%(B-1)==0){
        if(i==B-1){
          cout<<0<<endl;
          break;
        }
        cout<<itoc[i]<<endl;
        break;
      }
    }
  }

  return 0;
}
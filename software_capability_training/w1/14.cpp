// 7进制数？
// 通过星期写出对应的7进制数，然后再转为十进制数，看看在不在范围内
#include <iostream>
#include <string>
#include<map>
#include <vector>
using namespace std;
int main(){
  int T;
  cin>>T;

  map<string,int> week={
    {"monday",1},
    {"tuesday",2},
    {"wednesday",3},
    {"thursday",4},
    {"friday",5},
    {"saturday",6},
    {"sunday",0}
  };

  while(T--){
    string S,E;
    cin >> S >> E;
    int L,R;
    cin >> L >> R;

    vector<int> dayform;
    int gap=(week[E]-week[S]+1+7)%7;

    for(int i=0;i<15;i++){
      if(gap+i*7>=L && gap+i*7<=R){
        dayform.push_back(gap+i*7);
      }
      else if(gap+i*7>R){
        break;
      }
    }

    if(dayform.empty()){
      cout<<"impossible"<<endl;
    }
    else {
      if(dayform.size()==1){
        cout<<dayform[0]<<endl;
      }
      else cout<<"many"<<endl;
    }
  }
  return 0;
}

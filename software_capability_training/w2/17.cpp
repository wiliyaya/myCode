#include <iostream>
#include <string>
#include <vector>
using namespace std;

//递归溢出的话，可以用迭代器代替递归
long long dotNumber(int i,long long A,long long B,long long C){
  if(i==0){
    return (A*C+B)%6+1;
  } 
  else return (A*dotNumber(i-1,A,B,C)+B)%6+1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  long long A,B,C;
  while(cin>>N>>A>>B>>C){
    vector<int> toWhere(N);
    //初始化toWhere数组
    for(int i=0;i<N;i++){
      string str;
      cin>>str;
      if(str=="N"){
        toWhere[i]=i;//等于自己本身代表走到这个格子的位置不变
      }
      else {
        toWhere[i]=stoi(str.substr(1));
      }
    }

    int Lele_pos=0,Yueyue_pos=0;//lele and yueyue's position
    int turns=0;//轮次
    while(true){
      if(turns%2==0){//lele's turn
        Lele_pos+=dotNumber(turns,A,B,C);
        if(Lele_pos==N-1){
          cout<<"Lele"<<endl;
          break;
        }
        //超出范围要往回走
        if(Lele_pos>N-1){
          Lele_pos=N-1-(Lele_pos-N+1);
        }

        while(toWhere[Lele_pos]!=Lele_pos){
          Lele_pos=toWhere[Lele_pos];
        }
        if(Lele_pos==Yueyue_pos){
          Yueyue_pos=0;
        }

      }
      else{//yueyue's turn 
        Yueyue_pos+=dotNumber(turns,A,B,C);
        if(Yueyue_pos==N-1){
          cout<<"Yueyue"<<endl;
          break;
        }
        if(Yueyue_pos>N-1){
          Yueyue_pos=N-1-(Yueyue_pos-N+1);
        }
        while(toWhere[Yueyue_pos]!=Yueyue_pos){
          Yueyue_pos=toWhere[Yueyue_pos];
        }
        if(Yueyue_pos==Lele_pos){
          Lele_pos=0;
        }

      }
      turns++;
    }
  }
  return 0;
}
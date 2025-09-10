#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct warehouse{
  int id;
  vector<int> code;
  int superior_id=1001;
};

int main(){
  int n,m;//n个仓库，m维向量
  cin>>n>>m;
  vector<warehouse> warehouses(n);
  for(int i=0;i<n;i++){
    warehouses[i].id=i+1;
    warehouses[i].code.resize(m);
    for(int j=0;j<m;j++){
      cin>>warehouses[i].code[j];
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
        bool is_superior=true;
        for(int k=0;k<m;k++){
          if(warehouses[i].code[k]>=warehouses[j].code[k]){
            is_superior=false;
            break;
          }
        }
        if(is_superior){
          warehouses[i].superior_id=min(warehouses[i].superior_id,warehouses[j].id);
        }

      }
    }
    if(warehouses[i].superior_id==1001){
      warehouses[i].superior_id=0;
    }
  }
  for(int i=0;i<n;i++){
    cout<<warehouses[i].superior_id<<endl;
  }
  return 0;

}
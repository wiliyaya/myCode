#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

//计算无序度
int cac(string& str){
  int cnt=0;
  for(int i=0;i<str.size();i++){
    for(int j=i+1;j<str.size();j++){
      if(str[i]>str[j]){
        cnt++;
      }
    }
  }

  return cnt;

}

struct Node{
  string str;
  int disorder;
};

bool cmp(const Node& a,const Node& b){
    return a.disorder<b.disorder;
}

int main(){
  int n,m;
  cin>>n>>m;
  Node arr[m];
  for(int i=0;i<m;i++){
    cin>>arr[i].str;
    arr[i].disorder=cac(arr[i].str);
  }
  //排序
  stable_sort(arr,arr+m,cmp);
  
  for(int i=0;i<m;i++){
    cout<<arr[i].str<<endl;
  }

}
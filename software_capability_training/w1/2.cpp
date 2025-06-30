#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> &arr){
  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[i].size();j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}


int main(){
  int n,m;
  cin>>n>>m;

  vector<vector<int>> arr(n,vector<int>(m));
  vector<int> onlight(m,0);
  //先进行全局的统计
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char c;
      cin>>c;
      arr[i][j]= c-'0'; // 将字符转换为数字
      onlight[j]+= arr[i][j];
    }
  }

  // print(arr);


  //再枚举每个开关，假设不按它
  bool flag=true;
  for(int i=0;i<n;i++){
    flag=true;
    for(int j=0;j<m;j++){
      if(onlight[j]-arr[i][j] ==0){
        flag=false;
        break;
      }
    }
    if(flag){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  
  cout<<"NO"<<endl;
  return 0;


}
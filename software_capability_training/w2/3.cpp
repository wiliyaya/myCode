#include <iostream>
#include <cmath>
#include <vector>

struct Num {
  int x=0;
  int abs=0;
};

using namespace std;
int main(){
  int n;
  cin>>n;
  vector<Num> nums(n);
  int x=0;
  cin>>x;//输入的第一个数
  nums[0].x=x;
  int Max=x,Min=x;//用第一个数初始化最大和最小值
  for(int i=1;i<n;i++){
    cin>>x;
    nums[i].x=x;
    if(x>Max){
      Max=x;
    }
    if(x<Min){
      Min=x;
    }

  }
  //计算距离差
  x=nums[0].x;
  nums[0].abs= abs(abs(x-Max)-(x-Min));
  int minAbs=nums[0].abs;
  for(int i=1;i<n;i++){
    nums[i].abs= abs(abs(nums[i].x-Max)-(nums[i].x-Min));
    if(nums[i].abs<minAbs){
      minAbs=nums[i].abs;
      x=nums[i].x; // 更新最小值的x
    }
    else if(nums[i].abs==minAbs){
      if(nums[i].x<x){
        x=nums[i].x; // 如果相等，取更小的x
      }
    }
  }

  cout<<x<<endl;
  return 0;



 }
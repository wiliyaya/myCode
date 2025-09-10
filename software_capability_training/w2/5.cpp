#include <iostream>
#include <vector>
using namespace std;

//先计算恰好发第n枚金币的最后一天对应的数
vector<int> getDay;
void initgetDay(){
  for(int i=1;i*(i-1)/2<=10000;i++){//i代表金币数，i*(i-1)/2代表第i枚金币对应的天数
    getDay.push_back(i*(i-1)/2);

  }
}

long getMoney(int n){
  int daymoney;
  long sum=0;
  for(int i=0;i<getDay.size();i++){
    if(getDay[i]==n){
      daymoney= i+1; 
      for(int j=1;j<=daymoney;j++){
        sum+=j*j;
      }
      return sum;
    }
    else if(getDay[i]>n){
      daymoney= i;
      for(int j=1;j<=daymoney;j++){
        sum+=j*j;
      }
      sum+=(n-getDay[i])*(i+1);
      return sum;
    }

  }
}

//n*(n-1)/2
int main(){
  initgetDay();
  // cout<<getDay.size()<<endl;//141

  int n;
  while(cin>>n){
    cout<<n<<" "<<getMoney(n)<<endl;
  }

  return 0;
}
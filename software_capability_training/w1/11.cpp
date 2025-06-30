#include <iostream>
#include <vector>
using namespace std;

int main(){
  while(true){
    int N;
    cin>>N;
    if(N==0) break;
    vector<int> nums(N);
    double sum=0.0;
    for(int i=0;i<N;i++){
      cin>>nums[i];
      sum+=nums[i];
    }

    double average=1.0*sum/N;
    sum=0.0;
    for(int i=0;i<N;i++){
      sum+=(nums[i]-average)*(nums[i]-average);
    }
    int var=sum/N;
    cout <<var<<endl;
  }
  return 0;
}
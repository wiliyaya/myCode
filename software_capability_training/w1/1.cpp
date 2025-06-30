#include <iostream>
#include <vector>
using namespace std;
int main(){
  while(true){
    int n;
    cin>>n;
    if(n==0){
      break;
    }

    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    
    int maxcnt=0,maxValue=arr[0];
    int curcnt=1;
    for(int i=1;i<n;i++){
      if(arr[i]==arr[i-1]){
        curcnt++;
      }
      else 
      { if(curcnt>maxcnt){
        maxcnt=curcnt;
        maxValue=arr[i-1];
      }
      curcnt=1;
    }
    }

    if(curcnt>maxcnt){
      maxcnt=curcnt;
      maxValue=arr[n-1];
    }

    cout<<maxValue<<endl;
  }
  return 0;
}
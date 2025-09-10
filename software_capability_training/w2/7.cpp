#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
  int n;
  int times=0;
  while(cin>>n && n!=0){
    vector<string> names(n);
    int stard=0,end=n-1;
    for(int i=1;i<=n;i++){
      string name;
      cin>>name;
      if(i%2==1){//奇数位
        names[stard++]=name;
      }
      else { //偶数位
        names[end--]=name;
      }
    }

    cout<<"set-"<<++times<<endl;
    for(int i=0;i<n;i++){
      cout<<names[i]<<endl;
    }

  }

  return 0;
}
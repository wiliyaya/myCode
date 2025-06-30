//思路：把给的数字转化为string，然后比较？
#include<iostream>
#include<string>
using namespace std;

string cacStr(string& originNum,int k){
  string res;
  int carry=0;
  for(int i=originNum.size()-1;i>=0;i--){
    int digit=(originNum[i]-'0')*k;
    res=to_string((digit+carry)%10)+res;
    if((digit+carry)>=10){
      carry=(digit+carry)/10;
    }
    else carry=0;
  }

  if(carry>0){
    res=to_string(carry)+res;
  }

  return res;

}


int main(){
  string originNum;
  cin>> originNum;
  string doubleOriginNum= originNum+originNum;
  int n=originNum.size();
  bool isSameFlag = true;
  for(int i=1;i<=n;i++){
    string res=cacStr(originNum,i);
    if(res.size()!=originNum.size() || doubleOriginNum.find(res)==string::npos){
      isSameFlag=false;
      cout<<"No"<<endl;
      break;
    }
  }
  if(isSameFlag){
    cout<<"Yes"<<endl;
  }
  return 0;
}

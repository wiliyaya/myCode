#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string Add(string A,string B){
  string res;
  int carry=0;
  int LA=A.size(),LB=B.size();
  int L=max(LA,LB);
  for(int i=0;i<L;i++){
    //先取出当前位的数字
    int a=(i<LA) ? A[LA-1-i]-'a' :0;
    int b=(i<LB) ? B[LB-1-i]-'a' :0;
    int digit=a+b+carry;
    carry=digit/26; // 计算进位
    res=char(digit%26+'a')+res;
  }
  return res;
}




int main(){
  int N;
  cin>>N;
  while(N--){
    string A,B;
    cin>>A>>B;
    cout<<Add(A,B)<<endl;
  }
  return 0;
}


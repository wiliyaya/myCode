#include <iostream>
#include <string>

using namespace std;
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  string str;
  cin>>str;
  string cur_t;
  // =str.substr(0,1);
  int money=a;
  for(int i=1;i<n;i++){
    string pre_str=str.substr(0,i);//表示在str[i]之前的字符串
    cur_t=string(1,str[i]);//表示当前字符

    while(pre_str.find(cur_t)!=string::npos &&i<n){
      if(pre_str.find(cur_t+string(1,str[i+1]))!=string::npos){
        cur_t=cur_t+string(1,str[i+1]);
        i++;

        // if(b>cur_t.size()*a){
        //   break; // 如果当前字符的长度乘以a大于b，则不再继续累加
        // }
      }
      else{
        money+=b;
        break;
      }
    }

    if(pre_str.find(cur_t)==string::npos){
      money+=a;
    }

  }

  cout<<money<<endl;
  return 0;
}
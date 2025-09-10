#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
 
struct Person{
  //或者用set去重？
  vector<string> tele_numbers; // 电话号码列表 
}; 

//去重
// 判断电话号码a是电话号码b的后缀（也就是说，号码b以a结尾）
bool isSuffix(const string& a,const string& b){
  if(a.length()>b.length()){
    return false; // a比b长，不能是后缀
  }
  return b.substr(b.length()-a.length())==a; // 比较b的后缀是否等于a
}
//排序

int main(){
  int n;
  cin>>n;//n个条目
  for(int i=0;i<n;i++){
    string name;
    int tele_cnt;
    


  }
}




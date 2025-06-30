// 采用字符串的形式输入，再映射成相应的字符串，通过函数“stoi(octal_str, nullptr, 8); // 第三个参数指定基数”实现转化
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
  unordered_map<char,char> MAP={
    {'1','1'},
    {'2','2'},
    {'4','3'},
    {'5','4'},
    {'6','5'},
    {'7','6'},
    {'9','7'},
    {'0','0'}
  };

  int T;
  cin >> T;
  while(T--){

    
    
    string str;
    cin>>str;
    string octal_str;
    for(char c:str){
      octal_str+=MAP[c];
    }
    
    long long mile=stoi(octal_str,nullptr,8);
    
    cout << mile << endl;
  }
    return 0;
    
    


  }